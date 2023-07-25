cmake_minimum_required(VERSION 3.12)

add_library(EnvironmentRunner environment_runner.cpp environment_runner.h)
target_link_libraries(EnvironmentRunner  DatabaseManager CSharpHandle Boost::filesystem efsw Mono::Mono evpp ServerRunner)