#ifndef INDICATINGSOUND_H_
#define INDICATINGSOUND_H_

#include "MyTypes.h"

/* unit: Hz */
#define HIGH_FREQUENCY 		1300
#define MIDDLE_FREQUENCY 	800
#define LOW_FREQUENCY 		500

/* unit:mili second */
#define DEFAULT_ON_INTERVAL	100

#define DEFAULT_VOLUME		10

typedef struct _IndicatingSound {
	U32 frequency;
	U32 onInterval;
	U32 volume;
} IndicatingSound;

void IndicatingSound_create(IndicatingSound* sound, U32 m_frequency, U32 m_onInterval, U32 m_volume);

void IndicatingSound_indicate(IndicatingSound* sound);

#endif /* INDICATINGSOUND_H_ */
