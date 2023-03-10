cmake_minimum_required(VERSION 3.6)                            
PROJECT(exercise03)                                                                                

find_package(OpenCV REQUIRED )


INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( exercise_03a_erosion src/exercise_03a_erosion.cpp )
add_executable( exercise_03b_dilation src/exercise_03b_dilation.cpp )

target_link_libraries( exercise_03a_erosion  ${OpenCV_LIBS} )  
target_link_libraries( exercise_03b_dilation  ${OpenCV_LIBS} )  