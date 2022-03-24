#pragma once
#include "address.hpp"
#include <string>
#include <memory>

class Student {
    std::string name_;
    std::string surname_;
    std::string indexNumber_;
    std::string PESEL_;
    std::string sex_;
    std::shared_ptr<Address> address_;
    bool isPeselCorrect(std::string);
public:
    Student (std::string name,
            std::string surname,
            std::shared_ptr<Address> address,
            std::string indexNumber,
            std::string PESEL,
            std::string sex);
    
    std::string const getName();
    std::string const getSurame();
    Address getAddress(); 
    std::string const indexNumber();
    std::string const getPESEL();
    std::string const getSex();    
};
