#include "student.hpp"

Student::Student(std::string name,
                 std::string surname,
                 std::shared_ptr<Address> addres,
                 std::string indexNumber,
                 std::string PESEL,
                 std::string sex)
                : name_(name)
                , surname_(surname)
                , indexNumber_(indexNumber)
                , sex_(sex)
                , address_(addres)
{
    if (!isPeselCorrect(PESEL)){
        std::cerr << "PESEL incorect!\n";
        PESEL_ = "00000000000";
    }
    else{
        PESEL_ = PESEL;
    }
}

std::string const Student::getName() { return name_; }
std::string const Student::getSurname() { return surname_; }
std::shared_ptr<Address> Student::getAddress() { return address_; }
std::string const Student::getIndexNumber() { return indexNumber_; }
std::string const Student::getPESEL() { return PESEL_; }
std::string const Student::getSex() { return sex_; }

void Student::setName(std::string name){name_ = name;}
void Student::setSurname(std::string surname){surname_ = surname;}
void Student::setIndexNumber(std::string indexNumber){indexNumber_ = indexNumber;}
void Student::setPESEL(std::string PESEL){PESEL_ = PESEL;}
void Student::setSex(std::string sex){sex_ = sex;}
void Student::setAddress(std::shared_ptr<Address> address){address_ = address;}

void Student::printStudent(){
    std::cout << std::string(20,'-') << '\n';
    std::cout << "Index number: " << indexNumber_ << '\n';
    std::cout << std::string(20,'-') << '\n';;
    std::cout << "First name: " << name_ << '\n';
    std::cout << "Surname: " << surname_ << '\n';
    std::cout << std::string(20,'-') << '\n';;
    std::cout << "PESEL: " << PESEL_ << '\n';
    std::cout << "Sex: " << sex_ << '\n';
    std::cout << std::string(20,'-') << '\n';;
    std::cout << "Adress:\n";
    std::cout << address_->getStreet() << ' ' << address_->getHouseNumber() << '\n';
    std::cout << address_->getPostalCode() << ' ' << address_->getTown() << '\n';
    std::cout << std::string(20,'-') << '\n';;
}

bool Student::isPeselCorrect(std::string pesel){
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