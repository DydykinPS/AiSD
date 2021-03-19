cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(Polynoms)

include(cmake/function.cmake)

add_subdirectory(List_lib) 
add_subdirectory(Monom_lib) 
add_subdirectory(Polynom_lib) 
add_subdirectory(example) 

option (BTEST "build test?" OFF)

if(BTEST)
	add_subdirectory(gtest)
	add_subdirectory(test)
endif()