#pragma once
#include "student.hpp"
#include <memory>
#include <vector>

using studentDb = std::shared_ptr<Student>;
using universityDb = std::vector<studentDb>;

class University
{
    std::string name_;
    universityDb studentsDb_;
public:
    University(std::string name);

    void add(std::shared_ptr<Student> student); //ok
    void add();

    void printDb(); //ok

    
    studentDb const findByName(std::string name); //ok

    studentDb const findByPESEL(std::string PESEL); //ok

    universityDb & sortByName(); //ok

    universityDb &sortByPESEL(); //ok

    universityDb &deleteById(std::string index);

    void pToF();

    universityDb rFromF();
};