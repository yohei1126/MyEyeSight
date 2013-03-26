#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "AreaIndicator/AreaIndicatorFactory.h"

#define SONAR_SENSR_PORT NXT_PORT_S3

// デバイス初期化用フック関数
// この関数はnxtOSEK起動時に実行されます。
void ecrobot_device_initialize()
{
	ecrobot_init_sonar_sensor(SONAR_SENSR_PORT);
}

// デバイス終了用フック関数
// この関数はSTOPまたはEXITボタンが押された時に実行されます。
void ecrobot_device_terminate()
{
	ecrobot_term_sonar_sensor(SONAR_SENSR_PORT);
}

// 1msec周期割り込み(ISRカテゴリ2)から起動されるユーザー用フック関数
void user_1ms_isr_type2(void)
{
	// 今回は何も行わない
}

TASK(TaaskInit)
{
	//DeviceFactoryの初期化は不要;
	AreaIndicatorFactory_init();
}


TASK(TaskAreaIndicator)
{
	AreaIndicator_indicate(AreaIndicatorFactory_getAreaIndicator());
}
