#include <gtest/gtest.h>
// #include "person.hpp"
// #include "student.hpp"
// #include "employee.hpp"
#include "university.hpp"

struct UniversityTest: public ::testing::Test{
  University university{"University test"};

  std::shared_ptr<Student> person = std::make_shared<Student>(
		"a",
		"a",
		"a",
		std::make_shared<Address>("a","a","a","a"),
		"78040602656",
		"a"
	);
};

TEST_F(UniversityTest, AddPersonToEmptyPersonnelBase) {

  bool result = university.add(person);

  EXPECT_TRUE(result);
  
	int personnelBaseSize = university.getNumberOfPeople();
  EXPECT_EQ(personnelBaseSize, 1);
}