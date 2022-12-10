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
   std::string sex_;
   std::shared_ptr<Address> address_;
   std::string PESEL_;
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
   virtual std::string getIndexNumber() const = 0;
   virtual std::string getSalary() const = 0;
   std::string const getPESEL();
   std::string const getSex();    
   
   void setName(std::string name);
   void setSurname(std::string surname);
   void setPESEL(std::string PESEL);
   void setSex(std::string sex);
   void setAddress(std::shared_ptr<Address> address);
   virtual void setIndexNumber(std::string indexNumber) = 0;
   virtual void setSalary(std::string salary) = 0;

   virtual void printPerson() = 0;
   
   virtual ~Person(){};
};