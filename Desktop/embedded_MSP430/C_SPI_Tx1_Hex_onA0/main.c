#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	UCA0CTLW0 |= UCSWRST;

	UCA0CTLW0 |= UCSSEL__SMCLK;
	UCA0BRW = 10;

	UCA0CTLW0 |= UCSYNC;
    UCA0CTLW0 |= UCMST;



    P1SEL1 &= ~BIT5;
    P1SEL0 |=  BIT5;

    P1SEL1 &= ~BIT7;
    P1SEL0 |=  BIT7;

    P1SEL1 &= ~BIT6;
    P1SEL0 |=  BIT6;

    PM5CTL0 &= ~LOCKLPM5;

    UCA0CTLW0 &= ~UCSWRST;

    int i =0;

    while(1)
    {
        UCA0TXBUF = 0x4D;
        for(i=0;i<10000;i++)
        {

        }
    }






	return 0;
}
