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
	bool isNullStudentInstance(Student* student);
    Student*  searchStudentRecord(const uint8 stu_ID);
    bool insertStudentRecord(Student*  student);
    bool updateStudentRecord(Student*  student);
    bool deleteStudentRecord(Student*  student);
    void sendEmailToFamily(const string email_address);
    studentsMap getStudentsFromClub(const Club club);
    studentsMap getStudentsFromClass(const uint8 stu_class);
    void printAllStudentsBasicInfo();
    void printStudentBasicInfo(Student* const student);
    void printStudentClubsInfo(Student* const student);
    void printStudentCourseScoreInfo(Student* const student);
};


#endif
