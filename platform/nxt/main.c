#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "AreaIndicator/AreaIndicatorFactory.h"

#define SONAR_SENSR_PORT NXT_PORT_S3

// �f�o�C�X�������p�t�b�N�֐�
// ���̊֐���nxtOSEK�N�����Ɏ��s����܂��B
void ecrobot_device_initialize()
{
	ecrobot_init_sonar_sensor(SONAR_SENSR_PORT);
}

// �f�o�C�X�I���p�t�b�N�֐�
// ���̊֐���STOP�܂���EXIT�{�^���������ꂽ���Ɏ��s����܂��B
void ecrobot_device_terminate()
{
	ecrobot_term_sonar_sensor(SONAR_SENSR_PORT);
}

// 1msec�������荞��(ISR�J�e�S��2)����N������郆�[�U�[�p�t�b�N�֐�
void user_1ms_isr_type2(void)
{
	// ����͉����s��Ȃ�
}

TASK(TaaskInit)
{
	//DeviceFactory�̏������͕s�v;
	AreaIndicatorFactory_init();
}


TASK(TaskAreaIndicator)
{
	AreaIndicator_indicate(AreaIndicatorFactory_getAreaIndicator());
}
