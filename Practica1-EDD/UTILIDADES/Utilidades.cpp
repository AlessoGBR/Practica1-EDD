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


std::vector<std::string> cargarPalabrasDesdeCSV(const std::string &nombreArchivo) {
    std::vector<std::string> palabras;
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "ERROR AL ABRIR EL ARCHIVO: " << nombreArchivo << std::endl;
        return palabras;
    }

    std::string linea;
    // Ahora con este while lo podemos saber que es lineal, ya que depende de la
    // cantidad de palabras que se encuentre en el documento .cvs
    // Notacion O(N)
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

Pila<std::string> apilarPalabrasEncontradas(const std::vector<std::string> &palabrasDisponibles,
                                            const std::vector<std::string> &palabrasEncontradas) {
    Pila<std::string> pilaPalabras;
    std::vector<std::string> palabrasValidas;

    // En este ciclo for por la cantidad de palabras que se encuentran
    // la Notacion es de O(N)
    for (const auto &palabra: palabrasEncontradas) {
        if (std::find(palabrasDisponibles.begin(), palabrasDisponibles.end(), palabra) != palabrasDisponibles.end()) {
            palabrasValidas.push_back(palabra);
        }
    }

    // Para ordenar las palabras de forma alfabetica se utiliza el algoritmo burbuja, cuya
    // complejidad puede ser denotada como
    // Notacion O(N^2)
    for (size_t i = 0; i < palabrasValidas.size() - 1; ++i) {
        for (size_t j = 0; j < palabrasValidas.size() - i - 1; ++j) {
            if (palabrasValidas[j] > palabrasValidas[j + 1]) {
                std::swap(palabrasValidas[j], palabrasValidas[j + 1]);
            }
        }
    }

    // para apilar las palabras que encontramos en el docomento .cvs cada ves que
    // se ingresa a la pila es una Notacion O(N)
    for (const auto &palabra: palabrasValidas) {
        pilaPalabras.apilar(palabra);
    }

    return pilaPalabras;
}


ListaEnlazada<Ficha> generarFichas(const std::vector<std::string> &palabras) {
    std::vector<Ficha> fichasVector;
    int id = 1;

    // Por ser un bucle for dentro de otro bucle for
    // podemos mostrar que es una notacion lineal, ya que depende de la
    // cantidad de palbras que fueron encontradas
    // Notacion O(N)
    for (const auto &palabra: palabras) {
        for (char letra: palabra) {
            int valor = rand() % 10 + 1;
            fichasVector.emplace_back(letra, valor, id++);
        }
    }

    // Para ordenar las fichas se utiliza el algoritmo burbuja, cuya
    // complejidad puede ser denotada como
    // Notacion O(N^2)
    for (size_t i = 0; i < fichasVector.size() - 1; ++i) {
        for (size_t j = 0; j < fichasVector.size() - i - 1; ++j) {
            if (fichasVector[j].getValor() < fichasVector[j + 1].getValor()) {
                std::swap(fichasVector[j], fichasVector[j + 1]);
            }
        }
    }

    // y para agregar las fichas a la lista seria
    // una Notacion O(1) Lineal
    ListaEnlazada<Ficha> fichas;
    for (const auto &ficha: fichasVector) {
        fichas.insertar(ficha);
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
