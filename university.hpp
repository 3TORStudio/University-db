#pragma once
#include "student.hpp"
#include <memory>
#include <vector>

using universityDb = std::vector<std::shared_ptr<Student> >;

class University
{
    universityDb studentsDb;
public:
    //friend class student;

    void add(std::shared_ptr<Student>);

    // void const printDb();

    Student const findByName();

    Student const findByPESEL();

    universityDb &sortByName();

    universityDb &sortByPESEL();

    universityDb &deleteById(std::shared_ptr<Student>);

    void pToF();

    universityDb rFromF();
};