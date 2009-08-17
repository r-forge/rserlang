#include "eri.h"

int r_eval(int x){

  SEXP es, exps, R_GlobalEnv;
  int er=0;
  structRstart rp;
  Rstart Rp = &rp;

  if (!getenv("R_HOME")) {
    fprintf(stderr, "R_HOME is not set. Please set all required environment variables before running this program.\n");
    return 4*x;
  }else{
    fprintf(stderr,"%s.%s\n",R_MAJOR, R_MINOR);
    R_DefParams(Rp);
    Rp->NoRenviron = 0;
    R_SetParams(Rp);

    setup_Rmainloop();    
    return 5*x;
  }

  //run_Rmainloop();
  //SEXP a = allocVector("1+1", 1);
  //es=R_tryEval(exps, R_GlobalEnv, &er);

  return 4*x;
}
