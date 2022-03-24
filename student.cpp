#include "student.hpp"
//#include "address.hpp"

Student::Student (std::string name,
            std::string surname,
            std::shared_ptr<Address> addres,
            std::string indexNumber,
            std::string PESEL,
            std::string sex)
            : name_(name)
            , surname_(surname)
            , address_(addres)
            , indexNumber_(indexNumber)
            , PESEL_(PESEL)
            , sex_(sex)
        {}

    
    std::string const Student::getName(){};
    std::string const Student::getSurame(){};
    Address Student::getAddress(){}; 
    std::string const Student::indexNumber(){};
    std::string const Student::getPESEL(){};
    std::string const Student::getSex(){};