#include <stdio.h>

#include "erl_interface.h"
#include "ei.h"
#include "Rengine.h"
#include "Rinit.h"
#include "eri.h"

typedef unsigned char byte;

int read_cmd(byte *buf);
int write_cmd(byte *buff, int len);


int sum(int x, int y){
  return x+y;
}

void debugloop(){
  printf("start debug mode\n");

  if(setup()){
    printf("fail initR\n");
    return; 
  }  
  printf("R initialized\n");

  char *s;
  s = "1+1";
  int er=0;
  long es,pstr;

  pstr = r_parse(s);

  es = r_eval(pstr,&er);

  PrintValue(L2SEXP(es));


  printf("start main loop\n");
  r_run();

  printf("finish debug mode\n");
}

void mainloop(){
  
  ETERM *tuplep, *resp;
  ETERM *fnp, *argp1,*argp2;
  int resi,b=0;
  long resl;
  byte buf[100];
  ei_x_buff result;

  erl_init(NULL, 0);

  while (read_cmd(buf) > 0) {

    tuplep = erl_decode(buf);
    fnp = erl_element(1, tuplep);    

    //
    if(ei_x_new_with_version(&result) || ei_x_encode_tuple_header(&result,2)){
    }
    
    if (strncmp((char *)ERL_ATOM_PTR(fnp), "sum", 3)==0) {      
      argp1 = erl_element(2, tuplep);
      argp2 = erl_element(3, tuplep);
      resi = sum(ERL_INT_VALUE(argp1),ERL_INT_VALUE(argp2));
      resp = erl_mk_int(resi);
    }else if(strncmp((char *)ERL_ATOM_PTR(fnp), "setup", 4)==0){      
      resi = setup();
      resp = erl_mk_int(resi);
    }else if(strncmp((char *)ERL_ATOM_PTR(fnp), "parse", 5)==0){      
      resl = parse("1+1");
      if(ei_x_encode_atom(&result,"ok") || ei_x_encode_long(&result,resl)){
      }
      b=1;
    }else if(strncmp((char *)ERL_ATOM_PTR(fnp), "eval", 3)==0){
      
    }    
    
    if(b==0){
      erl_encode(resp, buf);
      write_cmd(buf, erl_term_len(resp));
      
      erl_free_compound(tuplep);
      erl_free_term(fnp);
      erl_free_term(argp1);
      erl_free_term(argp2);
      erl_free_term(resp);
    }else{
      write_cmd2(&result);
      ei_x_free(&result);
    }   
  }    

}

int main(int argc, char **argv ){

  if (argc==2 && !strcmp(argv[1],"-d")){
    debugloop();
  }else{
    mainloop();
  }  
  return 0;
}
