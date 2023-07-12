cmake_minimum_required(VERSION 3.12)
project(ByteRunnerDB)

set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/finds_cmake")
set(CMAKE_TOOLCHAIN_FILE "${HOME}/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_CXX_STANDARD 11)
find_package(Mono REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem)
# Verifica se o diretório de build existe e, se não, cria-o
if(NOT EXISTS "${CMAKE_BINARY_DIR}")
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}")
endif()
add_compile_options("-mavx" "-march=native")
set(MONO_INCLUDE_DIRS "/usr/include/mono-2.0/mono")



add_executable(ByteRunnerDB main.cpp ) 

target_compile_features(ByteRunnerDB PRIVATE cxx_std_17)
# Defina o diretório de saída para os arquivos da biblioteca
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

#Biliotecas
add_subdirectory("byterunner_libs/database_file_manager")
add_subdirectory("byterunner_libs/database_manager")
add_subdirectory("byterunner_libs/csharp_handle")
add_subdirectory("byterunner_libs/cli")
add_subdirectory("libs/cppfs")
target_include_directories(ByteRunnerDB PUBLIC "libs/nlhoman")
target_include_directories(ByteRunnerDB PUBLIC "libs/uuid_v4")
target_include_directories(ByteRunnerDB PUBLIC "libs/cli11")

target_include_directories(DatabaseFileManager PUBLIC "libs/nlhoman")
target_include_directories(DatabaseFileManager PUBLIC "libs/uuid_v4")

target_include_directories(DatabaseManager PUBLIC "libs/nlhoman")
target_include_directories(DatabaseManager PUBLIC "libs/uuid_v4")


target_include_directories(CSharpHandle PUBLIC "libs/nlhoman")
target_include_directories(CSharpHandle PUBLIC "libs/rapidxml")


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
target_link_libraries(ByteRunnerDB PUBLIC CSharpHandle)
target_link_libraries(ByteRunnerDB PUBLIC evpp)
target_link_libraries(ByteRunnerDB PUBLIC DatabaseFileManager)
target_link_libraries(ByteRunnerDB PUBLIC DatabaseManager)
target_link_libraries(ByteRunnerDB PUBLIC Boost::filesystem)
target_link_libraries(ByteRunnerDB PUBLIC CliRunner)
