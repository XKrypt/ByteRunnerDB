cmake_minimum_required(VERSION 3.12)


add_library(CSharpHandle csharp_handle.cpp csharp_handle.h)
target_link_libraries(CSharpHandle PUBLIC Mono::Mono)
