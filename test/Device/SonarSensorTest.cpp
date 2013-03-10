#include "CppUTest/TestHarness.h"

extern "C" {
#include "Device/ISonarSensor.h"
#include "Device/SonarSensorStub.h"
}

TEST_GROUP(SonarSensor) {
	SonarSensor sonar;
	void setup() {
		SonarSensor_create(&sonar, SENSOR_PORT_1);
		SonarSensorStub_setDistance(&sonar, 100);
	}
	void teardown(){
	}
};

//設定したポートと一致する
TEST(SonarSensor, MatchSensorPortAfterInitialized)
{
	CHECK_EQUAL(SonarSensor_getPort(&sonar), SENSOR_PORT_1);
}

//スタブから設定した距離がが取得できる
TEST(SonarSensor, MatchDistanceAfterInitialized)
{
	CHECK_EQUAL(SonarSensor_getDistance(&sonar), 100);
}

