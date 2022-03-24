#include "address.hpp"

Address::Address(std::string street,
                std::string houseNumber,
                std::string postalCode,
                std::string town)
                : street_(street)
                , houseNumber_(houseNumber)
                , postalCode_(postalCode)
                , town_(town)
    {}
std::string const Address::getStreet(){return street_;}
std::string const Address::getHouseNumber(){return houseNumber_;}
std::string const Address::getPostalCode(){return postalCode_;}
std::string const Address::getTown(){return town_;}
