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
   Student s2("a",
               "b",
               std::make_shared<Address>("c","d","e","f"),
               "g",
               "h",
               "i");
   University u("lo");
   u.add(std::make_shared<Student>(s1));
   u.add(std::make_shared<Student>(s2));
   u.printDb();
   return 0;
}
