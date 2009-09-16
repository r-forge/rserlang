#include "erl_interface.h"
#include "ei.h"
#include "rErlang.h"

//internal func.
int rE_init(){
  printf("erl_init\n");
  
  erl_init(NULL,0);

  return 1;
}

//
int rE_connect(){  
  rE_init();
  
  return 1;
}



