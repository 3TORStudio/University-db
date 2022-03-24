#include "student.hpp"
#include "university.hpp"
#include <iostream>

int main()
{
   Student s1("a",
               "b",
               std::make_shared<Address>("c","d","e","f"),
               "g",
               "h",
               "i");
   std::cout << s1.getAddress()->getStreet()<<'\n';

   return 0;
}
