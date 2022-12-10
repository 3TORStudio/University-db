#include <gtest/gtest.h>
#include "employee.hpp"

struct  StudentTest: public ::testing::Test
{
	Employee cut{
		"a",
		"a",
		"a",
		std::make_shared<Address>("a","a","a","a"),
		"78040602656",
		"a"};
};

TEST_F(StudentTest, CanGetSalary){
	EXPECT_EQ(cut.getSalary(),"a");
}
TEST_F(StudentTest, CanSetSalary){
	cut.setSalary("b");
	EXPECT_EQ(cut.getSalary(),"b");
}