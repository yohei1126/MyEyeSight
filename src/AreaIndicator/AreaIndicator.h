#ifndef AREAINDICATOR_H_
#define AREAINDICATOR_H_

#include "AreaIndicator/Area.h"
#include "Device/ISonarSensor.h"

#define AREA_NUM_MAX 3

typedef struct _AreaIndicator {
	Area* areaList[AREA_NUM_MAX];
	int currentAreaCount;
	SonarSensor* sonar;
} AreaIndicator;

void AreaIndicator_create(AreaIndicator* indicator, SonarSensor* sonar);

void AreaIndicator_addArea(AreaIndicator* indicator, Area* newArea);

void AreaIndicator_indicate(AreaIndicator* indicator);

#endif /* AREAINDICATOR_H_ */
