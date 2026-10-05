cmake_minimum_required(VERSION 4.0)
project(Practica2_EEDD)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Practica2_EEDD
        ListaDE.cpp
        ListaDE.h
        VDinamico.h
        Especie.h
        Especie.cpp
        LectorCSV.h
        LectorCSV.cpp
        main.cpp)
