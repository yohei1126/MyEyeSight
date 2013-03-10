#include "Device/IBuzzer.h"
#include "Device/BuzzerStub.h"
#include "MyTypes.h"

static U32 _freq;
static U32 _onInterval;
static U32 _volume;

/* ‰¹‚ð–Â‚ç‚· */
void Buzzer_tone(U32 freq, U32 onInterval, U32 volume) {
	_freq = freq;
	_onInterval = onInterval;
	_volume = volume;
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
