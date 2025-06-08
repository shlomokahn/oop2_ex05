cmake_minimum_required(VERSION 3.10)
project(oop2_ex05)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set SFML path
set(SFML_DIR "C:/SFML/SFML-2.6.1/lib/cmake/SFML")

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Add source files
add_executable(oop2_ex05 
    src/main.cpp
    src/Controller.cpp
)

# Include directories
target_include_directories(oop2_ex05 PRIVATE include)

# Link SFML libraries
target_link_libraries(oop2_ex05 sfml-graphics sfml-window sfml-system sfml-audio)

# Copy assets to build directory (if you have an assets folder)
if(EXISTS "${CMAKE_SOURCE_DIR}/assets")
    file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
endif()

# Copy SFML DLLs to build directory
if(WIN32)
    file(GLOB SFML_DLLS "C:/SFML/SFML-2.6.1/bin/*.dll")
    file(COPY ${SFML_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif() 