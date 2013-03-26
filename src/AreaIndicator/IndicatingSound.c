#include "AreaIndicator/IndicatingSound.h"
#include "Device/IBuzzer.h"

void IndicatingSound_create(IndicatingSound* sound, U32 frequency, U32 onInterval, U32 volume) {
	sound->frequency = frequency;
	sound->onInterval = onInterval;
	sound->volume = volume;
}

void IndicatingSound_indicate(IndicatingSound* sound) {
	Buzzer_tone(sound->frequency, sound->onInterval, sound->volume);
}


