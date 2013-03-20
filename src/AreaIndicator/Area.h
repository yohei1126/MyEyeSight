#ifndef AREA_H_
#define AREA_H_

#include "AreaIndicator/IndicatingSound.h"

typedef struct _Area {
	S32 maxDistance;
	S32 minDistance;
	IndicatingSound* sound;
} Area;

void Area_create(Area* area, S32 maxDistance, S32 minDistance, IndicatingSound* sound);

BOOL Area_include(Area* area, S32 distance);

void Area_indicate(Area* area);

#endif /* AREA_H_ */
