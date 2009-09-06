#include <stdio.h>

#include "erl_interface.h"
#include "ei.h"
#include "Rengine.h"
#include "Rinit.h"
#include "eri.h"

#define BUF_SIZE 128 

typedef unsigned char byte;

int read_cmd(byte *buf);
int write_cmd(ei_x_buff *buff);


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

  printf("%d\n",L2SEXP(es));
  PrintValue(L2SEXP(es));


  printf("start main loop\n");
  r_run();

  printf("finish debug mode\n");
}

int mainloop(){
    
  byte* buf;
  int size = BUF_SIZE;
  char command[MAXATOMLEN];
  char exp[MAXATOMLEN];
  long pstr;
  int resi,index, version, arity;
  int x,y;  
  long resl;  
  ei_x_buff result;


  if ((buf = (byte *) malloc(size)) == NULL) return -1;
    
  while (read_cmd(buf) > 0) {
    
    index = 0;
    if (ei_decode_version(buf, &index, &version)) return 1;
    if (ei_decode_tuple_header(buf, &index, &arity)) return 2;    
    if (ei_decode_atom(buf, &index, command)) return 4;
    
      
    //
    if(ei_x_new_with_version(&result) || ei_x_encode_tuple_header(&result,2)){
    }
    
    if (strncmp(command, "sum", 3)==0) {      
      fprintf(stderr,"%s\n",command);
      if (ei_decode_long(buf, &index, &x)) return 6;
      if (ei_decode_long(buf, &index, &y)) return 7;

      resi = sum(x,y);
      if(ei_x_encode_atom(&result,"ok") || ei_x_encode_long(&result,resi)){
      }
    }else if(strncmp(command, "setup", 4)==0){      
      resi = setup();
      if(ei_x_encode_atom(&result,"ok") || ei_x_encode_long(&result,resi)){
      }           
    }else if(strncmp(command, "parse", 5)==0){
      if (ei_decode_string(buf, &index, &exp)) return 6;      
      resl = parse(exp);
      if(ei_x_encode_atom(&result,"ok") || ei_x_encode_long(&result,resl)){
      }     
    }else if(strncmp(command, "eval", 3)==0){
      if (ei_decode_long(buf, &index, &pstr)) return 6;
      resl = erl_eval(pstr);
      fprintf(stderr,"result=%d\n",resl);
      if(ei_x_encode_atom(&result,"ok") || ei_x_encode_long(&result,resl)){
      }      
    }
    write_cmd(&result);
    ei_x_free(&result);
  }
  return 0;

}

int main(int argc, char **argv ){

  if (argc==2 && !strcmp(argv[1],"-d")){
    debugloop();
  }else{
    mainloop();
  }  
  return 0;
}
