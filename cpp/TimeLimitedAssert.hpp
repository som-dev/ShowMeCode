///@file
///@brief Macro for extending assert up to a specified time limit
///@note This style has been used for unit test framework assertions as well
/// such as google test ASSERT_EQUAL
#pragma once

#include <assert.h>
#include <thread>
#include <chrono>

/// @brief Keep checking the provided test for up to timeLimitSeconds
#define TIME_LIMITED_ASSERT(test, timeLimitSeconds) \
do { \
    auto limit = std::chrono::seconds(timeLimitSeconds); \
    auto start = std::chrono::steady_clock::now(); \
    while (!(test)) \
    { \
        auto elapsedTime = std::chrono::steady_clock::now() - start; \
        if (elapsedTime > limit) break; \
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); \
    } \
    assert(test); \
} while (false);
