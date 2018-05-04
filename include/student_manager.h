#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include <map>
#include <iostream>
#include "student_record.h"

using namespace std;

typedef map<uint8, Student> studentsMap;

class StudentMgr
{
private:
	studentsMap m_students;


public:
	StudentMgr();
	~StudentMgr();

	static StudentMgr& getInstance()
	{
		static StudentMgr studentMgr;
		return studentMgr;
	}

	studentsMap  getAllStudents(){return m_students;};
	//Student*  searchStudentRecord(uint8 stu_ID);
	bool searchStudentRecord(uint8 stu_ID, Student* &student);
	bool insertStudentRecord(Student*  student);
	bool updateStudentRecord(Student*  student);
	bool deleteStudentRecord(Student*  student);
	void sendEmailToFamily(string email_address);
	studentsMap getStudentsFromClub(Club club);
	studentsMap getStudentsFromClass(uint8 stu_class);
	void printAllStudentsBasicInfo();
	void printStudentBasicInfo(Student* student);
	void printStudentClubsInfo(Student* student);
	void printStudentCourseScoreInfo(Student* student);
};


#endif
