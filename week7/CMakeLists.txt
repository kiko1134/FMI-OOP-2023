cmake_minimum_required(VERSION 3.25)
project(week7)

set(CMAKE_CXX_STANDARD 17)

add_executable(week7 main.cpp "Task 0/Temperature.cpp" "Task 0/Temperature.h" Task1/Forecast.h Task1/Forecast.cpp Task2/Ticket.cpp Task2/Ticket.h Task2/Queue.cpp Task2/Queue.h Task3/Item.cpp Task3/Item.h Task3/Backpack.cpp Task3/Backpack.h)
