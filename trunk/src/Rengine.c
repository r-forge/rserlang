#include "eri.h"
#include "Rinit.h"

#include <R_ext/Parse.h>


/*
 * Rargv is the fake argument list we use to initialize R.
 */
static char *Rargv[] = {"rerlang", "--no-save", "--no-restore","--quiet", NULL};
#define N_R_ARGS ((sizeof(Rargv)/sizeof(char *)) - 1)


int r_setup(){

  int initRes;
  initRes=initR(N_R_ARGS, Rargv);
  
  return initRes;
}

void r_run(){
  run_Rmainloop();
}

int r_parse(){

  ParseStatus ps;
  SEXP pstr, cv;

  pstr=R_ParseVector(cv, 1, &ps,R_NilValue);

  return 0;
}

int r_eval(int x){  

  SEXP es, exps;
  int er=0; 
  es = R_tryEval(exps, R_GlobalEnv, &er);

  return 4*x;

}


int r_assign(){
  return 0;
}

