#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <random>

class DataGenerator{
    int countLinesInFile(const std::string & fileName);
public:
    std::string getSource(const std::string & sex, const short & num);
    std::string getMaleName();
    std::string getFemalSurname();
    std::string getMaleSurname();
    std::string generatePesel();
    std::string generateSex();
    std::string getAddress();
    std::string get
};