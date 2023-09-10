cmake_minimum_required(VERSION 3.12)


add_library(RunnerGui STATIC runner_gui.cpp runner_gui.h 
"windows/main/main.window.h" 
"windows/main/main.window.cpp" 
"windows/runner_window.cpp"
"windows/runner_window.h"
"windows/console_window/console.window.h" 
"windows/console_window/console.window.cpp")

target_link_libraries(RunnerGui PRIVATE ImGui Vulkan::Vulkan glfw)
 