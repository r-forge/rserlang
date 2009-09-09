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
  int type, i;
  double *vd;
  int *vi;  

  es = L2SEXP(exp);
  type = TYPEOF(es);
  unsigned int len = LENGTH(es);
  fprintf(stderr,"TYPEOF:%d\n",type);
  fprintf(stderr,"LENGTH:%d\n",len);  

  if(type == REALSXP){    
    if(len > 0){   
      vd = REAL(es);
      i = 0;      
      while(i < len){
	fprintf(stderr,"REAL:%f\n", *(vd+i));
	i++;
      }
    }    
    if(ei_x_encode_atom(result,"ok") || ei_x_encode_atom(result,"REALSXP") || ei_x_encode_long(result,exp)){
    } 
  }else if(type == INTSXP){
    if(len > 0){
      vi = INTEGER(es);
      i = 0;      
      while(i < len){	
	fprintf(stderr,"INTEGER:%d\n", *(vi+i));		
	i++;
      }
    }
    if(ei_x_encode_atom(result,"ok") || ei_x_encode_atom(result,"INTSXP") || ei_x_encode_long(result,exp)){
    } 
  }else{
    if(ei_x_encode_atom(result,"ok") || ei_x_encode_atom(result,"OTHER") || ei_x_encode_atom(result,"OTHER")){
    } 
  }
  

  return 0;
}
