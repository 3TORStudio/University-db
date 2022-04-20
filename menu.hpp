#pragma once
#include <iostream>

class Menu {
    
public:
    bool quit = false;
    bool requestForQuit();
    void printMenu() const;
    void mainMenu() const;
};