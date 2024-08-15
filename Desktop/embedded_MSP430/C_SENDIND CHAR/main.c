#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	UCA1CTLW0 |= UCSWRST;

    UCA1CTLW0 |= UCSSEL__SMCLK; //Choose SMCLK

    UCA1BRW = 8;                //Set Pre-Scaler to 8

    UCA1MCTLW |= 0xD600;         //Configure modulation settings + low frequency mode

    P4SEL1 &= ~BIT3;
    P4SEL0 |= BIT3;              //Puts UART on P4.3

    PM5CTL0 &= LOCKLPM5;        //turn on IO

    UCA1CTLW0 &= ~UCSWRST;

    int i = 0;

    while(1)
    {
        UCA1TXBUF = 'A';      //send A out over UART
        for(i = 0; i<1000; i++)
        {
        }

	return 0;
}
