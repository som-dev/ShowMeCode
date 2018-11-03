cmake_minimum_required (VERSION 2.6)

project (ShowMeCpp)

file(GLOB ShowMeCpp_SOURCES "*.cpp")
file(GLOB ShowMeCpp_HEADERS "*.hpp")

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

include_directories("./")
add_executable(ShowMeCpp ${ShowMeCpp_SOURCES})

find_package(Threads)
target_link_libraries(ShowMeCpp ${CMAKE_THREAD_LIBS_INIT})
