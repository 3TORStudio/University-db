#pragma once
#include "address.hpp"
#include "person.hpp"

class Student: public Person {
    std::string indexNumber_;
public:
    Student (std::string name,
            std::string surname,
            std::string sex,
            std::shared_ptr<Address> address,
            std::string PESEL,
            std::string indexNumber);

    std::string  getIndexNumber() const override;

    void setIndexNumber(std::string indexNumber) override;
    
    void printPerson()  override;

    //null objects pattern
    std::string getSalary() const override {return "-1";};
    void setSalary(std::string salary) override {};

    ~Student(){};
};
