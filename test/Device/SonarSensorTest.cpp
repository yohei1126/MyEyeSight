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

//�ݒ肵���|�[�g�ƈ�v����
TEST(SonarSensor, MatchSensorPortAfterInitialized)
{
	CHECK_EQUAL(SonarSensor_getPort(&sonar), SENSOR_PORT_1);
}

//�X�^�u����ݒ肵�����������擾�ł���
TEST(SonarSensor, MatchDistanceAfterInitialized)
{
	CHECK_EQUAL(SonarSensor_getDistance(&sonar), 100);
}

