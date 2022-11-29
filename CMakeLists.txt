cmake_minimum_required(VERSION 3.24.0)

project(TheDungeonGame)

set(
	SourceFiles
	main.cpp
	Creature.cpp
	Monster.cpp
	Player.cpp
)

set(
	HeaderFiles
	main.hpp
	Creature.hpp
	Monster.hpp
	Player.hpp
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main ${SourceFiles} ${HeaderFiles})

