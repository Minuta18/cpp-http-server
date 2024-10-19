cmake_minimum_required(VERSION 3.15)
project(CppHttpServer)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_executable(${PROJECT_NAME} src/Main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)


target_link_libraries(${PROJECT_NAME} CppHttpServerSrc ${CMAKE_DL_LIBS})

