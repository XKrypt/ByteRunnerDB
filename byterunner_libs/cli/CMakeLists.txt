cmake_minimum_required(VERSION 3.12)

add_library(CliRunner STATIC cli.cpp cli.h)
target_link_libraries(CliRunner PUBLIC DatabaseManager DatabaseFileManager CSharpHandle EnvironmentRunner unofficial::evpp::evmc_static unofficial::evpp::evpp_static unofficial::evpp::evnsq_static unofficial::evpp::evpp_lite_static)