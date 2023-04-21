/*
    This is the class providing the simple system informations
*/

#include <string>

class SystemInfo{

    // get various computer informations
    std::string getComputerName();
    std::string getCurrentDate();

public:
    // print the computer informations
    void printComputerName();
    void printCurrentDate();
};