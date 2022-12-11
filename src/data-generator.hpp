#pragma once
#include "address.hpp"
#include <string>
#include <fstream>
#include <ctime>
#include <iostream>
#include <memory>
#include <random>

class DataGenerator{
    int countLinesInFile(const std::string & fileName);
public:
    std::string getSource(const short & num);
    std::string generateName (const std::string & data);
    std::string generatePesel(const std::string & sex);
    std::string generateSex();
    std::string generateIndexNumber();
    //std::string getAddress();
    std::string generateSalary();
    std::shared_ptr<Address> generateAddress();
};