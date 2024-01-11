cmake_minimum_required(VERSION 3.13)
project(ExchangeSimulator)
set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(main
            src/types.h
            src/orderbook.h
            src/orderbook.cpp
            src/engine.h
            src/engine.cpp
            src/limits.h
            src/limits.h
    )
    target_link_libraries(main ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Boost not found. Please install Boost or check your Boost installation.")
endif()
