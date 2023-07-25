cmake_minimum_required(VERSION 3.12)
set(CMAKE_TOOLCHAIN_FILE /home/fhayha/vcpkg/scripts/buildsystems/vcpkg.cmake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/finds_cmake")
set(CMAKE_CXX_STANDARD 11)
set(CURSES_NEED_NCURSES TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -g")
set(CMAKE_PREFIX_PATH "${HOME}/vcpkg/packages/glfw3_x64-linux/share/glfw")

project(ByteRunnerDB)
find_package(Mono REQUIRED)
find_package(Vulkan REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem)
set(glfw3_DIR /home/fhayha//vcpkg/packages/glfw3_x64-linux/share/glfw3)
message(${glfw3_DIR})
find_package(glfw3 CONFIG REQUIRED)
# Verifica se o diretório de build existe e, se não, cria-o
if(NOT EXISTS "${CMAKE_BINARY_DIR}")
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}")
endif()
add_compile_options("-mavx" "-march=native")
#set(MONO_INCLUDE_DIRS "/usr/include/mono-2.0/mono")



add_executable(ByteRunnerDB main.cpp ) 

target_compile_features(ByteRunnerDB PRIVATE cxx_std_17)
# Defina o diretório de saída para os arquivos da biblioteca
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
#Biliotecas
add_subdirectory("byterunner_libs/database_file_manager")
add_subdirectory("byterunner_libs/database_manager")
add_subdirectory("byterunner_libs/server_runner")
add_subdirectory("byterunner_libs/csharp_handle")
add_subdirectory("byterunner_libs/cli")
add_subdirectory("byterunner_libs/environment_runner")
add_subdirectory("byterunner_libs/runner_gui")
add_subdirectory("libs/cppfs")
add_subdirectory("libs/efsw")

target_include_directories(ByteRunnerDB PUBLIC "libs/nlhoman")
target_include_directories(ByteRunnerDB PUBLIC "libs/uuid_v4")
target_include_directories(ByteRunnerDB PUBLIC "libs/cli11")

target_include_directories(DatabaseFileManager PUBLIC "libs/nlhoman")
target_include_directories(DatabaseFileManager PUBLIC "libs/uuid_v4")

target_include_directories(DatabaseManager PUBLIC "libs/nlhoman")
target_include_directories(DatabaseManager PUBLIC "libs/uuid_v4")


target_include_directories(CSharpHandle PUBLIC "libs/nlhoman")
target_include_directories(CSharpHandle PUBLIC "libs/rapidxml")


target_include_directories(RunnerGui PUBLIC "libs/imgui")

target_include_directories(EnvironmentRunner PUBLIC "libs/nlhoman")

target_include_directories(ServerRunner PUBLIC "libs/nlhoman")
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
target_link_libraries(ByteRunnerDB PUBLIC RunnerGui)