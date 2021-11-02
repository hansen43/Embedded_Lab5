#include "msp430G2553.h"

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;           // Stop WDT
     P1DIR |= BIT6;                     // P1.6 set for output
     P1OUT = 0x00;
     P1SEL |= BIT6;                     // select TA0.1 output signal
     TACCR0 = 62500-1;                  // PWM Time Period/frequency (1 MHz)
     TACCTL1 = OUTMOD_7;                // reset/set mode 7 for output signal
     TACCR1 = 6250;                     // PWM Duty cycle is 10%
     TACTL = TASSEL_2 + MC_1 + ID_3;    // SMCLK and Up Mode, divide frequency by 8

     while(1){
         P1OUT ^= BIT6;
             }

}
