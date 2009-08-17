#include "Rcallbacks.h"

int Re_ReadConsole(RCCONST char *prompt, unsigned char *buf, int len, int addtohistory)
{
    return -1;
}

void Re_ShowMessage(RCCONST char *buf)
{

}

void Re_WriteConsoleEx(RCCONST char *buf, int len, int oType)
{

}


/* Indicate that input is coming from the console */
void Re_ResetConsole()
{

}

/* Stdio support to ensure the console file buffer is flushed */
void Re_FlushConsole()
{
   
}

/* Reset stdin if the user types EOF on the console. */
void Re_ClearerrConsole()
{

}
void Re_Busy(int which)
{

}

int Re_ShowFiles(int nfile, 		/* number of files */
                 RCCONST char **file,	/* array of filenames */
                 RCCONST char **headers,/* the `headers' args of file.show. Printed before each file. */
                 RCCONST char *wtitle,  /* title for window = `title' arg of file.show */
                 Rboolean del,	        /* should files be deleted after use? */
                 RCCONST char *pager)	/* pager to be used */
{
    return 1;
}

int Re_ChooseFile(int new, char *buf, int len)
{
   
}

void Re_loadhistory(SEXP call, SEXP op, SEXP args, SEXP env)
{

}

void Re_savehistory(SEXP call, SEXP op, SEXP args, SEXP env)
{

}
