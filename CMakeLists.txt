cmake_minimum_required(VERSION 3.30)
project(JoJo_CC2_Toolbox)

set(CMAKE_CXX_STANDARD 23)
add_link_options(-static -static-libgcc -static-libstdc++ -mwindows)

add_subdirectory(external/wxWidgets-3.2.5)
file(GLOB_RECURSE SOURCES "src/*.c" "src/*.cpp" "src/*.h" "src/*.hpp")
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "src" "external/xfbin/xfbin")
target_link_libraries(${PROJECT_NAME} wx::net wx::core wx::base)