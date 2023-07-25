cmake_minimum_required(VERSION 3.12)

add_subdirectory(storage/)

add_library(DatabaseManager database_manager.cpp database_manager.h)

target_link_libraries(DatabaseManager PRIVATE Boost::filesystem)
target_link_libraries(DatabaseManager PUBLIC DatabaseFileManager Boost::filesystem)
target_link_libraries(DatabaseManager PUBLIC Storage)