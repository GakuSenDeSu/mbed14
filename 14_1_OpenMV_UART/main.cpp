#include"mbed.h"

Serial pc(USBTX,USBRX); //tx,rx
Serial uart(D12,D11); //tx,rx
DigitalIn button(SW2);

int main(){
   uart.baud(9600);
   while(1){
      if( button == 0){
         char s[21];
         sprintf(s,"qrcode");
         uart.puts(s);
         pc.printf("send\r\n");
         wait(0.5);
      }
      wait_us(10);
      if(uart.readable()){
            while (1){
            char recv = uart.getc();
            pc.putc(recv);
            if (recv == 'r'){
               pc.printf("\r\n");
               break;
            }
            }
      }
   }

}