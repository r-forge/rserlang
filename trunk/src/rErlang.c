#include "erl_interface.h"
#include "ei.h"
#include "rErlang.h"

int rE_init(){  
  erl_init(NULL,0);  
  return 1;
}

int rE_connect(){  
  rE_init();

  int identification_number = 99;
  int creation=1;
  char *cookie="rerlang"; 
  erl_connect_init(identification_number, cookie, creation);

  int sockfd;
  char *nodename="node01@localhost"; 
  if ((sockfd = erl_connect(nodename)) < 0){
    erl_err_quit("ERROR: erl_connect failed");   
    return 0;
  }
  return 1;
}
