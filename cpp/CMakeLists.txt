cmake_minimum_required (VERSION 2.6)

project (ShowMeCpp)

file(GLOB ShowMeCpp_SOURCES "*.cpp")
file(GLOB ShowMeCpp_HEADERS "*.hpp")

include_directories("./")
add_executable(ShowMeCpp ${ShowMeCpp_SOURCES}) 
