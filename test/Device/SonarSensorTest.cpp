#include "CppUTest/TestHarness.h"

extern "C" {
#include "Device/ISonarSensor.h"
#include "Device/SonarSensorStub.h"
}

TEST_GROUP(SonarSensor) {
	SonarSensor sonar;
	void setup() {
		SonarSensor_create(&sonar, SENSOR_PORT_1);
		SonarSensorStub_setDistance(&sonar, (S32)100);
	}
	void teardown(){
	}
};

TEST(SonarSensor, MatchSensorPortAfterInitialized)
{
	CHECK_EQUAL(SonarSensor_getPort(&sonar), SENSOR_PORT_1);
}

TEST(SonarSensor, MatchDistanceAfterInitialized)
{
	CHECK_EQUAL(SonarSensor_getDistance(&sonar), 100);
}

