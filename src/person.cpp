#include "person.hpp"

Person::Person(std::string name,
          std::string surname,
          std::string sex,
          std::shared_ptr<Address> address,
          std::string PESEL)
          : name_(name)
          , surname_(surname)
          , sex_(sex)
          , address_(address)
{
    if (!isPeselCorrect(PESEL)){
        std::cerr << "PESEL incorect!\n";
        setPESEL("00000000000");
    }
    else{
        setPESEL(PESEL);
    }
}


std::string const Person::getName() { return name_; }
std::string const Person::getSurname() { return surname_; }
std::shared_ptr<Address> Person::getAddress() { return address_; }
std::string const Person::getPESEL() { return PESEL_; }
std::string const Person::getSex() { return sex_; }


void Person::setName(std::string name){name_ = name;}
void Person::setSurname(std::string surname){surname_ = surname;}
void Person::setPESEL(std::string PESEL){PESEL_ = PESEL;}
void Person::setSex(std::string sex){sex_ = sex;}
void Person::setAddress(std::shared_ptr<Address> address){address_ = address;}
bool Person::isPeselCorrect(std::string pesel){
    if(pesel.size() != 11){
        return false;
    }
    if(std::any_of(pesel.begin(),pesel.end(),[](char const c){return !isdigit(c);})){
        return false;
    }
    unsigned s = pesel[0] -'0'
               + (pesel[1] - '0') * 3
               + (pesel[2] - '0') * 7
               + (pesel[3] - '0') * 9
               + pesel[4] -'0'
               + (pesel[5] - '0') * 3
               + (pesel[6] - '0') * 7
               + (pesel[7] - '0') * 9
               + pesel[8] -'0'
               + (pesel[9] - '0') * 3
               + pesel[10] -'0';
    if (s % 10){
        return false;
    }
    return true;
}