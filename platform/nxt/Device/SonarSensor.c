#include "Device/ISonarSensor.h"
#include "ecrobot_interface.h"

static U8 port = NXT_PORT_S1;

void SonarSensor_create(SonarSensor* sonar, ESensorPort port) {
	//U8 port;
	switch (port) {
	case SENSOR_PORT_1:
		port = NXT_PORT_S1;
		break;
	case SENSOR_PORT_2:
		port = NXT_PORT_S2;
		break;
	case SENSOR_PORT_3:
		port = NXT_PORT_S3;
		break;
	case SENSOR_PORT_4:
		port = NXT_PORT_S4;
		break;
	default:
		port = NXT_PORT_S1;
		break;
	}
}

ESensorPort SonarSensor_getPort(SonarSensor* sonar){
	return sonar->port;
}

S32 SonarSensor_getDistance(SonarSensor* sonar) {
	return ecrobot_get_sonar_sensor(port);
}
