#include "erl_interface.h"
#include "ei.h"
#include "rErlang.h"


int fd;

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

  fd = sockfd;

  return 1;
}

void rE_test(int num){

  ETERM *reply,*ep;

  ep = erl_format("[~i]", num);
  reply = erl_rpc(fd, "rErlang", "test", ep);
  
  printf("%d\n",ERL_INT_VALUE(reply));  
    
  erl_free_term(ep);
  erl_free_term(reply);  

  printf("test end\n");

}

