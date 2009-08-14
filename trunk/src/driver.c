#include <stdio.h>
typedef unsigned char byte;

int read_cmd(byte *buf);
int write_cmd(byte *buff, int len);

int main(){
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
