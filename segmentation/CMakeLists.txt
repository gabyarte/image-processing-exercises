cmake_minimum_required(VERSION 3.6)                            
PROJECT(exercise04)                                                                                

find_package(OpenCV REQUIRED )


INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable( s1a src/s1a.cpp )
target_link_libraries( s1a ${OpenCV_LIBS} )

add_executable( s1b src/s1b.cpp )
target_link_libraries( s1b ${OpenCV_LIBS} )  

add_executable( s1c src/s1c.cpp )
target_link_libraries( s1c ${OpenCV_LIBS} )  

add_executable( s1d src/s1d.cpp )
target_link_libraries( s1d ${OpenCV_LIBS} )  

add_executable( s1e src/s1e.cpp )
target_link_libraries( s1e ${OpenCV_LIBS} )  