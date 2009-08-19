#include <stdio.h>

#include "Rinit.h"

typedef unsigned char byte;

int read_cmd(byte *buf);
int write_cmd(byte *buff, int len);

void debugloop(){
  printf("start debug mode\n");

  if(r_setup()){
    printf("fail initR\n");
    return; 
  }  
  printf("R initialized\n");
  r_run();

  printf("finish debug mode\n");
}

void mainloop(){
  int fn, args1, args2, result;
  byte buff[100];

  while (read_cmd(buff) > 0) {
    fn = buff[0];
   
    if (fn == 1){
      args1 = buff[1];
      result = r_eval(args1);
    }else if(fn == 2){
      args1 = buff[1];
      args2 = buff[2];   
      result = r_eval(args1);   
    }
    buff[0] = result;
    write_cmd(buff, 1);
  }  
}

int main(int argc, char **argv ){

  if (argc==2 && !strcmp(argv[1],"-d")){
    debugloop();
  }else{
    mainloop();
  }  
  return 0;
}
