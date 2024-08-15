#include <msp430.h> 

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	//Setup Ports
	P1DIR |= BIT0;                //set port 1 pin0 to output
	P1OUT &= ~BIT0;                //Clear LED1 initially
	PM5CTL0 &= ~LOCKLPM5;           //Turn on Digital IO

	//Setup TImer
	
	TB0CTL |= TBCLR;                //reset timer
	TB0CTL |= TBSSEL__ACLK;         //Clock = ACLK
	TB0CTL |= MC__CONTINUOUS;       //Mode = Continuous

	//--Seup the Timer overflow IRQ

	TB0CTL |= TBIE;                    // LOCAL ENABLE FOR TBO OVERFLOW
	__enable_interrupt();               //Enable maskable IRQ

	TB0CTL &= ~TBIFG;                   //Clear IRQ Flag

	while(1){}

	return 0;
}




//--ISRs-------------------------//

#pragma vector = TIMER0_B1_VECTOR
__interrupt void ISR__TB0__Overflow(void)
{
        P1OUT ^= BIT0;              //Toggle LED1
        TB0CTL &= ~TBIFG;           //Clear IRQ Flag
}
