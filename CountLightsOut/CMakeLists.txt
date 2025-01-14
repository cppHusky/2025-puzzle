cmake_minimum_required(VERSION 3.30)
project(CountLightsOff VERSION 0.2)
set(CMAKE_CXX_STANDARD 20)
add_library(clo_library STATIC
	include/gaussian.hpp
	include/preset.hpp
	lib/gaussian.cpp
	lib/getcoef.cpp
)
target_include_directories(clo_library PUBLIC include)
add_executable(sol src/solve.cpp)
target_link_libraries(sol PRIVATE clo_library)
