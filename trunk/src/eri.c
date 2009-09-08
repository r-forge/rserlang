#include <stdio.h>

#include "eri.h"
#include "Rengine.h"


int setup(){  
  int res =  r_setup();
  return res;
}

long parse(const char *s){ 
  return r_parse(s);
}

long erl_eval(long exp){
  long e;  
  int er=0;
 
  e = r_eval(exp,&er);  

  return e;
}

int convert(long exp, ei_x_buff *result){

  SEXP es;
  double *v;
  int type;

  es = L2SEXP(exp);
  type = TYPEOF(es);
  fprintf(stderr,"TYPEOF:%d\n",type);
  fprintf(stderr,"LENGTH:%d\n",LENGTH(es));  

  if(type == REALSXP){
    v = REAL(es);
    fprintf(stderr,"REAL:%f\n", *v);
  }else{
    
  }

  if(ei_x_encode_atom(result,"ok") || ei_x_encode_long(result,exp) || ei_x_encode_atom(result,"tmp")){
  } 

  return 0;
}
