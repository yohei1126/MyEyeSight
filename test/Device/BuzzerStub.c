#include "Device/IBuzzer.h"
#include "Device/BuzzerStub.h"
#include "MyTypes.h"

static U32 _freq = 0;
static U32 _onInterval = 0;
static U32 _volume = 0;

void Buzzer_tone(U32 freq, U32 onInterval, U32 volume) {
	_freq = freq;
	_onInterval = onInterval;
	_volume = volume;
}

void BuzzerStub_init(void){
	_freq = 0;
	_onInterval = 0;
	_volume = 0;
}

U32 BuzzerStub_getLastFrequency(void) {
	return _freq;
}

U32 BuzzerStub_getLastOnInterval(void) {
	return _onInterval;
}

U32 BuzzerStub_getLastVolume(void) {
	return _volume;
}
