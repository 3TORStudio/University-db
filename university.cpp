#include "university.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>

University::University(std::string name): name_(name){}

void University::add(std::shared_ptr<Student> student){
   studentsDb_.push_back(student);
}

void University::printDb(){  
   std::for_each(studentsDb_.begin(),
                 studentsDb_.end(),
                 [](auto e){e->printStudent();});                
}