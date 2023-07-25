cmake_minimum_required(VERSION 3.12)


add_library(DatabaseFileManager database_file_manager.cpp database_file_manager.h)
target_link_libraries(DatabaseFileManager PUBLIC cppfs Boost::filesystem)
