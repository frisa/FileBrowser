#include "SystemInfo.hpp"
#include <iostream>

// linux specific
#include <unistd.h>
#include <limits.h>

std::string SystemInfo::getComputerName()
{
    char hostName[HOST_NAME_MAX];
    gethostname(hostName, HOST_NAME_MAX);
    std::string retVal(hostName);
    return retVal;
}

std::string SystemInfo::getCurrentDate()
{
    return std::string();
}

void SystemInfo::printComputerName()
{
    std::cout << "Host Name: " << getComputerName() << std::endl;
}

void SystemInfo::printCurrentDate()
{
    std::cout << "Current Date: " << getCurrentDate() << std::endl;
}
