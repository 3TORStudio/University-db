#pragma once
#include "address.hpp"
#include "person.hpp"

class Employee: public Person {
    std::string salary_;
public:
    Employee (std::string name,
            std::string surname,
            std::string sex,
            std::shared_ptr<Address> address,
            std::string PESEL,
            std::string salary);

    std::string getSalary() const override;
    void setSalary(std::string salary) override;
    void printPerson() override;

    //null objects pattern
    std::string  getIndexNumber() const override {return "none";};
    void setIndexNumber(std::string indexNumber) override {}; 

    ~Employee(){};
};
