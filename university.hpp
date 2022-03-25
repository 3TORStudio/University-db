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

    void add(std::shared_ptr<Student>); //ok

    void printDb(); //ok

    // void findByNameTest(std::string name);
    studentDb const findByName(std::string name);

    studentDb const findByPESEL(std::string PESEL);

    universityDb &sortByName();

    universityDb &sortByPESEL();

    universityDb &deleteById(std::shared_ptr<Student>);

    void pToF();

    universityDb rFromF();
};