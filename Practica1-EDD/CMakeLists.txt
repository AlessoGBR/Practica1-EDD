cmake_minimum_required(VERSION 3.31)
project(Practica1_EDD)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practica1_EDD main.cpp
        Estructuras/Pila.cpp
        Estructuras/Pila.h
        Estructuras/Cola.cpp
        Estructuras/Cola.h
        Estructuras/ListaEnlazada.cpp
        Estructuras/ListaEnlazada.h
        Objetos/Jugador.cpp
        Objetos/Jugador.h
        UTILIDADES/Juego.cpp
        UTILIDADES/Juego.h)
