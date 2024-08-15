#include <msp430.h> 


int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	//SETUP PORTS

	P1DIR |= BIT0;              //Config P1.0 to an output
	P1OUT &= ~BIT0;             //Clear P1.0 initially

	P4DIR &= ~BIT1;             //Config P4.1 as input
    P4REN |= BIT1;       //Enables resistor
    P4OUT |= BIT1;       //Sets resistor to pull up

    P4IES |= BIT1;      //Makes sensitivity H TO L

    PM5CTL0 &= ~LOCKLPM5; //Turn on Digital IO


    //Setup IRQ

    P4IE |= BIT1;            //enable P4.1 IRQ
    __enable_interrupt();    //Enable Maskable IRQs
    P4IFG &= ~BIT1;        //Clear P4.1 irq fLAG

    while(1)
    {


    }

	return 0;
}


//---IRS--------------------------//

#pragma vector = PORT4_VECTOR
__interrupt void ISR_PORT4_S1(void)
{
    P1OUT ^= BIT0;    //toggle LED1
    P4IFG &= ~BIT1;          //Clear P4.1 irq fLAG
}



