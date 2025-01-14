cmake_minimum_required(VERSION 3.30)
project(CountLightsOff VERSION 0.1)
set(CMAKE_CXX_STANDARD 20)
add_library(clo_library STATIC
	include/gaussian.hpp
	include/operate.hpp
	include/preset.hpp
	include/random.hpp
	lib/click.cpp
	lib/gaussian.cpp
	lib/getcoef.cpp
	lib/initialize.cpp
)
target_include_directories(clo_library PUBLIC include)
add_executable(clo src/clo.cpp)
add_executable(sol src/solve.cpp)
target_link_libraries(clo PRIVATE clo_library)
target_link_libraries(sol PRIVATE clo_library)
