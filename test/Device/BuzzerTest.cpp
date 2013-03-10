#include "CppUTest/TestHarness.h"
#include "include/MyTypes.h"

extern "C" {
#include "Device/IBuzzer.h"
#include "Device/BuzzerStub.h"
}



TEST_GROUP(Buzzer) {
	U32 freq;
	U32 onInterval; // unit: 10msec
	U32 volume;
	void setup() {
		freq = 1300;
		onInterval = 10; // unit: 10msec
		volume = 10;
	}
	void teardown(){
	}
};

//ƒuƒU[‚ğ–Â‚ç‚µ‚½Œã‚ÉŒ‹‰Ê‚ğæ“¾‚·‚é
TEST(Buzzer, GetParameterAfterTone)
{
	Buzzer_tone(freq, onInterval, volume);
	CHECK_EQUAL(BuzzerStub_getLastFrequency(), freq);
	CHECK_EQUAL(BuzzerStub_getLastOnInterval(), onInterval);
	CHECK_EQUAL(BuzzerStub_getLastVolume(), volume);
}

