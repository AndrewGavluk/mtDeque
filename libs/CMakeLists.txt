cmake_minimum_required(VERSION 3.2)

add_library(libmtDequeLib STATIC lib_mtDequeLib.cpp lib_mtDequeLib.h)
set_target_properties(libmtDequeLib  PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
target_include_directories(libmtDequeLib PRIVATE ${CMAKE_BINARY_DIR})

if(MSVC)
	target_compile_options(libmtDequeLib PRIVATE /W4)
else()
 	target_compile_options(libmtDequeLib PRIVATE -Wall -Wextra -Werror)
endif()
