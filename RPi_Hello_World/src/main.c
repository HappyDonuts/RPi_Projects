//============================================================================
// Name        : main.cpp
// Author      : Javi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <wiringPi.h>

void delay_until (unsigned int next);

int main() {

	wiringPiSetupGpio();
	pinMode(15, OUTPUT);

	unsigned int next = millis();
	while (1) {
		printf("Hello World using RPi!\r\n");
		next += 1000;
		delay_until (next);

	}
}

void delay_until (unsigned int next) {
	unsigned int now = millis();
	if (next > now) {
		delay (next - now);    }
}
