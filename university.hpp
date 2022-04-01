#pragma once
#include "person.hpp"
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
    universityDb personnelBase_;
public:
    University(std::string name);

    bool add(std::shared_ptr<Student> student);
    bool add();

    void printDb();
    studentDb const findByName(const std::string & name);
    studentDb const findByPESEL(const std::string & PESEL);
    universityDb & sortByName();
    universityDb & sortByPESEL();
    universityDb & deleteById(std::string index);
    bool pToF();
    bool rFromF();
};