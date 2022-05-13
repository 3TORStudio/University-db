#include "person.hpp"
#include "address.hpp"
#include "employee.hpp"

Employee::Employee(std::string name,
                 std::string surname,
                 std::string sex,
                 std::shared_ptr<Address> address,
                 std::string PESEL,
                 std::string salary)
                : Person(name, surname, sex, address, PESEL)
                , salary_(salary)
    { }

std::string  Employee::getSalary() const { return salary_; }

void Employee::setSalary(std::string salary){salary_ = salary;}

void  Employee::printPerson() {
    std::cout << std::string(20,'x') << '\n';
    std::cout << "First name: " << getName() << '\n';
    std::cout << "Last name: " << getSurname() << '\n';
    std::cout << "Salary: " << salary_ << '\n';
    std::cout << "PESEL: " << getPESEL() << '\n';
    std::cout << "Sex: " << getSex() << '\n';
    std::cout << "Adress:\n";
    std::cout << getAddress()->getStreet() << ' ' << getAddress()->getHouseNumber() << '\n';
    std::cout << getAddress()->getPostalCode() << ' ' << getAddress()->getTown() << '\n';
    std::cout << std::string(20,'x') << '\n';;
}

