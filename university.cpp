#include "university.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
// #include <memory>

University::University(std::string name): name_(name){
   Student s("No exist",
             "-",
             std::make_shared<Address>("-","-","-","-"),
             "-",
             "-",
             "-");
   studentsDb_.push_back(std::make_shared<Student>(s));
}

void University::add(std::shared_ptr<Student> student){
   studentsDb_.push_back(student);
}

void University::add(){
   Student s("Zwirek",
               "Muchomorek",
               std::make_shared<Address>("Bagienna","1","77-111","Brzezina"),
               "111A",
               "78040602656",
               "M");
   
   studentsDb_.push_back(std::make_shared<Student>(s));
}

void University::printDb(){  
   std::for_each(std::next(studentsDb_.begin()),
                 studentsDb_.end(),
                 [](auto e){e->printStudent();});                
}

studentDb const University::findByName(std::string name){
   auto result = std::find_if(studentsDb_.begin(),
                  studentsDb_.end(),
                  [name](auto student){return student->getName() == name;});
   if (result == studentsDb_.end())
      return studentsDb_.front();
   return *result;
}

studentDb const University::findByPESEL(std::string PESEL){
   auto result = std::find_if(std::next(studentsDb_.begin()),
                  studentsDb_.end(),
                  [PESEL](auto student){return student->getPESEL() == PESEL;});
   if (result == studentsDb_.end())
      return studentsDb_.front();
   return *result;
}

universityDb & University::sortByName(){
   auto comp = [](auto firstStudent, auto secondStudent){
      return firstStudent->getSurname() < secondStudent->getSurname();
   };
   std::sort(std::next(studentsDb_.begin()), studentsDb_.end(), comp);
   return studentsDb_;
}

universityDb & University::sortByPESEL(){
   auto comp = [](auto firstStudent, auto secondStudent){
      return firstStudent->getPESEL() < secondStudent->getPESEL();
   };
   std::sort(std::next(studentsDb_.begin()), studentsDb_.end(), comp);
   return studentsDb_;
}

universityDb & University::deleteById(std::string index){
   auto deletedStudent = 
      std::remove_if(std::next(studentsDb_.begin()),
                     studentsDb_.end(),
                     [index](auto student){return student->getIndexNumber() == index;});
   studentsDb_.erase(deletedStudent, studentsDb_.end());
   return studentsDb_;
}
