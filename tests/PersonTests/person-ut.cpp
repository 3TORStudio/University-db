#include <gtest/gtest.h>
#include "person.hpp"
#include "address.hpp"

class SubstitutionPerson: public Person
{
public:
  SubstitutionPerson(std::string name,
          std::string surname,
          std::string sex,
          std::shared_ptr<Address> address,
          std::string PESEL)
          :Person(name, surname, sex, address, PESEL)
    { }
  ~SubstitutionPerson(){};
  
  //null object pattern
  std::string  getIndexNumber() const override {return "none";};
  void setIndexNumber(std::string indexNumber) override {}; 
  std::string getSalary() const override {return "none";};
  void setSalary(std::string salary) override {};
  void printPerson() override {};

};

struct PesonTest: public ::testing::Test
{
  SubstitutionPerson cut{"a","a","a",
		std::make_shared<Address>("a","a","a","a"),
    "78040602656"
  };
};

TEST_F(PesonTest, CanGetName){
  EXPECT_EQ(cut.getName(), "a");
}
TEST_F(PesonTest, CanSettName){
  cut.setName("b");
  EXPECT_EQ(cut.getName(), "b");
}

TEST_F(PesonTest, CanGetSurname){
  EXPECT_EQ(cut.getSurname(), "a");
}
TEST_F(PesonTest, CanSetSurname){
  cut.setSurname("b");
  EXPECT_EQ(cut.getSurname(), "b");
}

TEST_F(PesonTest, CanGetSex){
  EXPECT_EQ(cut.getSex(), "a");
}
TEST_F(PesonTest, CanSetSex){
  cut.setSex("b");
  EXPECT_EQ(cut.getSex(), "b");
}

TEST_F(PesonTest, CanGetAddress){
  auto address = cut.getAddress();
  EXPECT_EQ(address->getTown(), "a");
  EXPECT_EQ(address->getHouseNumber(), "a");
  EXPECT_EQ(address->getPostalCode(), "a");
  EXPECT_EQ(address->getTown(), "a");
}

TEST_F(PesonTest, CanSetAddress){
  auto newAddress = std::make_shared<Address>("b","b","b","b");
  cut.setAddress(newAddress);
  auto address = cut.getAddress(); 
  EXPECT_EQ(address->getTown(), "b");
  EXPECT_EQ(address->getHouseNumber(), "b");
  EXPECT_EQ(address->getPostalCode(), "b");
  EXPECT_EQ(address->getTown(), "b");
}

TEST_F(PesonTest, CanGetPESEL){
  EXPECT_EQ(cut.getPESEL(), "78040602656");
}
TEST_F(PesonTest, CanSetPESEL){
  cut.setPESEL("b");
  EXPECT_EQ(cut.getPESEL(), "00000000000");
}

TEST_F(PesonTest, CheckigCorrectNumberOfDigits){
  SubstitutionPerson p{"a","a","a",
  std::make_shared<Address>("a","a","a","a"),"111111111"};
  EXPECT_EQ(p.getPESEL(),"00000000000");
}

TEST_F(PesonTest, CheckigIfPeselContainsOnlyDigits){
  SubstitutionPerson p{"a","a","a",
  std::make_shared<Address>("a","a","a","a"),"111111111aa"};
  EXPECT_EQ(p.getPESEL(),"00000000000");
}

TEST_F(PesonTest, CheckigControlNumber){
  SubstitutionPerson p{"a","a","a",
  std::make_shared<Address>("a","a","a","a"),"11111111111"};
  EXPECT_EQ(p.getPESEL(),"00000000000");
  EXPECT_EQ(cut.getPESEL(),"78040602656");
}