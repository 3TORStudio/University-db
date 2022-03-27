#pragma once
#include "student.hpp"
#include <algorithm>
#include <fstream>
#include <memory>
#include <iostream>
#include <iterator>
#include <vector>

using studentDb = std::shared_ptr<Student>;
using universityDb = std::vector<studentDb>;

class University
{
    std::string name_;
    universityDb studentsDb_;
public:
    University(std::string name);

    void add(std::shared_ptr<Student> student);
    void add();

    void printDb(); //ok
    studentDb const findByName(std::string name);
    studentDb const findByPESEL(std::string PESEL);
    universityDb & sortByName(); //ok
    universityDb &sortByPESEL(); //ok
    universityDb &deleteById(std::string index);
    bool pToF();
    bool rFromF();
};