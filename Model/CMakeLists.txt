cmake_minimum_required(VERSION 3.8)

project(Model)

#生成lib
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

SET(CMAKE_AUTOMOC_MOC_OPTIONS "-bstdafx.h")

include_directories(
	Standard
)

# 设置静态库文件目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# 可执行文件目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


file(GLOB CPP_FILES
  Standard/*.cpp
  Standard/*.h
)

message( "------------------")
message( ${CPP_FILES})


add_library(${PROJECT_NAME} SHARED ${CPP_FILES})

