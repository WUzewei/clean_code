#ifndef UTILS_UT
#define UTILS_UT

#include "utils.h"
#include "gtest/gtest.h"

TEST(getCourseNameTest, check_return_vaule_of_course_0)
{
    EXPECT_STREQ("Chinese", getCourseName((Course)0).c_str());
}

TEST(getClubNameTest, check_return_vaule_of_club_0)
{
    EXPECT_STREQ("reading", getClubName((Club)0).c_str());
}

#endif
