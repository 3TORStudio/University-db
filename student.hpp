#pragma once

#include <string>
class Student{
    std::string name;
    std::string surname;
    struct address 
    {
        std::string street;
        std::string houseNumber;
        std::string postalCode;
        std::string town;
    };
    std::string indexNumber;
    std::string PESEL;
    std::string sex;
public:
    Student add(Student);
    
};