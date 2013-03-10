#include "Device/ISonarSensor.h"
#include "Device/EPort.h"

void SonarSensor_create(SonarSensor* sonar, ESensorPort port) {
	sonar->port = port;
}

ESensorPort SonarSensor_getPort(SonarSensor* sonar){
	return sonar->port;
}

S32 SonarSensor_getDistance(SonarSensor* sonar) {
	return sonar->distance;
}

void SonarSensorStub_setDistance(SonarSensor* sonar, S32 distance) {
	sonar->distance = distance;
}
