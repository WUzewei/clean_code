#include "student_record.h"

Student::Student()
{
    stu_ID = 0;
    stu_grade = 0;
    stu_class = 0;	
    stu_clubs.clear();
    stu_courseScore.clear();
}


void Student::setStudentID(uint32 ID)
{
    stu_ID = ID;
}

uint8 Student::getStudentGender() const
{
    return stu_sex;
}

void Student::setStudentGender(uint8 sex)
{
    stu_sex = sex;
}


uint8 Student::getStudentAge() const
{
    return stu_age;
}

void Student::setStudentAge(uint8 age)
{
    stu_age = age;
}

void Student::setStudentName(string name)
{
    stu_name = name;
}

string Student::getStudentFamilyAddress() const
{
    return stu_family_address;
}

void Student::setStudentFamilyAddress(string family_address)
{
    stu_family_address = family_address;
}

string Student::getStudentFamilyEmail() const
{
    return stu_family_email;
}

void Student::setStudentFamilyEmail(string family_email)
{
    stu_family_email = family_email;
}

void Student::setStudentGrade(uint8 grade)
{
    stu_grade = grade;
}

void Student::setStudentClass(uint8 class_i)
{
    stu_class = class_i;
}

void Student::setStudentClubs(clubsVec clubs)
{
    stu_clubs = clubs;
}

void Student::addStudentClub(Club club)
{
    stu_clubs.push_back(club);
}

void Student::deleteStudentClub(Club club)
{
    clubsVec::iterator it = stu_clubs.begin();
    for (; it != stu_clubs.end(); it ++)
    {
        if ((*it) == club)
        {
            stu_clubs.erase(it);
            break;
        }
    }
}

void Student::setStudentCourseScore(courseScoreMap courseScore)
{
    stu_courseScore = courseScore;
}

