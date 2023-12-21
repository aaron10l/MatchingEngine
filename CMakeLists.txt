cmake_minimum_required(VERSION 3.13)  # CMake version check
project(ExchangeSimulator)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard

# Add main.cpp file of the project root directory as a source file
# set(main src/main.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(main src/main.cpp
        src/Book.h
        src/Limit.h
        src/Order.h
        src/Book.cpp
        src/Limit.cpp
        src/Order.cpp)