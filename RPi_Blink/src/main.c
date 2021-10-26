//============================================================================
// Name        : main.cpp
// Author      : Javi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdint.h>
#include <wiringPi.h>

void delay_until (unsigned int next);

const uint8_t pin_blink = 14;

int main() {

	// GPIO init
	wiringPiSetupGpio();

	// GPIO config
	pinMode(pin_blink, OUTPUT);

	unsigned int next = millis();
	while (1) {
		digitalWrite(pin_blink, HIGH);
		next += 4000;
		delay_until (next);

		digitalWrite(pin_blink, LOW);
		next += 4000;
		delay_until (next);
	}
}

void delay_until (unsigned int next) {
	unsigned int now = millis();
	if (next > now) {
		delay (next - now);    }
}
