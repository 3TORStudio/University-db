#include "student.hpp"
#include "university.hpp"
#include <iostream>

int main()
{
   Student s1("zero",
               "b",
               std::make_shared<Address>("c","d","e","f"),
               "g",
               "h",
               "i");
   Student s2("jeden",
               "b",
               std::make_shared<Address>("c","d","e","f"),
               "g",
               "h",
               "i");
   University u("lo");
   u.add(std::make_shared<Student>(s1));
   u.add(std::make_shared<Student>(s2));
   // u.printDb();

   auto s3 = u.findByName("jeden");

   s3->printStudent();
   return 0;
}
