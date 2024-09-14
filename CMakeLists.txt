cmake_minimum_required(VERSION 3.20)
project(JoJo_CyberConnectTools)

set(CMAKE_CXX_STANDARD 23)
add_link_options(-static -static-libgcc -static-libstdc++ -mwindows)

file(GLOB_RECURSE SOURCES "src/*.c" "src/*.cpp" "src/*.h" "src/*.hpp")

add_subdirectory(external/wxWidgets-3.2.5)
add_subdirectory(external/xfbin)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} nucc-cpp-library)
target_link_libraries(${PROJECT_NAME} wx::net wx::core wx::base)