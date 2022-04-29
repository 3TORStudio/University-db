#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <random>

class DataGenerator{
    int countLinesInFile(const std::string & fileName);
public:
    std::string getFemaleName();
    std::string getMaleName();
    std::string getFemalSurname();
    std::string getMaleSurname();
    std::string generatePesel();
    std::string generateSex();
    std::string getAddress();
};