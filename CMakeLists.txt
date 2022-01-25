cmake_minimum_required(VERSION 3.17)
project(Playlist2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Playlist2 main.c sorting.c sorting.h input.c input.h shuffle.c shuffle.h)