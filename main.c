/* Name: Olayiwola David Abraham
 * Date: 2/14/24
 * Random Number and Color Generator
 *
/* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>
#include "lcd_utils.h"
#include <stdio.h>
#include <stdlib.h>

void delay_ms(uint32_t milliseconds) {
    uint32_t i;
    for(i = 0; i < milliseconds*300; i++) {
        ; // Delay loop
    }
}

uint8_t i;
void RGB_Output(uint8_t RND_num){
// generate RGB and correlate to random num

    switch(RND_num){

           case 0:
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
           GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);//white
           break;

           case 1:
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);//black
           break;

           case 2:
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
           GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);//red
           break;

           case 3:
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
           GPIO_setOutputHighOnPin(GPIO_PORT_P2,GPIO_PIN1 |GPIO_PIN0);//yellow
           break;

           case 4:
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
           GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2 |GPIO_PIN0);//magenta
           break;

           case 5:
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
           GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2 |GPIO_PIN1);//cyan
           break;

           case 6:
           GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
           GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);//blue
           break;

           case 7:
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0 |GPIO_PIN1 |GPIO_PIN2);
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);//green
            break;
           }
}



int main(void){
    uint8_t RND_num;

    uint8_t prevNum = 255;

    /* Stop Watchdog  */
    WDT_A_hold(WDT_A_BASE);

    // Initialize LCD
    LCD_init();

    // Configure the pins
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2 | GPIO_PIN1 | GPIO_PIN0);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2 | GPIO_PIN1 | GPIO_PIN0);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1);

    showChar('E',char1);
    showChar('E',char2);
    showChar('C',char3);
    showNum(7,char4);


   while(1){

       while (GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1) == GPIO_INPUT_PIN_HIGH) {
       }
  delay_ms(5);

       while (GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1) == GPIO_INPUT_PIN_LOW) {
       }
  delay_ms(5);


  RND_num=(rand() %8);


  if(RND_num == prevNum){
      RND_num=RND_num+1;
      if(RND_num == 8){
          RND_num = RND_num-2;
      }

    }

  prevNum=RND_num;

    clearChar(char6);//LCD screen
    showNum(RND_num,char6);


      printf("Random number is %d\n", RND_num);

  RGB_Output(RND_num);
  delay_ms(150);

       }
    return 0;
}


