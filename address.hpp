#pragma once

#include <string>

class Address{
    std::string street_;
    std::string houseNumber_;
    std::string postalCode_;
    std::string town_;
public:
    Address(std::string street,
            std::string houseNumber,
            std::string postalCode,
            std::string town);
    
    std::string getStreet();
};