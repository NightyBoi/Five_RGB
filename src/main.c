#include <avr/io.h>
#include <util/delay.h>

//NOTE: RGB LEDS used are with common cathode, to use common anode just switch 5V and GND everywhere

int colour = 0;

void delaymagic(int x){
	int z;
	for (z=0;z<=x/2;z++){
		_delay_ms(1);
		if (PIND & (1<<PIND2)){
			colour++;
			if (colour==7) colour = 0;
			break;
		}
	}
	for (z=0;z<x/2;z++){
		_delay_ms(1);
	}
}



void TurnColor(int dio, int color){
	switch(dio){
		case 0:
			switch(color){
				case 0:
					PORTD &= (0<<PORTD3);
					PORTD &= (0<<PORTD4);
					PORTD &= (0<<PORTD5);
					PORTD ^= (1<<PORTD3);		//PORTD3 = red
					break;
				case 1:
					PORTD &= (0<<PORTD3);
					PORTD &= (0<<PORTD4);
					PORTD &= (0<<PORTD5);
					PORTD ^= (1<<PORTD4);		//PORTD4 = green
					break;
				case 2:
					PORTD &= (0<<PORTD3);
					PORTD &= (0<<PORTD4);
					PORTD &= (0<<PORTD5);
					PORTD ^= (1<<PORTD3);
					PORTD ^= (1<<PORTD4);
					break;
				case 3:
					PORTD &= (0<<PORTD3);
					PORTD &= (0<<PORTD4);
					PORTD &= (0<<PORTD5);
					PORTD ^= (1<<PORTD5);		//PORTD5 blue
					break;
				case 4:
					PORTD &= (0<<PORTD3);
					PORTD &= (0<<PORTD4);
					PORTD &= (0<<PORTD5);
					PORTD ^= (1<<PORTD5);
					PORTD ^= (1<<PORTD3);
					break;
				case 5:
					PORTD &= (0<<PORTD3);
					PORTD &= (0<<PORTD4);
					PORTD &= (0<<PORTD5);
					PORTD ^= (1<<PORTD5);
					PORTD ^= (1<<PORTD4);
					break;
				case 6:
					PORTD &= (0<<PORTD3);
					PORTD &= (0<<PORTD4);
					PORTD &= (0<<PORTD5);
					PORTD ^= (1<<PORTD5);
					PORTD ^= (1<<PORTD4);
					PORTD ^= (1<<PORTD3);
					break;
			}
			break;
		case 1:
			switch(color){
				case 0:
					PORTD |= (1<<PORTD6);
					PORTD |= (1<<PORTD7);
					PORTB |= (1<<PORTB0);
					PORTD ^= (1<<PORTD6);		//PORTD6 = red
					break;
				case 1:
					PORTD |= (1<<PORTD6);
					PORTD |= (1<<PORTD7);
					PORTB |= (1<<PORTB0);
					PORTD ^= (1<<PORTD7);		//PORTD7 = green
					break;
				case 2:
					PORTD |= (1<<PORTD6);
					PORTD |= (1<<PORTD7);
					PORTB |= (1<<PORTB0);
					PORTD ^= (1<<PORTD6)|(1<<PORTD7);
					break;
				case 3:
					PORTD |= (1<<PORTD6);
					PORTD |= (1<<PORTD7);
					PORTB |= (1<<PORTB0);
					PORTB ^= (1<<PORTB0);		//PORTB1 blue
					break;
				case 4:
					PORTD |= (1<<PORTD6);
					PORTD |= (1<<PORTD7);
					PORTB |= (1<<PORTB0);
					PORTD ^= (1<<PORTD6);
					PORTB ^= (1<<PORTB0);
					break;
				case 5:
					PORTD |= (1<<PORTD6);
					PORTD |= (1<<PORTD7);
					PORTB |= (1<<PORTB0);
					PORTD ^= (1<<PORTD7);
					PORTB ^= (1<<PORTB0);
				break;
				case 6:
					PORTD |= (1<<PORTD6);
					PORTD |= (1<<PORTD7);
					PORTB |= (1<<PORTB0);
					PORTD ^= (1<<PORTD7);
					PORTD ^= (1<<PORTD6);
					PORTB ^= (1<<PORTB0);
				break;
			}
			break;
		case 2:
			switch(color){
				case 0:
				PORTB |= (1<<PORTB1);
				PORTB |= (1<<PORTB2);
				PORTB |= (1<<PORTB3);
				PORTB ^= (1<<PORTB1);		//PORTB2 = red
				break;
				case 1:
				PORTB |= (1<<PORTB1);
				PORTB |= (1<<PORTB2);
				PORTB |= (1<<PORTB3);
				PORTB ^= (1<<PORTB2);		//PORTB3 = green
				break;
				case 2:
				PORTB |= (1<<PORTB1);
				PORTB |= (1<<PORTB2);
				PORTB |= (1<<PORTB3);
				PORTB ^= (1<<PORTB2);
				PORTB ^= (1<<PORTB1);
				break;
				case 3:
				PORTB |= (1<<PORTB1);
				PORTB |= (1<<PORTB2);
				PORTB |= (1<<PORTB3);
				PORTB ^= (1<<PORTB3);		//PORTD5 blue
				break;
				case 4:
				PORTB |= (1<<PORTB1);
				PORTB |= (1<<PORTB2);
				PORTB |= (1<<PORTB3);
				PORTB ^= (1<<PORTB3);
				PORTB ^= (1<<PORTB1);
				break;
				case 5:
				PORTB |= (1<<PORTB1);
				PORTB |= (1<<PORTB2);
				PORTB |= (1<<PORTB3);
				PORTB ^= (1<<PORTB3);
				PORTB ^= (1<<PORTB2);
				break;
				case 6:
				PORTB |= (1<<PORTB1);
				PORTB |= (1<<PORTB2);
				PORTB |= (1<<PORTB3);
				PORTB ^= (1<<PORTB3);
				PORTB ^= (1<<PORTB2);
				PORTB ^= (1<<PORTB1);
				break;
			}
			break;
		case 3:
			switch(color){
				case 0:
				PORTC |= (1<<PORTC0);
				PORTC |= (1<<PORTC1);
				PORTC |= (1<<PORTC2);
				PORTC ^= (1<<PORTC0);		//PORTC0 = red
				break;
				case 1:
				PORTC |= (1<<PORTC0);
				PORTC |= (1<<PORTC1);
				PORTC |= (1<<PORTC2);
				PORTC ^= (1<<PORTC1);		//PORTC1 = green
				break;
				case 2:
				PORTC |= (1<<PORTC0);
				PORTC |= (1<<PORTC1);
				PORTC |= (1<<PORTC2);
				PORTC ^= (1<<PORTC1);
				PORTC ^= (1<<PORTC0);
				break;
				case 3:
				PORTC |= (1<<PORTC0);
				PORTC |= (1<<PORTC1);
				PORTC |= (1<<PORTC2);
				PORTC ^= (1<<PORTC2);		//PORTC2 blue
				break;
				case 4:
				PORTC |= (1<<PORTC0);
				PORTC |= (1<<PORTC1);
				PORTC |= (1<<PORTC2);
				PORTC ^= (1<<PORTC2);
				PORTC ^= (1<<PORTC0);
				break;
				case 5:
				PORTC |= (1<<PORTC0);
				PORTC |= (1<<PORTC1);
				PORTC |= (1<<PORTC2);
				PORTC ^= (1<<PORTC2);
				PORTC ^= (1<<PORTC1);
				break;
				case 6:
				PORTC |= (1<<PORTC0);
				PORTC |= (1<<PORTC1);
				PORTC |= (1<<PORTC2);
				PORTC ^= (1<<PORTC2);
				PORTC ^= (1<<PORTC1);
				PORTC ^= (1<<PORTC0);
				break;
			}
			break;
		case 4:
			switch(color){
				case 0:
				PORTC |= (1<<PORTC3);
				PORTC |= (1<<PORTC4);
				PORTC |= (1<<PORTC5);
				PORTC ^= (1<<PORTC3);		//PORTC3 = red
				break;
				case 1:
				PORTC |= (1<<PORTC3);
				PORTC |= (1<<PORTC4);
				PORTC |= (1<<PORTC5);
				PORTC ^= (1<<PORTC4);		//PORTC4 = green
				break;
				case 2:
				PORTC |= (1<<PORTC3);
				PORTC |= (1<<PORTC4);
				PORTC |= (1<<PORTC5);
				PORTC ^= (1<<PORTC4);
				PORTC ^= (1<<PORTC3);
				break;
				case 3:
				PORTC |= (1<<PORTC3);
				PORTC |= (1<<PORTC4);
				PORTC |= (1<<PORTC5);
				PORTC ^= (1<<PORTC5);		//PORTC5 blue
				break;
				case 4:
				PORTC |= (1<<PORTC3);
				PORTC |= (1<<PORTC4);
				PORTC |= (1<<PORTC5);
				PORTC ^= (1<<PORTC5);
				PORTC ^= (1<<PORTC3);
				break;
				case 5:
				PORTC |= (1<<PORTC3);
				PORTC |= (1<<PORTC4);
				PORTC |= (1<<PORTC5);
				PORTC ^= (1<<PORTC5);
				PORTC ^= (1<<PORTC4);
				break;
				case 6:
				PORTC |= (1<<PORTC3);
				PORTC |= (1<<PORTC4);
				PORTC |= (1<<PORTC5);
				PORTC ^= (1<<PORTC5);
				PORTC ^= (1<<PORTC4);
				PORTC ^= (1<<PORTC3);
				break;
			}
			break;
	}
}

int main(void)
{
	DDRD = 251;
	DDRB = 63;
	DDRC = 63;						
	PCMSK2 |= (1<<PCINT18);								//Pin-Change Interrupt Setup
	PCICR |= (1<<PCIE2);
	PORTB = 63;
	PORTD = 192;
	PORTC = 63;
	while(1) {

		TurnColor(0,colour);
		delaymagic(4000);
		TurnColor(1,colour);
		delaymagic(4000);
		TurnColor(2,colour);
		delaymagic(4000);
		TurnColor(3,colour);
		delaymagic(4000);
		TurnColor(4,colour);
		delaymagic(4000);
	}
}