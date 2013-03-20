#include "Device/DeviceFactory.h"

#include "Device/EPort.h"

static SonarSensor sonar;
static const ESensorPort DEFAULT_SONAR_PORT = SENSOR_PORT_1;

static void DeviceFactory_init(void) {
	SonarSensor_create(&sonar, DEFAULT_SONAR_PORT);
}

SonarSensor* DeviceFactory_getSonarSensor(void) {
	if (SonarSensor_getPort(&sonar) == SENSOR_PORT_NONE) {
		DeviceFactory_init();
	}
	return &sonar;
}
