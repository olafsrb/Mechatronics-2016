#include <avr/io.h>
#include "delay.h"
#include <avr/interrupt.h>

#define CPU_hz 16000000
#define BAUDRATE 9600
#define BAUDRC ((CPU_hz/16/BAUDRATE) - 1)
#define TRANS_BUFFER_SIZE 128

char buffer[TRANS_BUFFER_SIZE];
uint8_t reading_pos = 0;
uint8_t writing_pos = 0;

void addSerial(char c);
void writeSerial();

int main(void) {

	UBRR0H = (BAUDRC >> 8);		// Set the baudrate for the upper byte
	UBRR0L = BAUDRC;			// Set the baud rate for the lower byte

	//UCSR0B = (1 << RXEN0);// Enable receiver

	UCSR0B = (1 << TXEN0)| (1 << TXCIE0);	// Enable the transmitter and the interrupt enable for transmission finished
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);			// Set 8 bit data frame

	sei();			// enable interrupt


	while(1) {



// TRANMISSION
/*
		writeSerial("Hello\n\r");
		writeSerial("world\n\r");

		delay_s(10);

		writeSerial("Goodbye\n\r");
		delay_s(10);
*/
	}
}

void addSerial(char c){
	buffer[writing_pos] = c;
	writing_pos++;

	if(writing_pos >= TRANS_BUFFER_SIZE) {
		writing_pos = 0;
	}
}

void writeSerial(char c[]) {
	for(uint8_t i = 0; i < strlen(c); i++) {
		addSerial(c[i]);
	}
	if(UCSR0A & (1 << UDRE0)) {
		UDR0 = 0;
	}
}

// This interrupt vector is used to detect the TXCIEn - transmission complete enable
ISR(USART_TX_vect) {
	if(reading_pos != writing_pos) {
		UDR0 = buffer[reading_pos];
		reading_pos++;

		if(reading_pos >= TRANS_BUFFER_SIZE) {
			reading_pos = 0;
		}
	}

}