cmake_minimum_required(VERSION 3.12)

find_package(Boost REQUIRED COMPONENTS filesystem)
add_library(CliRunner cli.cpp cli.h)
target_link_libraries(CliRunner DatabaseManager DatabaseFileManager CSharpHandle EnvironmentRunner)