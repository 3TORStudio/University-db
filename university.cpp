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

void University::printDb(){  
   std::for_each(studentsDb_.begin(),
                 studentsDb_.end(),
                 [](auto e){e->printStudent();});                
}

void University::findByNameTest(std::string name){
   auto result = std::find_if(studentsDb_.begin(),
                  studentsDb_.end(),
                  [name](auto stud){return stud->getName() == name;});
   (result != studentsDb_.end())
      ? std::cout << "There is a student\n"
      : std::cout << "There is no that name in Un-base.\n";
}

studentDb const University::findByName(std::string name){
   auto result = std::find_if(studentsDb_.begin(),
                  studentsDb_.end(),
                  [name](auto student){return student->getName() == name;});
   if (result == studentsDb_.end())
      return studentsDb_.front();
   return *result;
}