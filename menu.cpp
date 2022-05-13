#include "menu.hpp"

void Menu::printStartMenu() const{
    std::system("clear");
    std::cout << "Start menu\n";
    std::cout << "--------------------\n";
    std::cout << "1. New database\n";
    std::cout << "2. Default database\n";
    std::cout << "--------------------\n";
    std::cout << ":q to exit\n";         
}

std::shared_ptr<University> Menu::startMenu(){
    std::string choice {};
    std::string nameOfNewDatabase;
    printStartMenu();
    while(getline(std::cin,choice) && requestForQuit(choice)){
        if(choice == "1"){
            std::cout << "The name of new database: ";
            std::cin >> nameOfNewDatabase;
            University u(nameOfNewDatabase);
            std::cout << "startMenu " << u.getName() << '\n';
            return std::make_shared<University> (u);
        } 
        else if(choice == "2"){
            University ud("UniversityDefault");
            return std::make_shared<University> (ud);
        } 
        else {
            std::cerr << "Wrong choice. Try again.";
        }
    }
    return nullptr;
}

void Menu::printMainMenu() const {
    std::system("clear");
    std::cout << "xxxxxxxxxxxxxxxxxxxxxxx\n";
    std::cout << "University database\n";
    std::cout << "xxxxxxxxxxxxxxxxxxxxxxx\n";
    std::cout << "1. Read data from file\n";
    std::cout << "2. Write data to file\n";
    std::cout << "-----------------------\n";
    std::cout << "3. Print all data\n";
    std::cout << "4. Print students\n";
    std::cout << "5. Print employies\n";
    std::cout << "-----------------------\n";
    std::cout << "6. Sort by pesel\n";
    std::cout << "7. Sort by name\n";
    std::cout << "8. Sort by salary\n";
    std::cout << "-----------------------\n";
    std::cout << "9. Modyfiy salary\n";
    std::cout << "-----------------------\n";
    std::cout << "10. Find by pesel\n";
    std::cout << "11. Find by name\n";
    std::cout << "-----------------------\n";
    std::cout << "12. Delete by Index Number\n";
    std::cout << "-----------------------\n";
    std::cout << "13. Generate data\n";
    std::cout << "-----------------------\n";
    std::cout << ":q to exit\n";
    std::cout << "xxxxxxxxxxxxxxxxxxxxxxx\n";
}

void Menu::mainMenu(std::shared_ptr<University> u) {
    if (u)
    {
        std::string ans {};
        printMainMenu();
        //std::cin.clear(); std::cin.ignore();
        while(std::getline(std::cin,ans) && requestForQuit(ans)){
            //std::system("clear");
            printMainMenu();
            if (!ans.empty() && std::all_of(ans.begin(),
                                             ans.end(),
                                             [](const char c){
                                                 return isdigit(c);
                                             })){   
                switch (stoi(ans)){
                    case 2: u->pToF(); break;
                    case 3: u->printDb(); break;
                    case 6: u->sortByPESEL(); break;
                    case 7: u->sortByName(); break;
                    case 8: u->sortBySalary(); break;
                    case 9: u->salaryModificationByPesel("0","0"); break;
                    case 10: u->findByPESEL(); break;
                    case 11: u->findByName()->printPerson(); break;
                    case 12: u->deleteById(); break;
                    case 13: u->generateData(); break;
                    default: std::cout << "Wrong choice. Try again.\n"; break;
                }
            } 
            else {
                std::cout << "No choice. Try again: ";
            }
            //printMainMenu();
        }
    } 
    else{
        std::cout << "Exit.";
    }
}

bool Menu::requestForQuit(std::string ans){
    return ans == ":q" ? false : true;
}