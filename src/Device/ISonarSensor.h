#ifndef DEVICE_ISONAR_SENSOR_H
#define DEVICE_ISONAR_SENSOR_H

#include "Device/EPort.h"
#include "include/MyTypes.h"

/*SonarSensorの属性定義*/
typedef struct SonarSensor {
	ESensorPort port;
	S32 distance;
} SonarSensor;


/*SonarSensorを初期化する*/
void SonarSensor_create(SonarSensor* sonar, ESensorPort port);
/*SonarSensorのポートを取得する*/
ESensorPort SonarSensor_getPort(SonarSensor* sonar);
/*SonarSensorから距離を取得する*/
S32 SonarSensor_getDistance(SonarSensor* sonar);

#endif
