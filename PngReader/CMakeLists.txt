cmake_minimum_required(VERSION 3.8)

project(PngReader)

set(CMAKE_CXX_STANDARD 20)

set(LIBPNG_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/ThirdParty/libpng/include)
set(LIBPNG_LIBRARY_DIR ${CMAKE_SOURCE_DIR}/ThirdParty/libpng/lib)
set(LIBPNG_LIBRARY_BIN ${CMAKE_SOURCE_DIR}/ThirdParty/libpng/bin)
set(LIBPNG_LIBRARIES ${CMAKE_SOURCE_DIR}/ThirdParty/libpng/lib/libpng16.lib)

set(ZLIB_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/ThirdParty/zlib/include)
set(ZLIB_LIBRARY_DIR ${CMAKE_SOURCE_DIR}/ThirdParty/zlib/lib)
set(ZLIB_LIBRARY_BIN ${CMAKE_SOURCE_DIR}/ThirdParty/zlib/bin)
set(ZLIB_LIBRARIES ${CMAKE_SOURCE_DIR}/ThirdParty/zlib/lib/zlib.lib)

set(MODEL_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/Model/Standard)
set(MODEL_LIBRARY_DIR ${CMAKE_BINARY_DIR}/lib)
set(MODEL_LIBRARIES ${CMAKE_BINARY_DIR}/lib/Model.lib)

include_directories(
	${LIBPNG_INCLUDE_DIRS}
	${ZLIB_INCLUDE_DIRS}
	${MODEL_INCLUDE_DIRS}
)

#添加lib到链接路径
link_directories(MODEL_LIBRARY_DIR)

# 递归将本文件夹下的所有的.cpp文件放到
file(GLOB_RECURSE All_CPP_FILES src/*.cpp)

add_executable(${PROJECT_NAME} ${All_CPP_FILES})

target_link_libraries(${PROJECT_NAME} ${LIBPNG_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${ZLIB_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${MODEL_LIBRARIES})


#message(${EXECUTABLE_OUTPUT_PATH})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)

file(COPY ${LIBPNG_LIBRARY_BIN}/libpng16.dll DESTINATION ${EXECUTABLE_OUTPUT_PATH})
file(COPY ${ZLIB_LIBRARY_BIN}/zlib.dll DESTINATION ${EXECUTABLE_OUTPUT_PATH})

#[[
file(GLOB DLLS
 ${CMAKE_BINARY_DIR}/dll/*.dll
)

message("------------")
message(${DLLS})


file(COPY ${DLLS} DESTINATION ${EXECUTABLE_OUTPUT_PATH})
]]