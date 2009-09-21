/* important changes between versions:

   0.1- first public release
 */
#include <Rinternals.h>


#define COOKIE "rerlang"
#define NODE_NAME "node01@localhost"

int fd;
SEXP rE_connect();
void rE_test(int num);
void rE_eval(char *buf);
