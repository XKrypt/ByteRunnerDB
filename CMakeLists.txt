cmake_minimum_required(VERSION 3.12)

project(ByteRunnerDB)

if(UNIX)
    set(CMAKE_TOOLCHAIN_FILE /home/fhayha/vcpkg/scripts/buildsystems/vcpkg.cmake)
elseif(WIN32)
    set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}\\scripts\\buildsystems\\vcpkg.cmake)
    set(COPY_TARGET_DIR ${CMAKE_BINARY_DIR})
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/finds_cmake")

if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build")
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CURSES_NEED_NCURSES TRUE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
    add_compile_options("-mavx" "-march=native")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    set(CMAKE_PREFIX_PATH "$ENV{VCPKG_ROOT}/packages/glfw3_x64-linux/share/glfw" ${CMAKE_PREFIX_PATH})
    set(lib_directory $ENV{VCPKG_ROOT}\\packages\\glfw3_x64-windows\\lib)
    set(destination_directory ${CMAKE_CURRENT_BINARY_DIR})
elseif(UNIX)
    set(CMAKE_PREFIX_PATH "$ENV{HOME}/vcpkg/packages/glfw3_x64-linux/share/glfw")
endif()

set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
set(IMGUI_BACKEND_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends)

set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui.h
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_internal.h
    ${IMGUI_DIR}/imstb_rectpack.h
    ${IMGUI_DIR}/imstb_textedit.h
    ${IMGUI_DIR}/imstb_truetype.h
    # Adicione outros arquivos .cpp do ImGui aqui, se necessário
)

set(IMGUI_BACKEND_SOURCES
    ${IMGUI_BACKEND_DIR}/imgui_impl_glfw.cpp
    ${IMGUI_BACKEND_DIR}/imgui_impl_glfw.h
    ${IMGUI_BACKEND_DIR}/imgui_impl_vulkan.cpp
    ${IMGUI_BACKEND_DIR}/imgui_impl_vulkan.h
    # Adicione outros arquivos de backend aqui, se necessário
)

message("Imgui source ${IMGUI_SOURCES}")
message("Imgui backends ${IMGUI_BACKEND_SOURCES}")

find_package(Mono REQUIRED)
find_package(Vulkan REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

if(UNIX)
    set(glfw3_DIR /home/fhayha/vcpkg/packages/glfw3_x64-linux/share/glfw3)
elseif(WIN32)
    set(glfw3_DIR $ENV{VCPKG_ROOT}\\packages\\glfw3_x64-windows\\share\\glfw3)
endif()

message(${glfw3_DIR})
find_package(cppfs CONFIG REQUIRED)

if(NOT EXISTS "${CMAKE_BINARY_DIR}")
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}")
endif()

add_executable(ByteRunnerDB main.cpp )
set_target_properties(ByteRunnerDB PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "")

if(UNIX)
    add_library(evpp SHARED IMPORTED)
    set_target_properties(evpp PROPERTIES IMPORTED_LOCATION /usr/local/lib/libevpp.so)
    file(GLOB EVPP_LIBRARIES /usr/local/lib/*.so)
    file(GLOB EVPP_LIBRARIES_SO1 /usr/local/lib/*.so.1)
    file(COPY ${EVPP_LIBRARIES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY ${EVPP_LIBRARIES_SO1} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
elseif(WIN32)
    message("Copyying...")
    add_custom_target(
        copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        $ENV{VCPKG_ROOT}/packages/glfw3_x64-windows/lib
        ${CMAKE_CURRENT_BINARY_DIR}/lib
    )
    file(COPY ${libevent_files} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    find_package(unofficial-evpp CONFIG REQUIRED)
    find_package(Libevent CONFIG REQUIRED)
    set(evpp_imports "unofficial::evpp::evmc_static unofficial::evpp::evpp_static unofficial::evpp::evnsq_static unofficial::evpp::evpp_lite_static")
endif()

target_compile_features(ByteRunnerDB PRIVATE cxx_std_17)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_library(ImGui STATIC ${IMGUI_SOURCES} ${IMGUI_BACKEND_SOURCES})
add_subdirectory("libs/efsw")
add_subdirectory("byterunner_libs/storage")
add_subdirectory("byterunner_libs/database_file_manager")
add_subdirectory("byterunner_libs/database_manager")
add_subdirectory("byterunner_libs/server_runner")
add_subdirectory("byterunner_libs/csharp_handle")
add_subdirectory("byterunner_libs/cli")
add_subdirectory("byterunner_libs/environment_runner")
add_subdirectory("byterunner_libs/runner_gui")

target_include_directories(ByteRunnerDB PUBLIC "libs/cli11" "libs/nlhoman" "libs/imgui")
target_include_directories(Storage PUBLIC "libs/nlhoman")
target_include_directories(DatabaseFileManager PUBLIC "libs/nlhoman" "libs/uuid_v4")
target_include_directories(DatabaseFileManager PUBLIC "libs/uuid_v4")
target_include_directories(DatabaseManager PUBLIC "libs/nlhoman" "libs/uuid_v4")
target_include_directories(DatabaseManager PUBLIC )
target_include_directories(CSharpHandle PUBLIC "libs/nlhoman" "libs/rapidxml")
target_include_directories(EnvironmentRunner PUBLIC "libs/nlhoman")
target_include_directories(ServerRunner PUBLIC "libs/nlhoman")

if(UNIX)
    add_custom_command(TARGET ByteRunnerDB POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        /usr/local/lib/libevpp.so ${CMAKE_CURRENT_BINARY_DIR}/libevpp.so)
endif()

target_link_libraries(ByteRunnerDB PUBLIC Mono::Mono)
target_link_libraries(ImGui PUBLIC Vulkan::Vulkan glfw)
target_link_libraries(ByteRunnerDB PUBLIC cppfs::cppfs)
target_link_libraries(ByteRunnerDB PUBLIC CSharpHandle)

if(WIN32)
    message("linkin evpp imports : \n ${evpp_imports}")
    target_link_libraries(ByteRunnerDB PUBLIC unofficial::evpp::evmc_static unofficial::evpp::evpp_static unofficial::evpp::evnsq_static unofficial::evpp::evpp_lite_static)
elseif(UNIX)
    target_link_libraries(ByteRunnerDB PUBLIC evpp)
endif()

target_link_libraries(ByteRunnerDB PUBLIC DatabaseFileManager DatabaseManager CliRunner EnvironmentRunner RunnerGui Storage Vulkan::Vulkan glfw)