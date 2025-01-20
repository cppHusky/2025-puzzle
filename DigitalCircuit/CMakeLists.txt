cmake_minimum_required(VERSION 3.30)
project(Circuit VERSION 0.1)
set(CMAKE_CXX_STANDARD 20)
add_library(cc_library STATIC
	include/operate.hpp
	include/preset.hpp
	lib/floyd.cpp
	lib/signal.cpp
)
target_include_directories(cc_library PUBLIC include)
add_executable(kn src/karnaugh.cpp)
add_executable(sol src/solve.cpp)
add_executable(sim src/simulator.cpp)
add_executable(alz src/analyze.cpp)
target_link_libraries(kn PRIVATE cc_library)
target_link_libraries(sol PRIVATE cc_library)
target_link_libraries(sim PRIVATE cc_library)
target_link_libraries(alz PRIVATE cc_library)
