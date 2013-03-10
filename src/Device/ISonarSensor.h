#ifndef DEVICE_ISONAR_SENSOR_H
#define DEVICE_ISONAR_SENSOR_H

#include "Device/EPort.h"
#include "include/MyTypes.h"

/*SonarSensor�̑�����`*/
typedef struct SonarSensor {
	ESensorPort port;
	S32 distance;
} SonarSensor;


/*SonarSensor������������*/
void SonarSensor_create(SonarSensor* sonar, ESensorPort port);
/*SonarSensor�̃|�[�g���擾����*/
ESensorPort SonarSensor_getPort(SonarSensor* sonar);
/*SonarSensor���狗�����擾����*/
S32 SonarSensor_getDistance(SonarSensor* sonar);

#endif
