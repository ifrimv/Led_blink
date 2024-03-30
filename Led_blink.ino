/*
    Name:       Blink.ino
    Created:	29/03/2024 15:07:51
    Author:     ifrimv
	Hardware	ESP8266 LOLIN(WEMOS) D1 mini Lite
	Arduino		15
	Package		2.7.4
*/
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Led_blink_pattern.h"
#define LED_PIN D7

Led_blink ledError(LED_PIN);
uint8 ix= 0;

void setup(){

	ledError.addPattern(100, 2500);
	ledError.addPattern(300, 1000);
	ledError.addPattern(1000, 300);
	ledError.addPattern(300, 400, 2, 2500);
	ledError.addPattern(300, 300, 0, 0);
}

void loop(){
	ledError.startBlink(ix);

	delay(20000); //20second delay
	if (ix++ >= 4)	{
		ix = 0;
	} 
}
