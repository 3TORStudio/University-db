#pragma once
#include "address.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <memory>
#include <string>

class Person{
   std::string name_;
   std::string surname_;
   std::string PESEL_;
   std::string sex_;
   std::shared_ptr<Address> address_;
   std::string salary_;
protected:
   static bool isPeselCorrect(std::string);
public:
   Person(std::string name,
          std::string surname,
          std::string PESEL,
          std::string sex,
          std::shared_ptr<Address> address);
   std::string const getName();
   std::string const getSurname();
   std::string const getSalary();
   std::shared_ptr<Address> getAddress(); 
   
   std::string const getPESEL();
   std::string const getSex();    
   
   void setName(std::string name);
   void setSurname(std::string surname);
   void setPESEL(std::string PESEL);
   void setSex(std::string sex);
   void setAddress(std::shared_ptr<Address> address);
   void setSalary(std::string salary);
};