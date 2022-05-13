#pragma once
#include "university.hpp"
#include <iostream>

class Menu {
    
public:
    //bool quit = false;
    bool requestForQuit(std::string ans);
    
    void printMainMenu() const;
    void mainMenu(std::shared_ptr<University> u);
    
    void printStartMenu() const;
    std::shared_ptr<University> startMenu();
};