cmake_minimum_required(VERSION 3.25)
project(week8)

set(CMAKE_CXX_STANDARD 17)

add_executable(week8 main.cpp Soldier/Soldier.cpp Soldier/Soldier.h Commander/Commander.cpp Commander/Commander.h General/General.cpp General/General.h)
