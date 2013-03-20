#include "CppUTest/TestHarness.h"
#include "MyTypes.h"

extern "C" {
#include "AreaIndicator/Area.h"
}

TEST_GROUP(Area) {
	Area middleRangeArea;

	IndicatingSound middleFreqSound;

	static const U32 MIDDLE_RANGE_DISTANCE_MIN = 31;
	static const U32 MIDDLE_RANGE_DISTANCE_MAX = 59;

	void setup() {
		Area_create(&middleRangeArea, MIDDLE_RANGE_DISTANCE_MAX, MIDDLE_RANGE_DISTANCE_MIN, &middleFreqSound);
	}
	void teardown(){
	}
};

TEST(Area, DistanceIncludeBetweenMaxAndMin)
{
	CHECK_EQUAL(Area_include(&middleRangeArea, MIDDLE_RANGE_DISTANCE_MIN-1), FALSE);
	CHECK_EQUAL(Area_include(&middleRangeArea, MIDDLE_RANGE_DISTANCE_MIN), TRUE);
	CHECK_EQUAL(Area_include(&middleRangeArea, MIDDLE_RANGE_DISTANCE_MAX), TRUE);
	CHECK_EQUAL(Area_include(&middleRangeArea, MIDDLE_RANGE_DISTANCE_MAX+1), FALSE);
}
