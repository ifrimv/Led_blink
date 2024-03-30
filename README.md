# Led blink

Arduino Led blink library for ESP8266.

## Description

This library facilitates LED blinking with specified patterns on ESP8266 microcontrollers. It allows you to control the duration of LED on-time, off-time, repetitions, and pause time between blinks.

### Pattern Parameters

- `onTime`: Duration of LED being on.
- `offTime`: Duration of LED being off.
- `repeat`: Number of times the pattern repeats. If `repeat = 0`, `pauseTime` is used instead of `offTime`.
- `pauseTime`: Duration of pause between pattern repetitions.

### Example

```cpp
/*
Pattern example
 /''\_____/''\_____/''\____________/''\_...
 |-    repeat (3)    -| pause time |
*/
#include <Led_blink_pattern.h>


// Create an instance of Led_blink
Led_blink led(LED_PIN);

void setup() {
  //add pattern
  led.addPattern(onTime, offTime, repeat, pauseTime);;
  //Blink LED with specified pattern
  led.startBlink(ix);
}

void loop() {
	
}