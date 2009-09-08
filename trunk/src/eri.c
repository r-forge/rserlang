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
    unsigned int len = LENGTH(es);
    if(len > 0){   
      v = REAL(es);
      int i = 0;      
      while(i < len){
	fprintf(stderr,"REAL:%f\n", *v+i);      
	i++;
      }
    }    
  }else{
    
  }

  if(ei_x_encode_atom(result,"ok") || ei_x_encode_atom(result,"REALSXP") || ei_x_encode_long(result,exp)){
  } 

  return 0;
}
