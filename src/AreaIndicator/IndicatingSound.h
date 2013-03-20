#ifndef INDICATINGSOUND_H_
#define INDICATINGSOUND_H_

#include "MyTypes.h"

typedef struct IndicatingSound {
	U32 frequency;
	U32 onInterval;
	U32 volume;
} IndicatingSound;

void IndicatingSound_create(IndicatingSound* sound, U32 m_frequency, U32 m_onInterval, U32 m_volume);

void IndicatingSound_indicate(IndicatingSound* sound);

#endif /* INDICATINGSOUND_H_ */
