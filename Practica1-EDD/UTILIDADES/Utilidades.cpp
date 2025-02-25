//
// Created by alesso on 21/02/25.
//

#include "Utilidades.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "../OBJETOS/ListaEnlazada.h"
Utilidades::Utilidades() {

}


std::vector<std::string> cargarPalabrasDesdeCSV(const std::string& nombreArchivo) {
    std::vector<std::string> palabras;
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "ERROR AL ABRIR EL ARCHIVO: " << nombreArchivo << std::endl;
        return palabras;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string palabra;
        while (std::getline(ss, palabra, ',')) {
            palabras.push_back(palabra);
        }
    }

    archivo.close();
    return palabras;
}

Pila<std::string> apilarPalabrasEncontradas(const std::vector<std::string>& palabrasDisponibles, const std::vector<std::string>& palabrasEncontradas) {
    Pila<std::string> pilaPalabras;

    for (const auto& palabra : palabrasEncontradas) {
        if (std::find(palabrasDisponibles.begin(), palabrasDisponibles.end(), palabra) != palabrasDisponibles.end()) {
            pilaPalabras.apilar(palabra);
        }
    }

    return pilaPalabras;
}

ListaEnlazada<Ficha> generarFichas(const std::vector<std::string> &palabras) {
    ListaEnlazada<Ficha> fichas;
    int id = 1;

    for (const auto& palabra : palabras) {
        for (char letra : palabra) {
            int valor = rand() % 10 + 1;
            fichas.insertar(Ficha(letra, valor));
            ++id;
        }
    }

    return fichas;
}

void Utilidades::utilidades(std::vector<Jugador> &jugadores, ListaEnlazada<Ficha> fichas) {
    fichas.mezclar();

    int numJugadores = jugadores.size();
    int totalFichas = fichas.obtenerTamano();
    int fichasPorJugador = totalFichas / numJugadores;
    int fichasSobrantes = totalFichas % numJugadores;

    ListaEnlazada<Ficha>::Nodo *actual = fichas.obtenerCabeza();

    for (int jugadorIndex = 0; jugadorIndex < numJugadores; ++jugadorIndex) {
        int cantidadARepartir = fichasPorJugador + (fichasSobrantes > 0 ? 1 : 0);
        fichasSobrantes = std::max(0, fichasSobrantes - 1);
        int id = 1;
        for (int j = 0; j < cantidadARepartir && actual != nullptr; ++j) {
            actual->dato.id = id++;
            jugadores[jugadorIndex].agregarFicha(actual->dato);
            actual = actual->siguiente;
        }
    }
}



