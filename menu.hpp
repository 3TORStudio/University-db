#pragma once
#include "university.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>

class Menu {
    bool nameOfNewDatabaseIsNotOk(std::string nameOfNewDatabase);
    
public:
    //bool quit = false;
    bool requestForQuit(std::string ans);
    
    void printMainMenu() const;
    void mainMenu(std::shared_ptr<University> u);
    
    void printStartMenu() const;
    std::shared_ptr<University> startMenu();
};