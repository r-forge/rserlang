#include "Rcallbacks.h"

int Re_ReadConsole(RCCONST char *prompt, unsigned char *buf, int len, int addtohistory){
  fprintf(stderr,"Re_ReadConsole\n");
  return -1;
}

void Re_ShowMessage(RCCONST char *buf){
  fprintf(stderr,"Re_ShowMessage\n");
}

void Re_WriteConsoleEx(RCCONST char *buf, int len, int oType){
  fprintf(stderr,"Re_WriteConsoleEx\n");
}


/* Indicate that input is coming from the console */
void Re_ResetConsole(){
  fprintf(stderr,"Re_ResetConsole\n");
}

/* Stdio support to ensure the console file buffer is flushed */
void Re_FlushConsole(){
  fprintf(stderr,"Re_FlushConsole\n");
}

/* Reset stdin if the user types EOF on the console. */
void Re_ClearerrConsole(){  
  fprintf(stderr,"Re_ClearerrConsole\n");
}
void Re_Busy(int which){
  fprintf(stderr,"Re_Busy%s.%s\n",R_MAJOR, R_MINOR);
}

int Re_ShowFiles(int nfile, 		/* number of files */
                 RCCONST char **file,	/* array of filenames */
                 RCCONST char **headers,/* the `headers' args of file.show. Printed before each file. */
                 RCCONST char *wtitle,  /* title for window = `title' arg of file.show */
                 Rboolean del,	        /* should files be deleted after use? */
                 RCCONST char *pager)	/* pager to be used */{
  fprintf(stderr,"Re_ShowFiles\n");
  return 1;
}

int Re_ChooseFile(int new, char *buf, int len){
  fprintf(stderr,"Re_ChooseFile\n");
}

void Re_loadhistory(SEXP call, SEXP op, SEXP args, SEXP env){
  fprintf(stderr,"Re_loadhistory\n");
}

void Re_savehistory(SEXP call, SEXP op, SEXP args, SEXP env){
  fprintf(stderr,"Re_savehistory\n");
}
