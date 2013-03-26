#include "AreaIndicator/AreaIndicator.h"
#include <stdio.h>
#include "MyTypes.h"

static Area* AreaIndicator_findIncludedArea(AreaIndicator* indicator, S32 distance);


void AreaIndicator_create(AreaIndicator* indicator, SonarSensor* sonar) {
	indicator->currentAreaCount = 0;
	indicator->sonar = sonar;
}

void AreaIndicator_addArea(AreaIndicator* indicator, Area* newArea) {
	indicator->areaList[indicator->currentAreaCount++] = newArea;
}

void AreaIndicator_indicate(AreaIndicator* indicator) {
	S32 distance = SonarSensor_getDistance(indicator->sonar);
	Area* includedArea = AreaIndicator_findIncludedArea(indicator, distance);

	if (includedArea != NULL) {
		Area_indicate(includedArea);
	}
}

Area* AreaIndicator_findIncludedArea(AreaIndicator* indicator, S32 distance) {
	int i;
	for (i = 0; i < indicator->currentAreaCount; i++) {
		Area* area = indicator->areaList[i];
		if ((area != NULL) && (Area_include(area, distance) == 1)) {
			return area;
		}
	}
	return NULL;
}
