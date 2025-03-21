cmake_minimum_required(VERSION 3.10)
project(calculator)

set(GUI gui/button.cpp gui/button.h gui/gui_component.h gui/gui_component.cpp)

add_executable(calculator main.cpp ${GUI})
target_link_libraries(calculator SDL3)
target_include_directories(calculator PRIVATE gui)
