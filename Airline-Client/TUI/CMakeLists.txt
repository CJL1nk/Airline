cmake_minimum_required(VERSION 4.0)
project(Airline_Client)

set(CMAKE_C_STANDARD 17)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(Airline_Client src/main.c ${SRC_FILES})
target_link_libraries(Airline_Client PRIVATE ${CURSES_LIBRARIES})
