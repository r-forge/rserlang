/* important changes between versions:

   0.1- first public release
 */
#include <Rinternals.h>
#include "erl_interface.h"
#include "ei.h"

#define COOKIE "rerlang"
#define NODE_NAME "node01@localhost"

int fd;
SEXP rE_connect();
SEXP rE_test(int num);
SEXP rE_eval(SEXP str);
SEXP ETERM2SEXP(ETERM *eterm);
