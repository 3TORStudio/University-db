#pragma once
#include "student.hpp"
#include <memory>
#include <vector>

using universityDb = std::vector<std::shared_ptr<Student> >;

class University
{
    std::string name_;
    universityDb studentsDb_;
public:
    University(std::string name);

    void add(std::shared_ptr<Student>);

    void printDb();

    Student const findByName();

    Student const findByPESEL();

    universityDb &sortByName();

    universityDb &sortByPESEL();

    universityDb &deleteById(std::shared_ptr<Student>);

    void pToF();

    universityDb rFromF();
};