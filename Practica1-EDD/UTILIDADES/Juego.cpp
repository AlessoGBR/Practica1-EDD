//
// Created by alesso on 21/02/25.
//

#include "Juego.h"
#include <vector>
#include "../OBJETOS/Jugador.h"
#include "../OBJETOS/Cola.h"
#include "../OBJETOS/Tablero.h"

Juego::Juego() {
}

bool verificarPalabraEnPila(Pila<std::string> &pilaPalabras, const std::string &palabra) {
    Pila<std::string> pilaTemporal;
    bool encontrada = false;

    while (!pilaPalabras.estaVacia()) {
        std::string palabraActual = pilaPalabras.desapilar();
        if (palabraActual == palabra) {
            encontrada = true;
        } else {
            pilaTemporal.apilar(palabraActual);
        }
    }

    while (!pilaTemporal.estaVacia()) {
        pilaPalabras.apilar(pilaTemporal.desapilar());
    }

    return encontrada;
}

std::string obtenerPalabraHorizontal(Tablero &tablero, int fila, int columna, int &valorPalabraHorizontal) {
    valorPalabraHorizontal = 0;
    std::string palabraIzquierda, palabraCompleta;

    int col = columna - 1;
    while (col >= 0 && tablero.obtenerLetra(fila, col).getLetra() != ' ') {
        palabraIzquierda += tablero.obtenerLetra(fila, col).getLetra();
        valorPalabraHorizontal += tablero.obtenerLetra(fila, col).getValor();
        --col;
    }

    std::reverse(palabraIzquierda.begin(), palabraIzquierda.end());

    palabraCompleta = palabraIzquierda + tablero.obtenerLetra(fila, columna).getLetra();
    valorPalabraHorizontal += tablero.obtenerLetra(fila, columna).getValor();

    col = columna + 1;
    while (col < tablero.obtenerColumnas() && tablero.obtenerLetra(fila, col).getLetra() != ' ') {
        palabraCompleta += tablero.obtenerLetra(fila, col).getLetra();
        valorPalabraHorizontal += tablero.obtenerLetra(fila, col).getValor();
        ++col;
    }

    return palabraCompleta;
}

std::string obtenerPalabraVertical(Tablero &tablero, int fila, int columna, int &valorPalabraVertical) {
    valorPalabraVertical = 0;
    std::string arriba, abajo;

    int f = fila - 1;
    while (f >= 0 && tablero.obtenerLetra(f, columna).getLetra() != ' ') {
        arriba += tablero.obtenerLetra(f, columna).getLetra();
        valorPalabraVertical += tablero.obtenerLetra(f, columna).getValor();
        --f;
    }

    std::reverse(arriba.begin(), arriba.end());

    std::string palabra = arriba + tablero.obtenerLetra(fila, columna).getLetra();
    valorPalabraVertical += tablero.obtenerLetra(fila, columna).getValor();

    f = fila + 1;
    while (f < tablero.obtenerFilas() && tablero.obtenerLetra(f, columna).getLetra() != ' ') {
        palabra += tablero.obtenerLetra(f, columna).getLetra();
        valorPalabraVertical += tablero.obtenerLetra(f, columna).getValor();
        ++f;
    }

    return palabra;
}


int valorPalabraHorizontal;
int valorPalabraVertical;

void Juego::juego(std::vector<Jugador> &jugadores, Pila<std::string> &pilaPalabras) {
    Cola<Jugador *> turnos;
    for (auto &jugador: jugadores) {
        turnos.encolar(&jugador);
    }

    Tablero tablero;
    std::cout << "\nTABLERO INICIAL:\n";
    tablero.mostrarTablero();

    while (!turnos.estaVacia()) {
        Jugador *jugadorActual = turnos.desencolar();
        std::cout << "\n🎮 TURNO DE: " << jugadorActual->nombre << " PUNTUACION: "<< jugadorActual->puntuacion<< std::endl;

        // Mostrar fichas del jugador
        jugadorActual->mostrarFicha();

        int idFichaSeleccionada;
        std::cout << "INGRESE EL ID DE LA FICHA A JUGAR: ";
        std::cin >> idFichaSeleccionada;

        Ficha *fichaSeleccionada = jugadorActual->obtenerFichaPorId(idFichaSeleccionada);
        if (!fichaSeleccionada) {
            std::cout << "❌ ID DE FICHA NO VALIDO...\n";
            turnos.encolar(jugadorActual);
            continue;
        }

        int fila, columna;
        std::cout << "INGRESE AL FILA (0-" << tablero.obtenerFilas() - 1 << "): ";
        std::cin >> fila;
        std::cout << "INGRESE LA COLUMNA (0-" << tablero.obtenerColumnas() - 1 << "): ";
        std::cin >> columna;

        if (!tablero.colocarFicha(fila, columna, fichaSeleccionada->letra, fichaSeleccionada->valor)) {
            std::cout << "❌ POSICION OCUPADA O INVALIDA.\n";
            std::cout << "PIERDES EL TURNO DE JUEGO";
            turnos.encolar(jugadorActual);
            continue;
        }

        jugadorActual->eliminarFichaPorId(idFichaSeleccionada);

        tablero.mostrarTablero();

        std::string palabraHorizontal = obtenerPalabraHorizontal(tablero, fila, columna, valorPalabraHorizontal);
        std::string palabraVertical = obtenerPalabraVertical(tablero, fila, columna, valorPalabraVertical);

        std::string palabraVerticalInvertida = palabraVertical;
        std::reverse(palabraVerticalInvertida.begin(), palabraVerticalInvertida.end());

        bool palabraEncontrada = false;

        if (palabraHorizontal.length() > 1 && verificarPalabraEnPila(pilaPalabras, palabraHorizontal)) {
            std::cout << "✅ PALABRA EN HORIZONTAL ENCONTRADA: " << palabraHorizontal
                      << " | PUNTOS GANADOS: " << valorPalabraHorizontal << "!\n";
            jugadorActual->puntuacion += valorPalabraHorizontal;
            palabraEncontrada = true;
        } else {
            valorPalabraHorizontal = 0;
        }

        if (palabraVertical.length() > 1 && verificarPalabraEnPila(pilaPalabras, palabraVertical)) {
            std::cout << "✅ PALABRA EN VERTICAL ENCONTRADA: " << palabraVertical
                      << " | PUNTOS GANADOS: " << valorPalabraVertical << "!\n";
            jugadorActual->puntuacion += valorPalabraVertical;
            palabraEncontrada = true;
        } else {
            valorPalabraVertical = 0;
        }


        if (!palabraEncontrada) {
            std::cout << "❌ NO SE FORMO UNA PALABRA.\n";
        }

        turnos.encolar(jugadorActual);

        std::cout << "🔄 PRESIONE ENTER PARA CONTINUAR...";
        std::cin.ignore();
        std::cin.get();
    }
}
