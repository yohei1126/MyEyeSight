#include "AreaIndicator/Area.h"

void Area_create(Area* area, S32 maxDistance, S32 minDistance, IndicatingSound* sound) {
	area->maxDistance = maxDistance;
	area->minDistance = minDistance;
	area->sound = sound;
}

int Area_include(Area* area, S32 distance) {
	if ((area->minDistance <= distance) && (distance <= area->maxDistance)) {
		return 1;
	} else {
		return 0;
	}
}

void Area_indicate(Area* area) {
	IndicatingSound_indicate(area->sound);
}
