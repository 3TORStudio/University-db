#pragma once
#include "person.hpp"
#include "student.hpp"
#include <algorithm>
#include <fstream>
#include <memory>
#include <iostream>
#include <iterator>
#include <vector>

using personDb = std::shared_ptr<Person>;
using universityDb = std::vector<personDb>;

class University
{
    std::string name_;
    universityDb personnelBase_;
public:
    University(std::string name);

    bool add(std::shared_ptr<Person> person);
    bool add();

    void printDb();
    personDb const findByName(const std::string & name);
    personDb const findByPESEL(const std::string & PESEL);
    universityDb & sortByName();
    universityDb & sortByPESEL();
    universityDb & deleteById(std::string index);
    bool pToF();
    bool rFromF();
};