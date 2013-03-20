#include "CppUTest/TestHarness.h"
#include "MyTypes.h"
#include <memory>

extern "C" {
#include "AreaIndicator/AreaIndicator.h"
#include "AreaIndicator/Area.h"
#include "AreaIndicator/IndicatingSound.h"
#include "Device/ISonarSensor.h"
#include "Device/BuzzerStub.h"
#include "Device/SonarSensorStub.h"
}

TEST_GROUP(AreaIndicator) {
	AreaIndicator indicator;
	Area closeRangeArea;
	Area middleRangeArea;
	Area longRangeArea;

	IndicatingSound highFreqSound;
	IndicatingSound middleFreqSound;
	IndicatingSound lowFreqSound;

	static const S32 CLOSE_RANGE_DISTANCE_MIN = 0;
	static const S32 CLOSE_RANGE_DISTANCE_MAX = 30;
	static const S32 MIDDLE_RANGE_DISTANCE_MIN = CLOSE_RANGE_DISTANCE_MAX + 1;
	static const S32 MIDDLE_RANGE_DISTANCE_MAX = 59;
	static const S32 LONG_RANGE_DISTANCE_MIN = MIDDLE_RANGE_DISTANCE_MAX + 1;
	static const S32 LONG_RANGE_DISTANCE_MAX = 255; // max distance for sonar sensor
	SonarSensor sonar;

	void setup() {
		IndicatingSound_create(&highFreqSound, HIGH_FREQUENCY, DEFAULT_ON_INTERVAL, DEFAULT_VOLUME);
		Area_create(&closeRangeArea, CLOSE_RANGE_DISTANCE_MAX, CLOSE_RANGE_DISTANCE_MIN, &highFreqSound);

		IndicatingSound_create(&middleFreqSound, MIDDLE_FREQUENCY, DEFAULT_ON_INTERVAL, DEFAULT_VOLUME);
		Area_create(&middleRangeArea, MIDDLE_RANGE_DISTANCE_MAX, MIDDLE_RANGE_DISTANCE_MIN, &middleFreqSound);

		IndicatingSound_create(&lowFreqSound, LOW_FREQUENCY, DEFAULT_ON_INTERVAL, DEFAULT_VOLUME);
		Area_create(&longRangeArea, LONG_RANGE_DISTANCE_MAX, LONG_RANGE_DISTANCE_MIN, &lowFreqSound);

		SonarSensor_create(&sonar, SENSOR_PORT_1);
		AreaIndicator_create(&indicator, &sonar);
		AreaIndicator_addArea(&indicator, &closeRangeArea);
		AreaIndicator_addArea(&indicator, &middleRangeArea);
		AreaIndicator_addArea(&indicator, &longRangeArea);
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
	SonarSensorStub_setDistance(&sonar, CLOSE_RANGE_DISTANCE_MIN);
	AreaIndicator_indicate(&indicator);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), HIGH_FREQUENCY);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), DEFAULT_ON_INTERVAL);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), DEFAULT_VOLUME);
}

TEST(AreaIndicator, CloseRangeDistanceThenHighVolumeTone2)
{
	SonarSensorStub_setDistance(&sonar, CLOSE_RANGE_DISTANCE_MAX);
	AreaIndicator_indicate(&indicator);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), HIGH_FREQUENCY);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), DEFAULT_ON_INTERVAL);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), DEFAULT_VOLUME);
}

TEST(AreaIndicator, MiddleRangeDistanceThenMiddleVolumeTone1)
{
	SonarSensorStub_setDistance(&sonar, MIDDLE_RANGE_DISTANCE_MIN);
	AreaIndicator_indicate(&indicator);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), MIDDLE_FREQUENCY);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), DEFAULT_ON_INTERVAL);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), DEFAULT_VOLUME);
}

TEST(AreaIndicator, MiddleRangeDistanceThenMiddleVolumeTone2)
{
	SonarSensorStub_setDistance(&sonar, MIDDLE_RANGE_DISTANCE_MAX);
	AreaIndicator_indicate(&indicator);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), MIDDLE_FREQUENCY);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), DEFAULT_ON_INTERVAL);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), DEFAULT_VOLUME);
}

TEST(AreaIndicator, LongRangeDistanceThenLowVolumeTone1)
{
	SonarSensorStub_setDistance(&sonar, LONG_RANGE_DISTANCE_MIN);
	AreaIndicator_indicate(&indicator);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), LOW_FREQUENCY);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), DEFAULT_ON_INTERVAL);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), DEFAULT_VOLUME);
}

TEST(AreaIndicator, LongRangeDistanceThenLowVolumeTone2)
{
	SonarSensorStub_setDistance(&sonar, LONG_RANGE_DISTANCE_MAX);
	AreaIndicator_indicate(&indicator);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), LOW_FREQUENCY);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), DEFAULT_ON_INTERVAL);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), DEFAULT_VOLUME);
}
