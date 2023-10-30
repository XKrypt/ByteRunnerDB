cmake_minimum_required(VERSION 3.12)


add_library(ServerRunner STATIC server_runner.cpp server_runner.h)
target_link_libraries(ServerRunner PRIVATE cppfs::cppfs glog::glog unofficial::evpp::evmc_static unofficial::evpp::evpp_static unofficial::evpp::evnsq_static unofficial::evpp::evpp_lite_static)
