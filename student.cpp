#include "student.hpp"
#include <iostream>
//#include "address.hpp"

Student::Student(std::string name,
                 std::string surname,
                 std::shared_ptr<Address> addres,
                 std::string indexNumber,
                 std::string PESEL,
                 std::string sex)
    : name_(name), surname_(surname), indexNumber_(indexNumber), PESEL_(PESEL), sex_(sex), address_(addres)
{
}

std::string const Student::getName() { return name_; }
std::string const Student::getSurame() { return surname_; }
std::shared_ptr<Address> Student::getAddress() { return address_; }
std::string const Student::indexNumber() { return indexNumber_; }
std::string const Student::getPESEL() { return PESEL_; }
std::string const Student::getSex() { return sex_; }

void Student::setName(std::string name){name_ = name;}
void Student::setSurname(std::string surname){surname_ = surname;}
void Student::setIndexNumber(std::string indexNumber){indexNumber_ = indexNumber;}
void Student::setPESEL(std::string PESEL){PESEL_ = PESEL;}
void Student::setSex(std::string sex){sex_ = sex;}
void Student::setAddress(std::shared_ptr<Address> address){address_ = address;}

void Student::printStudent(){
    std::cout << std::string(20,'-') << '\n';
    std::cout << "Index number: " << indexNumber_ << '\n';
    std::cout << std::string(20,'-') << '\n';;
    std::cout << "First name: " << name_ << '\n';
    std::cout << "Surname: " << surname_ << '\n';
    std::cout << std::string(20,'-') << '\n';;
    std::cout << "PESEL: " << PESEL_ << '\n';
    std::cout << "Sex: " << sex_ << '\n';
    std::cout << std::string(20,'-') << '\n';;
    std::cout << "Adress:\n";
    std::cout << address_->getStreet() << ' ' << address_->getHouseNumber() << '\n';
    std::cout << address_->getPostalCode() << ' ' << address_->getTown() << '\n';
    std::cout << std::string(20,'-') << '\n';;
}