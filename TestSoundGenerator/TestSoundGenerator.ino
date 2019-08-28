/*
 Name:		TestSoundGenerator.ino
 Created:	8/28/2019 2:17:32 PM
 Author:	gorangrubic
*/

#include <LightChrono.h>
#include <Chrono.h>

#define TONE_CYCLE 1000
#define TONE_DURATION 750
#define TONE_PITCH 220
#define SOUND_OUT 9

Chrono soundTimer;

// the setup function runs once when you press reset or power the board
void setup() {
	
	pinMode(SOUND_OUT, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
  
	if (soundTimer.hasPassed(TONE_CYCLE)) {
		tone(SOUND_OUT, TONE_PITCH, TONE_DURATION);
		soundTimer.restart();
	}
}
