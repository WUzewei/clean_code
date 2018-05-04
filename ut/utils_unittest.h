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

#if 0
int main(int argc, char** argv)
{
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}
#endif
