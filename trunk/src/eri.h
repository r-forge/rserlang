#include <R.h>
#include <Rinternals.h>
#include <Rversion.h>

#define SEXP2L(s) ((unsigned long)(s))
#define L2SEXP(s) ((SEXP)(unsigned long)(s))


/* the viewpoint is from R, i.e. "get" means "Erlang->R" whereas "put" means "R->Erlang" */

SEXP eri_getString();
