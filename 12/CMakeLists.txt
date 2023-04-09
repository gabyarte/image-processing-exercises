cmake_minimum_required(VERSION 3.6)                            
PROJECT(exercise12)                                                                                

find_package(OpenCV REQUIRED )


INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( exercise_12a src/exercise_12a.cpp )

target_link_libraries( exercise_12a  ${OpenCV_LIBS} )  