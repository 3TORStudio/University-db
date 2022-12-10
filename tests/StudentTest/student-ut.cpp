#include <gtest/gtest.h>
#include "student.hpp"

struct  StudentTest: public ::testing::Test
{
	Student cut{
		"a",
		"a",
		"a",
		std::make_shared<Address>("a","a","a","a"),
		"78040602656",
		"a"};
};

TEST_F(StudentTest, CanGetIndexNumber){
	EXPECT_EQ(cut.getIndexNumber(),"a");
}
TEST_F(StudentTest, CanSetIndexNumber){
	cut.setIndexNumber("b");
	EXPECT_EQ(cut.getIndexNumber(),"b");
}