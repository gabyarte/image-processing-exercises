cmake_minimum_required(VERSION 3.6)                            
PROJECT(exercise13ab)                                                                                

find_package(OpenCV REQUIRED )


INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( exercise_13b_maximum src/exercise_13b_maximum.cpp )
add_executable( exercise_13a_minimum src/exercise_13a_minimum.cpp )


target_link_libraries( exercise_13b_maximum  ${OpenCV_LIBS} )  
target_link_libraries( exercise_13a_minimum  ${OpenCV_LIBS} )  