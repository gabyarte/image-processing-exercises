cmake_minimum_required(VERSION 3.6)                            
PROJECT(exercise07)                                                                                

find_package(OpenCV REQUIRED )

set( SRC
    src/main.cpp
)


INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( ${CMAKE_PROJECT_NAME} ${SRC} )

target_link_libraries( ${CMAKE_PROJECT_NAME} ${OpenCV_LIBS} ) 