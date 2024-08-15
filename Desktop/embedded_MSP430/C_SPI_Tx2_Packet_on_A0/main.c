#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	UCA0CTLW0 |= UCSWRST;
	UCA0CTLW0 |= UCSSEL__SMCLK;
	UCA0BRW   |= 10;

	UCA0CTLW0 |= UCSYNC;

	UCA0CTLW0 |= UCMST;

	P4DIR &= ~BIT1;
	P4REN |= BIT1;
	P4OUT |= BIT1;
	P4IES |= BIT1;

	P1SEL1 &= ~BIT5;
	P1SEL0 |= BIT5;

    P1SEL1 &= ~BIT7;
    P1SEL0 |= BIT7;

    P1SEL1 &= ~BIT6;
    P1SEL0 |= BIT6;

    PM5CTL0 &= ~LOCKLPM5;


    UCA0CTLW0 &= ~UCSWRST;

    P4IFG &= ~BIT1;
    P4IE |= BIT1;

    UCA0IFG &= ~UCTXIFG;
    UCAIE |= UCTXIE;

    __enable_interrupt();

    while(1)
    {}

	return 0;
}


#pragma vector = PORT4_VECTOR
__interrupt void ISR_Port4_S1 (void) {
    position = 0;
    UCA0TXBUF = packet [position];
    P4IFG &= ~BIT1;
}


#pragma vector = EUSCI_A0_VECTOR
__interrupt void ISR_EUSCI_A0 (void) {
    position++;

    if(position< sizeof(packet))
    {
        UCA0TXBUF = packet [position];
    }
    else {
        UCA0IFG &= ~UCTXIFG;
    }
}
