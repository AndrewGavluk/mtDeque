cmake_minimum_required (VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
	project( mtDeque VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
	project( mtDeque VERSION 99.99.999)
endif()

add_subdirectory (${PROJECT_SOURCE_DIR}/libs)
add_subdirectory (${PROJECT_SOURCE_DIR}/src)
add_subdirectory (${PROJECT_SOURCE_DIR}/test)
