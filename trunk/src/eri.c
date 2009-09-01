#include <stdio.h>

#include "Rengine.h"


int setup(){  
  int res =  r_setup();
  return res;
}

long parse(const char *s){ 
  return r_parse(s);
}

long erl_eval(long exp){
  int er=0;
  return r_eval(exp,&er);
}
