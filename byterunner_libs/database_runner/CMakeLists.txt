cmake_minimum_required(VERSION 3.12)


add_library(DatabaseRunner database_runner.cpp database_runner.h)
target_link_libraries(DatabaseRunner PUBLIC cppfs)
include_directories("libs/")
