#include <msp430.h> 

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1DIR |= BIT0;
	P1OUT &= ~BIT0;             //Clear LED1

	P4DIR &= ~BIT1;      //Set P4.1 to input
	P4REN |= BIT1;       //Enables resistor
	P4OUT |= BIT1;       //Sets resistor to pull up

	PM5CTL0 &= ~LOCKLPM5; //Turn on Digital IO

	int SW1;
	int i;


	while(1)
	{

	    SW1 = P4IN;     //Read Port 4
	    SW1 &= BIT1;     //Clear all bits except SW1


	    if(SW1 == 0)
	    {
	        P1OUT ^= BIT0;
	    }


	}

	return 0;
}
