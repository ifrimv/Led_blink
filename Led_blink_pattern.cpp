// 
// 
// 
#include "led_blink_pattern.h"


Led_blink::Led_blink(int pin) {
	ledPin = pin;
	isBlinking = false;
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
	totalPatterns = 0;
}

void Led_blink::addPattern(unsigned long onTime, unsigned long offTime, uint8 repeat, uint16 pauseTime) {
	if (totalPatterns < MAX_PATTERN_NUMBERS) {
		patterns[totalPatterns].onTime = onTime;
		patterns[totalPatterns].offTime = offTime;
		patterns[totalPatterns].repeat = repeat;
		patterns[totalPatterns].pauseTime = pauseTime;
		totalPatterns++;
	}
}

void Led_blink::startBlink(uint8 ix) {
	stopBlink();
	if (ix >= 0 && ix < totalPatterns) {
		isBlinking = true;
		curentPattern = ix;
		repeatCounter = 0;
		onTime = patterns[curentPattern].onTime;
		offTime = patterns[curentPattern].offTime;
		repeat = patterns[curentPattern].repeat;
		pauseTime = patterns[curentPattern].pauseTime;
		toggle(); // LED ON
	}
}

void Led_blink::stopBlink() {
	if (isBlinking) {
		isBlinking = false;
		ticker.detach();
		digitalWrite(ledPin, LOW);
	}
}

void Led_blink::toggle() {
	if (repeat) {
		//blink with pause
		if (!digitalRead(ledPin)) {			
			//rising edge	
			if (repeatCounter < repeat) {	
				//blink period			
				repeatCounter++;
				ticker.once_ms(onTime, [this]() { toggle(); });
				digitalWrite(ledPin, HIGH); //Led ON
			}
			else {							
				//pause period		
				ticker.once_ms(pauseTime, [this]() { toggle(); });
				repeatCounter = 0;			//restart cicle
			}
		}
		else {								
			//falling edge		
			ticker.once_ms(offTime, [this]() { toggle(); });
			digitalWrite(ledPin, LOW);		//Led OFF
		}
	}
	else {
		// blink
		digitalWrite(ledPin, !digitalRead(ledPin));
		if (digitalRead(ledPin) == HIGH) {
			//Start Led ON  period
			ticker.once_ms(onTime, [this]() { toggle(); });
		}
		else {
			//Start Led OFF period 
			ticker.once_ms(offTime, [this]() { toggle(); });
		}
	}
}
