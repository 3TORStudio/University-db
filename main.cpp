#include "student.hpp"
#include "university.hpp"
#include <iostream>

int main()
{
   //Test1 - University class constructor 
   University u("University");
   // //Test2a - adding student to database
   // u.add();
   // //Test2b - adding student to database
   // u.add(std::make_shared<Student>("Mis",
   //             "Uszatek",
   //             std::make_shared<Address>("Majowa","3","00-000","Lasek"),
   //             "111B",
   //             "03283004156",
   //             "M"));
   // //Test3 - find by Name
   // std::cout << std::string(20,'-') << '\n';
   // std::cout << "\nFind by name:\n";
   // auto s3 = u.findByName("Mis");
   // std::cout << s3->getSurname() << '\n';
   // std::cout << std::string(20,'-') << '\n';
   // //Test4 - find by pesel
   // std::cout << "\nFind by pesel:\n";
   // auto s4 = u.findByPESEL("78040602656");
   // std::cout << s4->getName() <<'\n';
   // std::cout << std::string(20,'-') << '\n';
   // std::cout << "Befor sorting\n";
   // u.printDb();
   // //Test5 - sort by name
   // u.sortByName();
   // std::cout << "After sort by name\n";
   // u.printDb();
   // //Test6 - sort by pesel
   // std::cout << "After sort by PESEL\n";
   // u.sortByPESEL();
   // u.printDb();
   // //Test7 - delete by Id
   // u.deleteById("111B");
   // std::cout << "After deleting\n";
   // u.printDb();
   // //Test8 - print to file
   // u.pToF();
   // std::cout << "After reading from file\n";
   // //Test9 - print from file
   // u.rFromF();
   // u.printDb();
   return 0;
}
