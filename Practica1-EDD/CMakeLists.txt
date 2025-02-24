cmake_minimum_required(VERSION 3.30)
project(Practica1_EDD)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practica1_EDD main.cpp
        OBJETOS/Jugador.cpp
        OBJETOS/Jugador.h
        OBJETOS/Tablero.cpp
        OBJETOS/Tablero.h
        OBJETOS/Ficha.cpp
        OBJETOS/Ficha.h
        OBJETOS/ListaEnlazada.cpp
        OBJETOS/ListaEnlazada.h
        OBJETOS/Pila.cpp
        OBJETOS/Pila.h
        OBJETOS/Cola.cpp
        OBJETOS/Cola.h
        UTILIDADES/Juego.cpp
        UTILIDADES/Juego.h
        UTILIDADES/Utilidades.cpp
        UTILIDADES/Utilidades.h)
