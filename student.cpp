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
            , indexNumber_(indexNumber)
            , PESEL_(PESEL)
            , sex_(sex)
            , address_(addres)
    {}

    
    std::string const Student::getName(){return name_;};
    std::string const Student::getSurame(){return surname_;};
    std::shared_ptr<Address> Student::getAddress(){return address_;}; 
    std::string const Student::indexNumber(){return indexNumber_;};
    std::string const Student::getPESEL(){return PESEL_;};
    std::string const Student::getSex(){return sex_;};