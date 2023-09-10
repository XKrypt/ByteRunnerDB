cmake_minimum_required(VERSION 3.12)


add_library(DatabaseManager STATIC database_manager.cpp database_manager.h)
target_link_libraries(DatabaseManager PUBLIC cppfs::cppfs DatabaseFileManager Storage)