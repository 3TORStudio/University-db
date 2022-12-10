#include <gtest/gtest.h>
#include "address.hpp"

struct AddressTest: public ::testing::Test
{
	Address cut{"Wolnosci","12/3","76-200","Slupsk"};
};

TEST_F(AddressTest,CanGetStreetCorrectly){
	EXPECT_EQ(cut.getStreet(),"Wolnosci");
}
TEST_F(AddressTest,CanGetHouseNumberCorrectly){
	EXPECT_EQ(cut.getHouseNumber(),"12/3");
}
TEST_F(AddressTest,CanGetPostalCodeCorrectly){
	EXPECT_EQ(cut.getPostalCode(),"76-200");
}
TEST_F(AddressTest,CanGetTownCorrectly){
	EXPECT_EQ(cut.getTown(),"Slupsk");
}