#pragma once
#include <iostream>

class Menu {
    
public:
    //bool quit = false;
    bool requestForQuit(std::string ans);
    void printMenu() const;
    void mainMenu();
};