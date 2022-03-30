#include "person.hpp"
#include "address.hpp"
#include "student.hpp"

Student::Student(std::string name,
                 std::string surname,
                 std::string PESEL,
                 std::string sex,
                 std::shared_ptr<Address> address,
                 std::string indexNumber)
                : Person(name, surname, PESEL, sex, address)
                , indexNumber_(indexNumber)
    { }

std::string const Student::getIndexNumber() { return indexNumber_; }

void Student::setIndexNumber(std::string indexNumber){indexNumber_ = indexNumber;}

void Student::printStudent(){
    std::cout << std::string(20,'-') << '\n';
    std::cout << "Index number: " << indexNumber_ << '\n';
    std::cout << std::string(20,'-') << '\n';;
    std::cout << "First name: " << getName() << '\n';
    std::cout << "Surname: " << getSurname() << '\n';
    std::cout << std::string(20,'-') << '\n';;
    std::cout << "PESEL: " << getPESEL() << '\n';
    std::cout << "Sex: " << getSex() << '\n';
    std::cout << std::string(20,'-') << '\n';;
    std::cout << "Adress:\n";
    std::cout << getAddress()->getStreet() << ' ' << getAddress()->getHouseNumber() << '\n';
    std::cout << getAddress()->getPostalCode() << ' ' << getAddress()->getTown() << '\n';
    std::cout << std::string(20,'-') << '\n';;
}

