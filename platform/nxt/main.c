#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "AreaIndicator/AreaIndicatorFactory.h"

#define SONAR_SENSR_PORT NXT_PORT_S3

// hook function for device initialization
// this function is initialized when nxtosek starts
void ecrobot_device_initialize()
{
	ecrobot_init_sonar_sensor(SONAR_SENSR_PORT);
}

// hook function for device termination
// this function is initialized when exis button ends.
void ecrobot_device_terminate()
{
	ecrobot_term_sonar_sensor(SONAR_SENSR_PORT);
}

// 1 msec cyclic isr
void user_1ms_isr_type2(void)
{
	// do nothing
}

TASK(TaaskInit)
{
	AreaIndicatorFactory_init();
}


TASK(TaskAreaIndicator)
{
	AreaIndicator_indicate(AreaIndicatorFactory_getAreaIndicator());
}
