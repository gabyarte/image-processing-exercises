cmake_minimum_required(VERSION 3.6)                            
PROJECT(exercise02)                                                                                

find_package(OpenCV REQUIRED )


INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( exercise_02a_thresh src/exercise_02a_thresh.cpp )
add_executable( exercise_02b_compare src/exercise_02b_compare.cpp )
add_executable( exercise_02c_sup src/exercise_02c_sup.cpp )
add_executable( exercise_02c_inf src/exercise_02c_inf.cpp )

target_link_libraries( exercise_02a_thresh  ${OpenCV_LIBS} )  
target_link_libraries( exercise_02b_compare  ${OpenCV_LIBS} )  
target_link_libraries( exercise_02c_sup  ${OpenCV_LIBS} )  
target_link_libraries( exercise_02c_inf  ${OpenCV_LIBS} ) 