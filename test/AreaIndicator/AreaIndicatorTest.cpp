#include "CppUTest/TestHarness.h"
#include "MyTypes.h"
#include <memory>

extern "C" {
#include "AreaIndicator/AreaIndicatorFactory.h"
#include "AreaIndicator/AreaIndicator.h"
#include "AreaIndicator/Area.h"
#include "AreaIndicator/IndicatingSound.h"
#include "AreaIndicator/IndicatingSoundSpec.h"
#include "Device/DeviceFactory.h"
#include "Device/ISonarSensor.h"
#include "Device/BuzzerStub.h"
#include "Device/SonarSensorStub.h"
}

TEST_GROUP(AreaIndicator) {

	SonarSensor* sonar;
	AreaIndicator* indicator;

	void setup() {
		AreaIndicatorFactory_init();
		sonar = DeviceFactory_getSonarSensor();
		indicator = AreaIndicatorFactory_getAreaIndicator();
	}
	void teardown(){
		BuzzerStub_init();
	}
};

TEST(AreaIndicator, NoIndicateAfterInitialization)
{
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), 0);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), 0);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), 0);
}

TEST(AreaIndicator, CloseRangeDistanceThenHighVolumeTone1)
{
	SonarSensorStub_setDistance(sonar, CLOSE_RANGE_DISTANCE_MIN);
	AreaIndicator_indicate(indicator);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), HIGH_FREQUENCY);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), DEFAULT_ON_INTERVAL);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), DEFAULT_VOLUME);
}

TEST(AreaIndicator, CloseRangeDistanceThenHighVolumeTone2)
{
	SonarSensorStub_setDistance(sonar, CLOSE_RANGE_DISTANCE_MAX);
	AreaIndicator_indicate(indicator);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), HIGH_FREQUENCY);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), DEFAULT_ON_INTERVAL);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), DEFAULT_VOLUME);
}

TEST(AreaIndicator, MiddleRangeDistanceThenMiddleVolumeTone1)
{
	SonarSensorStub_setDistance(sonar, MIDDLE_RANGE_DISTANCE_MIN);
	AreaIndicator_indicate(indicator);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), MIDDLE_FREQUENCY);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), DEFAULT_ON_INTERVAL);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), DEFAULT_VOLUME);
}

TEST(AreaIndicator, MiddleRangeDistanceThenMiddleVolumeTone2)
{
	SonarSensorStub_setDistance(sonar, MIDDLE_RANGE_DISTANCE_MAX);
	AreaIndicator_indicate(indicator);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), MIDDLE_FREQUENCY);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), DEFAULT_ON_INTERVAL);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), DEFAULT_VOLUME);
}

TEST(AreaIndicator, LongRangeDistanceThenLowVolumeTone1)
{
	SonarSensorStub_setDistance(sonar, LONG_RANGE_DISTANCE_MIN);
	AreaIndicator_indicate(indicator);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), LOW_FREQUENCY);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), DEFAULT_ON_INTERVAL);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), DEFAULT_VOLUME);
}

TEST(AreaIndicator, LongRangeDistanceThenLowVolumeTone2)
{
	SonarSensorStub_setDistance(sonar, LONG_RANGE_DISTANCE_MAX);
	AreaIndicator_indicate(indicator);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), LOW_FREQUENCY);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), DEFAULT_ON_INTERVAL);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), DEFAULT_VOLUME);
}
