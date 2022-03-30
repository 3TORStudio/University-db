#pragma once
#include "address.hpp"
#include <algorithm>
#include <memory>
#include <iostream>
#include <string>

class Person{
    std::string name_;
    std::string PESEL_;
    std::string surname_;
    std::string sex_;
    std::shared_ptr<Address> address_;
protected:
    static bool isPeselCorrect(std::string);
public:
    Person(std::string name,
            std::string surname,
            std::string sex,
            std::shared_ptr<Address> address,
            std::string PESEL);
    
    std::string const getName();
    std::string const getSurname();
    std::shared_ptr<Address> getAddress(); 
    std::string const getPESEL();
    std::string const getSex();    

    void setName(std::string name);
    void setSurname(std::string surname);
    void setPESEL(std::string PESEL);
    void setSex(std::string sex);
    void setAddress(std::shared_ptr<Address> address);
};