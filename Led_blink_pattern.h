// Led_blink_pattern.h

#ifndef LED_BLINK_H
#define LED_BLINK_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <Arduino.h>
#include <Ticker.h>

#define MAX_PATTERN_NUMBERS 5

struct struct_BlinkPatern{
	//time in ms
	uint16 onTime;		// ms - led ON
	uint16 offTime;		// ms - led OFF
	uint16 pauseTime;	// ms - pause
	uint8 repeat;		// number of blinks before pause, if 0 -> no pause
};

class Led_blink {
private:
	int ledPin;
	bool isBlinking;
	uint8 curentPattern;
	uint8 totalPatterns;
	uint8 repeatCounter;
	uint16 onTime;
	uint16 offTime;
	uint16 pauseTime;
	uint8 repeat;
	struct_BlinkPatern patterns[MAX_PATTERN_NUMBERS];
	Ticker ticker;
	void toggle();

public:
	Led_blink(int pin);
	void addPattern(unsigned long onTime, unsigned long offTime, uint8 repeat=0, uint16 pauseTime=0);
	void startBlink(uint8 patternIndex);
	void stopBlink();
};

#endif