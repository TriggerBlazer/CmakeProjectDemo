cmake_minimum_required(VERSION 3.8)

project(Network)

set(CMAKE_CXX_STANDARD 20)


# 递归将本文件夹下的所有的.cpp文件放到
file(GLOB_RECURSE All_CPP_FILES src/*.cpp)

add_executable(${PROJECT_NAME} ${All_CPP_FILES} resource.rc )

#message(${EXECUTABLE_OUTPUT_PATH})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)

file(COPY ${CMAKE_SOURCE_DIR}/Resource/Log/Request.log DESTINATION ${EXECUTABLE_OUTPUT_PATH})