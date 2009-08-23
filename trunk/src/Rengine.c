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

int r_parse(const char *s){

  ParseStatus ps;
  SEXP pstr, cv, es;
  int er=0,i=0,l;

  PROTECT(cv=allocVector(STRSXP,5));
  SET_STRING_ELT(cv, 0, mkChar(s));
  UNPROTECT(1);
  printf("parsing \"%s\"\n", CHAR(STRING_ELT(cv,0)));    
  pstr=R_ParseVector(cv, 1, &ps, R_NilValue);  
  printf("%d\n",TYPEOF(pstr));  
  printf("parse status=%d, result=%x, type=%d\n", ps, (int) pstr, (pstr!=0)?TYPEOF(pstr):0);

  if (TYPEOF(pstr)==EXPRSXP) { /* if the object is a list of exps, eval them one by one */
    l=LENGTH(pstr);
    while (i<l) {
      es=R_tryEval(VECTOR_ELT(pstr,i), R_GlobalEnv, &er);
      i++;
    }
  } else
    es=R_tryEval(pstr, R_GlobalEnv, &er);

  printf("%d\n",er);
  printf("%d\n",TYPEOF(es));
  PrintValue(es);

  return 0;
}

int r_eval(int x){  

  SEXP es, exps;
  int er=0; 
  //es = R_tryEval(exps, R_GlobalEnv, &er);

  return 4*x;

}


int r_assign(){
  return 0;
}

