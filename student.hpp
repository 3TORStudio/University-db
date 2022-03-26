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
    static bool isPeselCorrect(std::string);
public:
    Student (std::string name,
            std::string surname,
            std::shared_ptr<Address> address,
            std::string indexNumber,
            std::string PESEL,
            std::string sex);
    
    std::string const getName();
    std::string const getSurname();
    std::shared_ptr<Address> getAddress(); 
    std::string const getIndexNumber();
    std::string const getPESEL();
    std::string const getSex();    

    void setName(std::string name);
    void setSurname(std::string surname);
    void setIndexNumber(std::string indexNumber);
    void setPESEL(std::string PESEL);
    void setSex(std::string sex);
    void setAddress(std::shared_ptr<Address> address);

    void printStudent();
};
