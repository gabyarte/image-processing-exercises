cmake_minimum_required(VERSION 3.6)                            
PROJECT(exercise13ab)                                                                                

find_package(OpenCV REQUIRED )


INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( exercise_13a src/exercise_13a.cpp )
add_executable( exercise_13b src/exercise_13b.cpp )


target_link_libraries( exercise_13a  ${OpenCV_LIBS} )  
target_link_libraries( exercise_13b  ${OpenCV_LIBS} )  