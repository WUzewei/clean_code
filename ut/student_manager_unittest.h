#ifndef STUDENT_MANAGER_UT
#define STUDENT_MANAGER_UT

#include "student_record.h"
#include "student_manager.h"
#include "gtest/gtest.h"

class StudentMgrTest : public ::testing::Test
{
protected:
    static void SetUpTestCase(){};
    static void TearDownTestCase(){};
    Student *s1 = new Student();
    Student *s2 = new Student();
    Student *s3 = new Student();
    Student *s4 = new Student();
};

TEST_F(StudentMgrTest, insertNewStudent)
{
    s1->setStudentID(110);
    s1->setStudentName("Alice");
    s1->setStudentGender(FEMALE);
    s1->setStudentAge(18);
    s1->setStudentGrade(GRADE_FIVE);
    s1->setStudentClass(119);
    s1->setStudentFamilyEmail("alice@nokia.com");
    s1->setStudentFamilyAddress("qingdao");

    clubsVec clubs;
    clubs.push_back(CLUB_READING);
    clubs.push_back(CLUB_DRAMA);
    s1->setStudentClubs(clubs);

    courseScoreMap courseScore;
    courseScore.insert(pair<Course, float>(COURSE_CHINESE, 99.99));
    courseScore.insert(pair<Course, float>(COURSE_MATH, 89.99));
    courseScore.insert(pair<Course, float>(COURSE_ENGLISH, 79.99));
    s1->setStudentCourseScore(courseScore);

    EXPECT_TRUE(StudentMgr::getInstance().insertStudentRecord(s1));

    s2->setStudentID(111);
    s2->setStudentName("Bob");
    s2->setStudentGender(MALE);
    s2->setStudentAge(19);
    s2->setStudentGrade(GRADE_FIVE);
    s2->setStudentClass(119);
    s2->setStudentFamilyEmail("Bob@nokia.com");
    s2->setStudentFamilyAddress("beijing");
    clubs.push_back(CLUB_MATH);
    s2->setStudentClubs(clubs);
    courseScore.clear();
    courseScore.insert(pair<Course, float>(COURSE_CHINESE, 100));
    courseScore.insert(pair<Course, float>(COURSE_MATH, 99));
    courseScore.insert(pair<Course, float>(COURSE_ENGLISH, 79));
    s2->setStudentCourseScore(courseScore);
    EXPECT_TRUE(StudentMgr::getInstance().insertStudentRecord(s2));

    s3->setStudentID(112);
    s3->setStudentName("Charis");
    s3->setStudentGender(FEMALE);
    s3->setStudentAge(19);
    s3->setStudentGrade(GRADE_NINE);
    s3->setStudentClass(118);
    s3->setStudentFamilyEmail("Charis@nokia.com");
    s3->setStudentFamilyAddress("shanghai");
    clubs.pop_back();
    s3->setStudentClubs(clubs);
    courseScore.clear();
    courseScore.insert(pair<Course, float>(COURSE_CHINESE, 99.99));
    courseScore.insert(pair<Course, float>(COURSE_MATH, 89.99));
    courseScore.insert(pair<Course, float>(COURSE_ENGLISH, 79.99));
    courseScore.insert(pair<Course, float>(COURSE_PHYSICAL, 120));
    courseScore.insert(pair<Course, float>(COURSE_CHEMICAL,100));
    courseScore.insert(pair<Course, float>(COURSE_HISTORICAL, 150));
    courseScore.insert(pair<Course, float>(COURSE_GEOGRAPHY, 110));
    s3->setStudentCourseScore(courseScore);
    EXPECT_TRUE(StudentMgr::getInstance().insertStudentRecord(s3));

    EXPECT_EQ(3, StudentMgr::getInstance().getAllStudents().size());
}

TEST_F(StudentMgrTest, searchStudent)
{
    uint32 student_id = 110;
    s4 = StudentMgr::getInstance().searchStudentRecord(student_id);
    EXPECT_STREQ("Alice", s4->getStudentName().c_str());

    student_id = 0;
    s4 = StudentMgr::getInstance().searchStudentRecord(student_id);
	EXPECT_TRUE(StudentMgr::getInstance().isNullStudentInstance(s4));
}

TEST_F(StudentMgrTest, updateStudent)
{
    string new_email = "zhangs@nokia-sbell.com";
    uint32 student_id = 110;
    s1 = StudentMgr::getInstance().searchStudentRecord(student_id);

    s1->setStudentFamilyEmail(new_email);
    EXPECT_TRUE(StudentMgr::getInstance().updateStudentRecord(s1));
    EXPECT_STREQ(new_email.c_str(), s1->getStudentFamilyEmail().c_str());
}

TEST_F(StudentMgrTest, getStudentsFromClass)
{
    uint8 class_id = 119;
    studentsMap students= StudentMgr::getInstance().getStudentsFromClass(class_id);

    EXPECT_EQ(2, students.size());
}

TEST_F(StudentMgrTest, getStudentsFromClub)
{
    Club club = CLUB_READING;
    studentsMap students= StudentMgr::getInstance().getStudentsFromClub(club);

    EXPECT_EQ(3, students.size());
}

#endif
