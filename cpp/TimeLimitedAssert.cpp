/// @file
/// @brief 

#include "TimeLimitedAssert.hpp"
#include <iostream>
#include <thread>
#include <chrono>

/// @brief simply sleep for the provided time and set the flag to true
void RunThread(bool& flag, size_t sleepSeconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(sleepSeconds));
    flag = true;
}

/// @brief Test the time limited assert
void TimeLimitedAssert()
{
    auto start = std::chrono::system_clock::now();
    bool flag = false;
    std::thread t1(RunThread, std::ref(flag), 2);
    std::cout << "Starting first assert" << std::endl;
    TIME_LIMITED_ASSERT(flag, 5);
    auto end = std::chrono::system_clock::now();
    std::cout << "Assert took "
              << std::chrono::duration_cast<std::chrono::seconds>(end - start).count()
              << " seconds" << std::endl;
    if (t1.joinable()) t1.join();
    
    flag = false;
    std::cout << "Starting second assert" << std::endl;
    TIME_LIMITED_ASSERT(flag, 5); // this will fail in debug mode
}

