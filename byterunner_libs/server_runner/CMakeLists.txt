cmake_minimum_required(VERSION 3.12)


add_library(ServerRunner server_runner.cpp server_runner.h)
target_link_libraries(ServerRunner PUBLIC evpp cppfs Boost::filesystem)
