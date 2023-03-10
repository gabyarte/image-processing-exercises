cmake_minimum_required(VERSION 3.6)                            
PROJECT(exercise04)                                                                                

find_package(OpenCV REQUIRED )


INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( exercise_04a_opening src/exercise_04a_opening.cpp )
add_executable( exercise_04b_closing src/exercise_04b_closing.cpp )

target_link_libraries( exercise_04a_opening  ${OpenCV_LIBS} )  
target_link_libraries( exercise_04b_closing  ${OpenCV_LIBS} )