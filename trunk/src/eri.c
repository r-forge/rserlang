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
  SEXP es;
  int er=0;
  e = r_eval(exp,&er);
  es = L2SEXP(e);
  fprintf(stderr,"TYPEOF:%d\n",TYPEOF(es));
  fprintf(stderr,"LENGTH:%d\n",LENGTH(es));
  
  return e;
}
