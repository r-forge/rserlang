#include "eri.h"
#include "Rinit.h"


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

int r_eval(int x){  
  return 4*x;

}
