#include <msp430.h> 

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1DIR |= BIT0;               //Configure P1.0 (LED1) as output
	PM5CTL0                            //Turn On GPIO System







	return 0;
}
