#include "rErlang.h"

SEXP add(SEXP a, SEXP b){
  int i, n;
  n = length(a);
  for(i=0; i < n; i++){
    REAL(a)[i] += REAL(b)[i];
  }
  return (a);
}

int  rE_init(){  
  erl_init(NULL,0);  
  return 1;
}

SEXP rE_connect(SEXP a){  
  int init;
  init =  rE_init();

  int identification_number = 99;
  int creation=1;  
  erl_connect_init(identification_number, COOKIE, creation);
  
  if ((fd = erl_connect(NODE_NAME)) >= 0){    
    return a;    
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
    return a;
  }  
}

SEXP rE_test(int num){

  ETERM *reply,*ep;
  SEXP result;

  ep = erl_format("[~i]", num);
  reply = erl_rpc(fd, "rErlang", "test", ep);
  
  //erl_print_term(stdout,reply);
  result = ETERM2SEXP(reply);
    
  erl_free_term(ep);
  erl_free_term(reply);  

  return result;
}

SEXP rE_eval(SEXP str){

  ETERM *reply,*ep;
  SEXP result;
  int type, i;  
  
  type = TYPEOF(str);
  unsigned int len = LENGTH(str);
  if(type == STRSXP){    
    char *buf;
    buf = CHAR(STRING_ELT(str,0));   
    ep = erl_format("[~s]", buf);
    reply = erl_rpc(fd, "rErlang", "eval", ep);
    //erl_print_term(stdout,reply);
    result = ETERM2SEXP(reply);  
    
  }else{
    result = NULL;
  }  
    
  erl_free_term(ep);
  erl_free_term(reply);

  return result;
  
}

SEXP ETERM2SEXP(ETERM *eterm){

  int i;
  SEXP result;
  
  PROTECT(result = allocVector(STRSXP, 4));
  for (i = 0; i < 4; i++) {
    SET_STRING_ELT(result, i, mkChar("hello"));
  }
  UNPROTECT(1);  
  return result;  
}
