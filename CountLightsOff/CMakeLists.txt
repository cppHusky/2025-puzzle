cmake_minimum_required(VERSION 3.30)
project(CountLightsOff VERSION 0.1)
set(CMAKE_CXX_STANDARD 20)
add_library(clo_library STATIC
	lib/initialize.cpp
	lib/click.cpp
	include/random.hpp
	include/operate.hpp)
target_include_directories(clo_library PUBLIC include)
add_executable(clo src/clo.cpp)
target_link_libraries(clo PRIVATE clo_library)
