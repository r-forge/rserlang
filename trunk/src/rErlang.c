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
  erl_connect_init(identification_number, COOKIE, creation);
  
  if ((fd = erl_connect(NODE_NAME)) >= 0){    
    return 1;    
  }else {
    /* (failure) */
    switch (fd) {
    case ERL_NO_DAEMON:
      erl_err_quit("<ERROR> No epmd running!");
      break;
    case ERL_CONNECT_FAIL:
      erl_err_quit("<ERROR> Connect failed!");
      break;
    case ERL_NO_PORT:
      erl_err_quit("<ERROR> Node is not running!");
      break;
    case ERL_TIMEOUT:
      erl_err_quit("<ERROR> Connect timed out!");
      break;
    default:
      erl_err_quit("<ERROR> Error during connect! (%d)",fd);
      break;
    }
    return 0;
  }  
}

void rE_test(int num){

  ETERM *reply,*ep;

  ep = erl_format("[~i]", num);
  reply = erl_rpc(fd, "rErlang", "test", ep);
  
  erl_print_term(stdout,reply);
    
  erl_free_term(ep);
  erl_free_term(reply);  

  printf("test end\n");

}

void rE_eval(char *buf){

}
