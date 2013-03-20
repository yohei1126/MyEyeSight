/*
 * DeviceFactory.h
 *
 *  Created on: 2013/03/20
 *      Author: Administrator
 */

#ifndef DEVICEFACTORY_H_
#define DEVICEFACTORY_H_

#include "Device/ISonarSensor.h"

SonarSensor* DeviceFactory_getSonarSensor(void);

#endif /* DEVICEFACTORY_H_ */
