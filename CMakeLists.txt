cmake_minimum_required(VERSION 3.17)
project(Chess_UCSP)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chess_UCSP main.cpp Librerias/Tablero/Tablero.cpp Librerias/Tablero/Tablero.h Librerias/Piezas/Piezas.cpp Librerias/Piezas/Piezas.h)