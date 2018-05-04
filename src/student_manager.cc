#include <stdio.h>
#include "utils.h"
#include "student_record.h"
#include "student_manager.h"


using namespace std;

StudentMgr::StudentMgr()
{
    m_students.clear();
}

StudentMgr::~StudentMgr()
{
	m_students.clear();
}

bool StudentMgr::searchStudentRecord(uint8 ID, Student* &student)
{
    studentsMap::iterator student_iterator = m_students.find(ID);
    if (student_iterator != m_students.end())
     {
        printf("%s: find the student ID %d\n", __FUNCTION__, ID);
        student = &student_iterator->second;
		return true;
    }

    printf("%s: not find the student ID %d\n", __FUNCTION__, ID);
	return false;
}

bool StudentMgr::insertStudentRecord(Student*  student)
{
    if (student==NULL)
    {
        printf("%s student is invalid.\n", __FUNCTION__);
        return false;
    }

    uint8 student_id = student->getStudentID();
    studentsMap::iterator student_iterator = m_students.find(student_id);
    if (student_iterator != m_students.end())
    {
        printf("%s has the same student ID %d.\n", __FUNCTION__, student_id);
        return false;
    }
    else
    {
        m_students.insert(pair<uint8, Student>(student_id,*student));
        printf("%s add student ID %d successfully.\n", __FUNCTION__, student_id);
        return true;
    }
}

bool StudentMgr::updateStudentRecord(Student*  student)
{
	if (student == NULL)
	{
		printf("%s student is invalid.\n", __FUNCTION__);
		return false;
	}
	
	uint8 student_id = student->getStudentID();
	studentsMap::iterator student_iterator = m_students.find(student_id);
	if (student_iterator != m_students.end())
	{
		m_students.erase(student_iterator);
		m_students.insert(pair<uint8, Student>(student_id,*student));
		return true;
	}
	else
	{
		printf("%s student ID %d not found.\n", __FUNCTION__, student_id);
		return false;
	}
} 

bool StudentMgr::deleteStudentRecord(Student*  student)
{
	if (student == NULL)
	{
		printf("%s student is invalid.\n", __FUNCTION__);
		return false;
	}
	
	uint8 student_id = student->getStudentID();
	studentsMap::iterator student_iterator = m_students.find(student_id);
	if (student_iterator != m_students.end())
	{
		m_students.erase(student_iterator);
		printf("%s student ID %d delete successfully.\n", __FUNCTION__, student_id);
		return true;
	}
	else
	{
		printf("%s student ID %d not found.\n", __FUNCTION__, student_id);
		return false;
	}
}

void StudentMgr::sendEmailToFamily(string email_address)
{
	printf("Send email to student's family successfully.\n");
}

studentsMap StudentMgr::getStudentsFromClass(uint8 stu_class)
{
	printf("%s %d\n", __FUNCTION__, stu_class);

	studentsMap students;
	uint8 class_id;

	studentsMap::iterator student_iterator = m_students.begin();
	for(; student_iterator != m_students.end(); student_iterator++)
	{
		class_id = student_iterator->second.getStudentClass();
		if (class_id == stu_class)
		{
			students.insert(pair<uint8, Student>(student_iterator->first, student_iterator->second));
		}		
	}
	return students;
}

void StudentMgr::printAllStudentsBasicInfo()
{
    Student student;
    printf("ID    Name      Sex     Grade Class Email               Address\n");
    
    studentsMap::iterator student_iterator = m_students.begin();
    
    for (; student_iterator != m_students.end(); student_iterator++)
    {
        student = student_iterator->second;
		printStudentBasicInfo(&student);
		
#if 0
        printf("%-6d%-10s%-8s%-6d%-6d%-20s%-30s\n ", 
           student.getStudentID(),
           student.getStudentName().c_str(),
           student.getStudentSex() == 1? "Male":"Female",
           student.getStudentGrade(),
           student.getStudentClass(),
           student.getStudentFamilyEmail().c_str(),
           student.getStudentFamilyAddress().c_str());
#endif
    }
}

void StudentMgr::printStudentBasicInfo(Student* student)
{
	//printf("ID    Name      Sex     Grade Class Email               Address\n");
	printf("%-6d%-10s%-8s%-6d%-6d%-20s%-30s\n ",
		student->getStudentID(),
		student->getStudentName().c_str(),
		student->getStudentSex() == 1? "Male":"Female",
		student->getStudentGrade(),
		student->getStudentClass(),
		student->getStudentFamilyEmail().c_str(),
		student->getStudentFamilyAddress().c_str());
}
void StudentMgr::printStudentClubsInfo(Student* student)
{
	clubsVec clubs;
	clubs = student->getStudentClubs();
	printf("Student %s hobby clubs:", student->getStudentName().c_str());
	for (uint8 i = 0; i < clubs.size(); i++)
	{
		string club_name;
		club_name = getClubName((Club)i);
		printf("%s ", club_name.c_str());
	}
	printf("\n");
}
	
void StudentMgr::printStudentCourseScoreInfo(Student* student)
{
	courseScoreMap cMap;
	cMap = student->getStudentCourseScore();
	printf("Student %s course score:\n", student->getStudentName().c_str());
	
	Course courseMax;
	if(student->getStudentGrade() <= GRADE_SIX)
		courseMax = COURSE_ENGLISH;
	else
		courseMax = COURSE_GEOGRAPHY;

	for(uint8 i = 0; i <= courseMax; i++)
	{
		string course_name;
		course_name = getCourseName((Course)i);
		printf("%-12s:%.2f\n", course_name.c_str(), cMap[(Course)i]);
	}	
}
