cmake_minimum_required(VERSION 3.6)                            
PROJECT(exercise13cd)                                                                                

find_package(OpenCV REQUIRED )


INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( exercise_13c src/exercise_13c.cpp )
add_executable( exercise_13d src/exercise_13d.cpp )


target_link_libraries( exercise_13c  ${OpenCV_LIBS} )  
target_link_libraries( exercise_13d  ${OpenCV_LIBS} )  