cmake_minimum_required(VERSION 3.10)
project(oop2_ex05)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set SFML path
set(SFML_DIR "C:/SFML/SFML-2.6.1/lib/cmake/SFML")

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Enable Edit and Continue for MSVC (Debug mode)
if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /ZI")
endif()

# Add source files
add_executable( "oop2_ex05" 
    "src/main.cpp"
  "src/Controller.cpp"
 "include/GameBoard.h" "src/GameBoard.cpp"
"include/Object.h" "src/Object.cpp"
"include/Texture.h" "src/Texture.cpp"
"include/Car.h" "src/Car.cpp" 
"include/Io.h"
"include/SrartWindow.h" "src/SrartWindow.cpp"
"include/PrintText.h" "src/PrintText.cpp" 
"include/SmartCar.h" "src/SmartCar.cpp" 
"include/Exit.h" 
"include/UserSettings.h"
"include/Player.h" "src/Player.cpp" 
"include/Enemy.h" "src/Enemy.cpp" 
"include/EnemyCar.h" "src/EnemyCar.cpp" 
"include/Menu.h" "src/Menu.cpp" 
"include/Command.h"  
"include/Botton.h" "src/Botton.cpp" 
"include/Help.h" "src/Help.cpp" 
"include/Road.h" "src/Road.cpp" 
"include/RoadLine.h" "src/RoadLine.cpp" "include/ObjectMove.h" "src/ObjectMove.cpp")

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

# Copy resources to all relevant build directories (for image/sound loading)
if(EXISTS "${CMAKE_SOURCE_DIR}/resources")
    file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR}/Debug)
    file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR}/Release)
    file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR}/x64-Debug)
    file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR}/x64-Release)
endif()