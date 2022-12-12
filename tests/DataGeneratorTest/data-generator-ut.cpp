#include <algorithm>
#include <gtest/gtest.h>
#include "data-generator.hpp"

TEST(genSex,doesGenSexReturnStringForM){
	DataGenerator dg{};
	std::string s = dg.generateSex();
	EXPECT_EQ(s.size(),1);
}
//----------------------------------------------
struct peselGenerator: public ::testing::Test{
	DataGenerator dg{};
	std::string s = dg.generatePesel("F");
};

TEST_F(peselGenerator,doesPESELcontain11digits){
	EXPECT_EQ(s.size(),11);
}

TEST_F(peselGenerator,doesPESELcontainOnlyDigits){
	auto a = std::all_of(begin(s),end(s),isdigit);
	EXPECT_TRUE(a);
}

TEST_F(peselGenerator,doesPESELcontainEvenNumberInCaseFemale){
	int genderNum = (s[9] - 48) % 2;
	if(genderNum){
		EXPECT_NE(genderNum,0);
	}
	else{
		EXPECT_EQ(genderNum,0);
	}
}

TEST_F(peselGenerator,doesPESELcontainRightFirstDigitOfMonth){
	int firstDigitOfMonth = (s[2] - 48);
	EXPECT_LT(firstDigitOfMonth,4);
}

TEST_F(peselGenerator,doesPESELcontainRightSecondDigitOfMonth){
	int firstDigitOfMonth = (s[2] - 48);
	int secondDigitOfMonth = (s[3] - 48);
	if(firstDigitOfMonth == 1 or firstDigitOfMonth == 3){
		EXPECT_LT(secondDigitOfMonth,3);
	}
	else{
		EXPECT_GT(secondDigitOfMonth,0);
	}
}