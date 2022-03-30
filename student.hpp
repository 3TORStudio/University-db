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

    std::string const getIndexNumber();
    
    void setIndexNumber(std::string indexNumber);
    
    void printStudent();
};
