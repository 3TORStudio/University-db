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
std::string Address::getStreet(){return street_;}
