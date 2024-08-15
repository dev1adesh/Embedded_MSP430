#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	                            //--setup ports
	P1DIR |= BIT0;              //set p1.0 to output
	P1OUT &= ~BIT0 ;             //clear p1.0 initally

	PM5CTL0 &= ~LOCKLPM5;

	//-SETUP TIMER

	TB0CTL |= TBCLR;            //reset timer
	TB0CTL |= TBSSEL__ACLK;       //ACLK as Source
	TB0CTL |= MC__CONTINUOUS;       //put timer into continuous mode
	TB0CTL |= CNTL_1;               //12 BIT LENGTH


	//-SETUP TIMER INTERRUPT

	TB0CTL |= TBIE;             //local enable for overflow
	__enable_interrupt();       //global enable GIE
	TB0CTL &= ~TBIFG;           //clears interrupt flag

	while(1){}


	return 0;
}



#pragma vector = TIMER0_B1_VECTOR
__interrupt void ISR_TB0_OVERFLOW(void)
{
    P1OUT ^= BIT0;          //toggle
    TB0CTL &= ~TBIFG;   //clears flag

}
