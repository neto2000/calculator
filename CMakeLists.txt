cmake_minimum_required(VERSION 3.10)
project(calculator)


set(GUI gui/button.cpp gui/button.h gui/gui_component.h gui/gui_component.cpp gui/display.h gui/display.cpp)

set(LOGIC logic/key_translator.h logic/key_translator.cpp)

add_executable(calculator main.cpp structure.cpp structure.h ${GUI} ${LOGIC})

target_compile_features(calculator PUBLIC cxx_std_20)






target_link_libraries(calculator PUBLIC SDL3_image SDL3)
target_include_directories(calculator PRIVATE gui)
target_include_directories(calculator PRIVATE logic)
