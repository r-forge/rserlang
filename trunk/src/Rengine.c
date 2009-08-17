#include "eri.h"

int r_eval(int x){

  SEXP es, exps, R_GlobalEnv;
  int er=0;

  run_Rmainloop();
  SEXP a = allocVector("1+1", 1);
  //es=R_tryEval(exps, R_GlobalEnv, &er);

  return 4*x;
}
