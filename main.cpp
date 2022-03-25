#include "student.hpp"
#include "university.hpp"
#include <iostream>

int main()
{
   Student s1("tero",
               "yn",
               std::make_shared<Address>("c","d","e","f"),
               "g",
               "y",
               "i");
   Student s2("jeden",
               "aab",
               std::make_shared<Address>("c","d","e","f"),
               "z",
               "z",
               "i");
   University u("lo");
   u.add(std::make_shared<Student>(s1));
   u.add(std::make_shared<Student>(s2));
   
   // u.printDb();
   // auto s3 = u.findByPESEL("y");
   // s3->printStudent();

   std::cout << "Befor sorting\n";
   u.printDb();
   u.sortByName();
   std::cout << "After sort by name\n";
   u.printDb();
   std::cout << "After sort by PESEL\n";
   u.sortByPESEL();
   u.printDb();
   u.deleteById("z");
   std::cout << "After deleting\n";
   u.printDb();
   return 0;
}
