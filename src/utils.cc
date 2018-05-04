#include "utils.h"

string getCourseName(Course course)
{
	string course_name;

	switch(course)
	{
    case COURSE_CHINESE:
        course_name = "Chinese";
        break;
    case COURSE_MATH:
        course_name = "Math";
        break;
    case COURSE_ENGLISH:
        course_name = "English";
        break;
    case COURSE_PHYSICAL:
        course_name = "Physical";
        break;
    case COURSE_CHEMICAL:
        course_name = "Chemical";
        break;
    case COURSE_HISTORICAL:
        course_name = "Historical";
        break;
    case COURSE_GEOGRAPHY:
        course_name = "Geography";
        break;
    default:
        course_name = "Other";
        break;
	}	
	
	return course_name;       
}

string getClubName(Club club)
{
	string club_name;

	switch(club)
	{
    case CLUB_READING:
        club_name = "reading";
        break;
    case CLUB_DRAMA:
        club_name = "drama";
        break;
    case CLUB_MATH:
        club_name = "math";
        break;
    default:
        club_name = "other";
        break;
	}

	return club_name;
}

