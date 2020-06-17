#include"mbed.h"

Serial pc(USBTX,USBRX); //tx,rx
Serial uart(D12,D11); //tx,rx

int main(){
   uart.baud(9600);
   char buf[1000]={0};
   while(uart.readable()){
      for (int i=0; ; i++) {
          char recv = uart.getc();
          if (recv == '\r') {
            break;}
        buf[i] = pc.putc(recv);
        }
        wait(0.1);
    }
}