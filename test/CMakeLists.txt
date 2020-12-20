cmake_minimum_required(VERSION 3.2)
enable_testing()

find_package(GTest REQUIRED)
include_directories()
add_executable(gtest_mtDequeLib test_mtDequeLib.cpp)

set_target_properties(gtest_mtDequeLib 
	PROPERTIES 
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS})
	
				
if(MSVC)
	target_compile_options(gtest_mtDequeLib PRIVATE /W4)
else()
	target_compile_options(gtest_mtDequeLib PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
							
target_link_libraries(gtest_mtDequeLib gtest pthread libmtDequeLib)
							
add_test(gtest_mtDequeLib_test1 gtest_mtDequeLib)
