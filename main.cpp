#include "student.hpp"
#include "university.hpp"
#include <iostream>

int main()
{
   University u("lo");
   u.add();
   u.add(std::make_shared<Student>("Mis",
               "Uszatek",
               std::make_shared<Address>("Majowa","3","00-000","Lasek"),
               "111B",
               "03283004156",
               "M"));

   std::cout << "\nFind by pesel:\n";
   auto s3 = u.findByPESEL("y");
   std::cout << s3->getName() <<'\n';
   std::cout << std::string(20,'-') << '\n';

   std::cout << "Befor sorting\n";
   u.printDb();
   u.sortByName();
   std::cout << "After sort by name\n";
   u.printDb();
   std::cout << "After sort by PESEL\n";
   u.sortByPESEL();
   u.printDb();
    u.deleteById("111B");
   std::cout << "After deleting\n";
   u.printDb();
   u.pToF();
   std::cout << "After reading from file\n";
   u.rFromF();
   u.printDb();
   return 0;
}
