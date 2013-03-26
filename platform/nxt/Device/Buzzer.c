#include "Device/ISonarSensor.h"
#include "ecrobot_interface.h"

/* ‰¹‚ð–Â‚ç‚· */
void Buzzer_tone(U32 freq, U32 onInterval, U32 volume) {
	ecrobot_sound_tone (freq, onInterval, volume);
}
