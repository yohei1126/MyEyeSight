#include "Device/ISonarSensor.h"
#include "ecrobot_interface.h"

void SonarSensor_create(SonarSensor* sonar, ESensorPort port) {
	//U8 port;
	switch (port) {
	case SENSOR_PORT_1:
	case SENSOR_PORT_2:
	case SENSOR_PORT_3:
	case SENSOR_PORT_4:

	}
	//ecrobot_init_sonar_sensor(U8 port_id)
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
