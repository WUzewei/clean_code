#ifndef COMMON_TYPE_H_
#define COMMON_TYPE_H_

#include <map>
#include <vector>

using namespace std;

typedef unsigned char uint8;
typedef unsigned int  uint32;

typedef enum{
	CLUB_READING,
	CLUB_DRAMA,
	CLUB_MATH
}Club;

typedef enum{
	GRADE_ONE = 1,
	GRADE_TWO,
	GRADE_THREE,
	GRADE_FOUR,
	GRADE_FIVE,
	GRADE_SIX,
	GRADE_SEVEN,
	GRADE_EIGHT,
	GRADE_NINE
}Grade;

typedef enum{
	COURSE_CHINESE = 0,
	COURSE_MATH,
	COURSE_ENGLISH,
	COURSE_PHYSICAL,
	COURSE_CHEMICAL,
	COURSE_HISTORICAL,
	COURSE_GEOGRAPHY
}Course;

typedef vector<Club> clubsVec;
typedef map<Course, float> courseScoreMap;

#endif

