#include "AreaIndicator/AreaIndicatorFactory.h"
#include "AreaIndicator/AreaIndicator.h"
#include "AreaIndicator/Area.h"
#include "AreaIndicator/IndicatingSound.h"
#include "AreaIndicator/IndicatingSoundSpec.h"
#include "Device/DeviceFactory.h"

static AreaIndicator indicator;
static Area closeRangeArea;
static Area middleRangeArea;
static Area longRangeArea;

static IndicatingSound highFreqSound;
static IndicatingSound middleFreqSound;
static IndicatingSound lowFreqSound;

void AreaIndicatorFactory_init(void) {
	IndicatingSound_create(&highFreqSound, HIGH_FREQUENCY, DEFAULT_ON_INTERVAL, DEFAULT_VOLUME);
	Area_create(&closeRangeArea, CLOSE_RANGE_DISTANCE_MAX, CLOSE_RANGE_DISTANCE_MIN, &highFreqSound);

	IndicatingSound_create(&middleFreqSound, MIDDLE_FREQUENCY, DEFAULT_ON_INTERVAL, DEFAULT_VOLUME);
	Area_create(&middleRangeArea, MIDDLE_RANGE_DISTANCE_MAX, MIDDLE_RANGE_DISTANCE_MIN, &middleFreqSound);

	IndicatingSound_create(&lowFreqSound, LOW_FREQUENCY, DEFAULT_ON_INTERVAL, DEFAULT_VOLUME);
	Area_create(&longRangeArea, LONG_RANGE_DISTANCE_MAX, LONG_RANGE_DISTANCE_MIN, &lowFreqSound);

	AreaIndicator_create(&indicator, DeviceFactory_getSonarSensor());
	AreaIndicator_addArea(&indicator, &closeRangeArea);
	AreaIndicator_addArea(&indicator, &middleRangeArea);
	AreaIndicator_addArea(&indicator, &longRangeArea);
}

AreaIndicator* AreaIndicatorFactory_getAreaIndicator(void) {
	return &indicator;
}

