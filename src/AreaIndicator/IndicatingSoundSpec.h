#ifndef INDICAINGSOUNDSPEC_H_
#define INDICAINGSOUNDSPEC_H_

#define CLOSE_RANGE_DISTANCE_MIN 	((S32)0)
#define CLOSE_RANGE_DISTANCE_MAX 	((S32)30)
#define MIDDLE_RANGE_DISTANCE_MIN 	((S32)(CLOSE_RANGE_DISTANCE_MAX + 1))
#define MIDDLE_RANGE_DISTANCE_MAX 	((S32)59)
#define LONG_RANGE_DISTANCE_MIN 	((S32)(MIDDLE_RANGE_DISTANCE_MAX + 1))
#define LONG_RANGE_DISTANCE_MAX 	((S32)255) /* max distance for sonar sensor */

#endif /* INDICAINGSOUNDSPEC_H_ */