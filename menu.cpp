#include "menu.hpp"

void Menu::printMenu() const {
    std::cout << "xxxxxxxxxxxxxxxxxxxxxxx\n";
    std::cout << "University database\n";
    std::cout << "xxxxxxxxxxxxxxxxxxxxxxx\n";
    std::cout << "1. Add new database\n";
    std::cout << "2. Read data from file\n";
    std::cout << "3. Write data to file\n";
    std::cout << "-----------------------\n";
    std::cout << "4. Print all data\n";
    std::cout << "5. Print students\n";
    std::cout << "6. Print employies\n";
    std::cout << "-----------------------\n";
    std::cout << "7. Sort by pesel\n";
    std::cout << "8. Sort by index number\n";
    std::cout << "9. Sort by salary\n";
    std::cout << "-----------------------\n";
    std::cout << "10. Modyfiy salary\n";
    std::cout << "-----------------------\n";
    std::cout << "11. Find by pesel\n";
    std::cout << "12. Find by index number\n";
    std::cout << "-----------------------\n";
    std::cout << ":q to exit\n";
    std::cout << "xxxxxxxxxxxxxxxxxxxxxxx\n";
}

void Menu::mainMenu() {
    std::string ans;
    do{
        std::system("clear");
        printMenu();
    } while(requestForQuit());
}

bool Menu::requestForQuit(){
    std::string s;
    std::cin >> s;
    if (s == ":q") {
        return false;
    }
    return true;
}