cmake_minimum_required(VERSION 3.8)

project(CmakeProjectDemo)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Model)
add_subdirectory(PngReader)

add_subdirectory(Network)

#定义依赖关系 编译顺序
add_dependencies(PngReader Model)