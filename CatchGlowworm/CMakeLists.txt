cmake_minimum_required(VERSION 3.30)
project(CatchGlowworm VERSION 0.1)
set(CMAKE_CXX_STANDARD 20)
add_library(cg_library STATIC
	include/coordinate.hpp
	include/operate.hpp
	include/preset.hpp
	include/random.hpp
	lib/initialize.cpp
	lib/move.cpp
	lib/calculator.cpp
)
target_include_directories(cg_library PUBLIC include)
add_executable(cg src/cg.cpp)
target_link_libraries(cg PRIVATE cg_library)
