#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H

#include <string>
#include "common_type.h"

using namespace std;

class Student
{
private:
	uint32	stu_ID;
	uint8	stu_sex;
	uint8	stu_age;
	string	stu_name;
	string	stu_family_email;
	string	stu_family_address;
	
	uint8	stu_grade;
	uint8 	stu_class;

	clubsVec 		stu_clubs;
	courseScoreMap 	stu_courseScore;
	
public:
	
	Student();

	uint8 getStudentID(){return stu_ID;};
	void  setStudentID(uint32 ID);

	uint8 getStudentSex();
	void  setStudentSex(uint8 sex);

	uint8 getStudentAge();
	void  setStudentAge(uint8 age);

	//void  getStudentName(char* &name);
	string  getStudentName(){return stu_name;};
	//void  setStudentName(char* name);
	void    setStudentName(string name);

	//void getStudentFamilyEmail(char* &family_email);
	string getStudentFamilyEmail();
	//void setStudentFamilyEmail(char* family_email);
	void   setStudentFamilyEmail(string family_email);

	//void getStudentFamilyAddress(char* &family_address);
	string getStudentFamilyAddress();
	//void setStudentFamilyAddress(char* family_address);
	void   setStudentFamilyAddress(string family_address);

	uint8 getStudentGrade(){return stu_grade;};
	void  setStudentGrade(uint8 grade);

	uint8 getStudentClass(){return stu_class;};
	void setStudentClass(uint8 class_i);

	clubsVec getStudentClubs(){return stu_clubs;};
	void setStudentClubs(clubsVec clubs);
	void addStudentClub(Club club);
	void deleteStudentClub(Club club);

	courseScoreMap	getStudentCourseScore(){return stu_courseScore;};
	void setStudentCourseScore(courseScoreMap coureScore);

};
#endif
