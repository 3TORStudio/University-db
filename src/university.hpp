#pragma once
#include "data-generator.hpp"
#include "employee.hpp"
#include "person.hpp"
#include "student.hpp"
#include <algorithm>
#include <fstream>
#include <filesystem>
#include <memory>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <string_view>
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

    int getNumberOfPeople();
    
    bool add(std::shared_ptr<Person> person);
    bool add();

    void printDb();
    void printSt();
    void printEmp();
    personDb const findByName();
    personDb const findByPESEL();
    universityDb & sortByName();
    universityDb & sortByPESEL();
    universityDb & sortBySalary();
    universityDb & deleteById();
    universityDb & deleteByPesel();
    void generateData();
    void salaryModificationByPesel(const std::string & PESEL, const std::string & newSalary);
    bool pToF();
    bool rFromF();

    std::string getName(){return name_;};
    void setName(std::string name);
};