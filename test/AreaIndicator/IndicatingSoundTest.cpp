#include "CppUTest/TestHarness.h"
#include "MyTypes.h"
#include <memory>

extern "C" {
#include "AreaIndicator/IndicatingSound.h"
#include "Device/BuzzerStub.h"
}

TEST_GROUP(IndicatingSound) {
	U32 freq;
	U32 onInterval; // unit: 10msec
	U32 volume;
	IndicatingSound sound;
	void setup() {
		freq = 1300;
		onInterval = 10; // unit: 10msec
		volume = 10;
		IndicatingSound_create(&sound, freq, onInterval, volume);
	}
	void teardown(){
		BuzzerStub_init();
	}
};

TEST(IndicatingSound, NoIndicateAfterInitialization)
{
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), 0);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), 0);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), 0);
}

TEST(IndicatingSound, OneIndicateAfterTone)
{
	IndicatingSound_indicate(&sound);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), freq);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), onInterval);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), volume);
}

