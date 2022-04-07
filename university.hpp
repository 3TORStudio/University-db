#pragma once
#include "employee.hpp"
#include "person.hpp"
#include "student.hpp"
#include <algorithm>
#include <fstream>
#include <memory>
#include <iostream>
#include <iterator>
#include <vector>

using personDb = std::shared_ptr<Person>;
using employeeDb = std::shared_ptr<Employee>;
using studentDb = std::shared_ptr<Student>;
using universityDb = std::vector<personDb>;

class University
{
    std::string name_;
    universityDb personnelBase_;
    
    studentDb getDataStudent();
    employeeDb getDataEmployee();
public:
    University(std::string name);

    bool add(std::shared_ptr<Person> person);
    bool add();

    void printDb();
    personDb const findByName(const std::string & name);
    personDb const findByPESEL(const std::string & PESEL);
    universityDb & sortByName();
    universityDb & sortByPESEL();
    universityDb & sortBySalary();
    universityDb & deleteById(std::string index);
    void salaryModificationByPesel(const std::string & PESEL, const std::string & newSalary);
    bool pToF();
    bool rFromF();
};