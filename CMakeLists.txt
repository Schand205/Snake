# Mindestversion CMake
cmake_minimum_required(VERSION 3.10)

# Projektname
project(Snake_SDL VERSION 1.0)

# C++-Standard setzen
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

# SDL2
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

# Source/Header Dateien
add_executable(snake
	src/draw.cpp
	src/init.cpp
	src/input.cpp
	src/main.cpp
	src/highscore.cpp
	src/score.cpp
	lib/header.hpp
)
# Include Dateien(Header)
target_include_directories(snake
	PRIVATE
		${PROJECT_SOURCE_DIR}/lib
		${SDL2_INCLUDE_DIRS}
)
# SDL2 linken
target_link_libraries(snake
	PRIVATE
		${SDL2_LIBRARIES}
)
