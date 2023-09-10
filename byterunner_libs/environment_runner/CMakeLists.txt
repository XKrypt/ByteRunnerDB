cmake_minimum_required(VERSION 3.12)

add_library(EnvironmentRunner STATIC environment_runner.cpp environment_runner.h)
target_link_libraries(EnvironmentRunner PUBLIC DatabaseManager CSharpHandle efsw Mono::Mono ServerRunner unofficial::evpp::evmc_static unofficial::evpp::evpp_static unofficial::evpp::evnsq_static unofficial::evpp::evpp_lite_static)