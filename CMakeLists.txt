cmake_minimum_required(VERSION 3.13)
project(ExchangeSimulator)
set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(TEST_SRCS src/orderbook.cpp src/engine.cpp src/tests/test.cpp)
set(SCORE_SRCS src/orderbook.cpp src/engine.cpp src/tests/score.cpp)

if(Boost_FOUND)
    add_executable(test ${TEST_SRCS})
    add_executable(score ${SCORE_SRCS})
else()
    message(FATAL_ERROR "Boost not found. Please install Boost or check your Boost installation.")
endif()
