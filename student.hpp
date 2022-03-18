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
    bool isPeselCorrect(std::string);
public:
    Student (std::string, std::string, std::string,
             std::string, std::string, std::string,
             std::string, std::string, std::string);
    
    std::string const getName();
    std::string const getSurame();
    struct addres getAddress(); 
    std::string const indexNumber();
    std::string const getPESEL();
    std::string const getSex();    
};
