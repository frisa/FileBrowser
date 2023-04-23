#include "../inc/SystemInfo.hpp"
#include <iostream>

// linux specific
#include <unistd.h>
#include <limits.h>
#include <chrono>
#include <ctime>

#define HOST_NAME_MAX 255

std::string SystemInfo::getComputerName()
{
    char hostName[HOST_NAME_MAX];
    gethostname(hostName, HOST_NAME_MAX);
    std::string retVal(hostName);
    return retVal;
}

std::string SystemInfo::getCurrentDate()
{
    // just to leave the code sniped for the profiling example
    auto start_time =  std::chrono::system_clock::now();
    usleep(1000); // this simulate the profiling function
    auto end_time = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_time_in_seconds = (end_time - start_time);
    std::time_t end_time_obj = std::chrono::system_clock::to_time_t(end_time);
    std::cout << "The command has been finished at the time: " << std::ctime(&end_time_obj)
        << " elapsed time was: " << elapsed_time_in_seconds.count() << "[s]" << std::endl;

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
