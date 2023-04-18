/*
    this is the main application of the file browser
*/
#include "SystemInfo.hpp"

#include <iostream>
#include <memory>

int main()
{
    std::cout << "File Browser application has started" << std::endl;
    std::unique_ptr<SystemInfo> si =  std::make_unique<SystemInfo>();
    si->printComputerName();
    return 0;
}
