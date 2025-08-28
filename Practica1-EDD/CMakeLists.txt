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
        Objetos/PowerUps/PowerUp.cpp
        Objetos/PowerUps/PowerUp.h
        Estructuras/Cola/NodoCola.cpp
        Estructuras/Cola/NodoCola.h
        Estructuras/Pila/NodoPila.cpp
        Estructuras/Pila/NodoPila.h
        Estructuras/ListaEnlazada/NodoTablero.cpp
        Estructuras/ListaEnlazada/NodoTablero.h
        Objetos/PowerUps/DobleLinea.cpp
        Objetos/PowerUps/DobleLinea.h
        Objetos/PowerUps/TrampaSecreta.cpp
        Objetos/PowerUps/TrampaSecreta.h
        Objetos/PowerUps/Bloqueo.cpp
        Objetos/PowerUps/Bloqueo.h
        Objetos/PowerUps/LlaveSecreta.cpp
        Objetos/PowerUps/LlaveSecreta.h
        Objetos/PowerUps/Pase.cpp
        Objetos/PowerUps/Pase.h
        Objetos/PowerUps/Escurridizo.cpp
        Objetos/PowerUps/Escurridizo.h
        Objetos/PowerUps/PowerUpWrapper.cpp
        Objetos/PowerUps/PowerUpWrapper.h
        Objetos/GeneradorPoderes.cpp
        Objetos/GeneradorPoderes.h
        UTILIDADES/GestorFinJuego.cpp
        UTILIDADES/GestorFinJuego.h
        UTILIDADES/EstadisticasJugador.cpp
        UTILIDADES/EstadisticasJugador.h
)
