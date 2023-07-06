cmake_minimum_required(VERSION 3.12)
project(ByteRunnerDB)

set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/finds_cmake")
set(CMAKE_TOOLCHAIN_FILE "/home/fhayha/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_CXX_STANDARD 11)

# Verifica se o diretório de build existe e, se não, cria-o
if(NOT EXISTS "${CMAKE_BINARY_DIR}")
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}")
endif()
add_compile_options("-mavx" "-march=native")

find_package(Mono REQUIRED)

add_executable(ByteRunnerDB main.cpp ) 
# Defina o diretório de saída para os arquivos da biblioteca
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)



#Biliotecas
add_subdirectory("byterunner_libs/database_runner")
add_subdirectory("libs/cppfs")
target_include_directories(ByteRunnerDB PUBLIC "libs/nlhoman")
target_include_directories(ByteRunnerDB PUBLIC "libs/uuid_v4")

target_include_directories(DatabaseRunner PUBLIC "libs/nlhoman")
target_include_directories(DatabaseRunner PUBLIC "libs/uuid_v4")


# Adicione a biblioteca ao seu projeto
add_library(evpp SHARED IMPORTED)
set_target_properties(evpp PROPERTIES IMPORTED_LOCATION /usr/local/lib/libevpp.so)
# Encontrar todas as bibliotecas do evpp na pasta de origem
file(GLOB EVPP_LIBRARIES /usr/local/lib/*.so)
file(GLOB EVPP_LIBRARIES_SO1 /usr/local/lib/*.so.1)

# Copiar todas as bibliotecas para a pasta de destino
file(COPY ${EVPP_LIBRARIES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${EVPP_LIBRARIES_SO1} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
# Adicione um comando personalizado para copiar a biblioteca
add_custom_command(TARGET ByteRunnerDB POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    /usr/local/lib/libevpp.so ${CMAKE_CURRENT_BINARY_DIR}/libevpp.so)



target_link_libraries(ByteRunnerDB PUBLIC Mono::Mono)
target_link_libraries(ByteRunnerDB PUBLIC evpp)
target_link_libraries(ByteRunnerDB PUBLIC DatabaseRunner)

