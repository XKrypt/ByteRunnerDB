cmake_minimum_required(VERSION 3.12)


add_library(RunnerGui runner_gui.cpp runner_gui.h)

target_link_libraries(RunnerGui Vulkan::Vulkan glfw)