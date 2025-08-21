cmake_minimum_required(VERSION 3.31)
project(Practica1_EDD)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practica1_EDD main.cpp
        Estructuras/Pila/Pila.cpp
        Estructuras/Pila/Pila.h
        Estructuras/Cola/Cola.cpp
        Estructuras/Cola/Cola.h
        Estructuras/ListaEnlazada/ListaEnlazada.cpp
        Estructuras/ListaEnlazada/ListaEnlazada.h
        Objetos/Jugador.cpp
        Objetos/Jugador.h
        UTILIDADES/Juego.cpp
        UTILIDADES/Juego.h
        Objetos/PowerUp.cpp
        Objetos/PowerUp.h
        Estructuras/Cola/NodoCola.cpp
        Estructuras/Cola/NodoCola.h
        Estructuras/Pila/NodoPila.cpp
        Estructuras/Pila/NodoPila.h
        Estructuras/ListaEnlazada/NodoTablero.cpp
        Estructuras/ListaEnlazada/NodoTablero.h)
