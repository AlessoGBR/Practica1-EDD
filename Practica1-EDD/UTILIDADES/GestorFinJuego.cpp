//
// Created by alesso on 27/08/25.
//

#include "GestorFinJuego.h"

#include <algorithm>
#include <iomanip>

#include "../Estructuras/ListaEnlazada/ListaEnlazada.h"
#include "../Estructuras/ListaEnlazada/NodoTablero.h"
#include "../Objetos/Jugador.h"

GestorFinJuego::GestorFinJuego(ListaEnlazadaTablero tab, int f, int c)
    : tablero(tab), filas(f), columnas(c) {
}

GestorFinJuego::~GestorFinJuego() {
}

bool GestorFinJuego::tableroEstaLleno() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            NodoTablero *casilla = tablero.obtenerNodo(i, j);
            if (casilla && casilla->dueño == ' ') {
                return false;
            }
        }
    }
    return true;
}

Jugador *GestorFinJuego::determinarGanador(Cola<Jugador *>& jugadores) {
    std::vector<EstadisticasJugador> estadisticas;

    Cola<Jugador *> colaTemp = jugadores;
    while (!colaTemp.estaVacia()) {
        Jugador *jugador = colaTemp.desencolar();
        estadisticas.push_back(EstadisticasJugador(jugador));
    }

    calcularCuadradosCerrados(estadisticas);
    calcularFilasGanadas(estadisticas);
    calcularColumnasGanadas(estadisticas);
    calcularIslaMasGrande(estadisticas);

    std::cout << "======================" << std::endl;
    std::cout << "DATOS FINALES: " << std::endl;

    std::vector<EstadisticasJugador> ganadores = estadisticas;

    ganadores = filtrarEmpate(ganadores, 1);
    if (ganadores.size() == 1) {
        std::cout << "GANADOR POR PUNTOS: " << ganadores[0].jugador->getNombre() << std::endl;
        return ganadores[0].jugador;
    }

    ganadores = filtrarEmpate(ganadores, 2);
    if (ganadores.size() == 1) {
        std::cout << "GANADOR POR CUADRADOS CERRADOS: " << ganadores[0].jugador->getNombre() << std::endl;
        return ganadores[0].jugador;
    }

    ganadores = filtrarEmpate(ganadores, 3);
    if (ganadores.size() == 1) {
        std::cout << "GANADOR POR FILAS: " << ganadores[0].jugador->getNombre() << std::endl;
        return ganadores[0].jugador;
    }

    ganadores = filtrarEmpate(ganadores, 4);
    if (ganadores.size() == 1) {
        std::cout << "GANADOR POR COLUMNAS: " << ganadores[0].jugador->getNombre() << std::endl;
        return ganadores[0].jugador;
    }

    ganadores = filtrarEmpate(ganadores, 5);
    if (ganadores.size() == 1) {
        std::cout << "GANADOR POR ISLA MAS GRANDE: " << ganadores[0].jugador->getNombre() << std::endl;
        return ganadores[0].jugador;
    }

    ganadores = filtrarEmpate(ganadores, 6);
    if (ganadores.size() == 1) {
        std::cout << "GANADOR POR POWERUPS USADOS: " << ganadores[0].jugador->getNombre() << std::endl;
        return ganadores[0].jugador;
    }

    std::cout << "EMPATE" << std::endl;
    for (const auto &est: ganadores) {
        std::cout << "   - " << est.jugador->getNombre() << std::endl;
    }

    return ganadores[0].jugador;
}

void GestorFinJuego::calcularCuadradosCerrados(std::vector<EstadisticasJugador>& estadisticas) {

    for (int i = 0; i < filas - 1; i++) {
        for (int j = 0; j < columnas - 1; j++) {
            NodoTablero* nodo1 = tablero.obtenerNodo(i, j);
            NodoTablero* nodo2 = tablero.obtenerNodo(i, j + 1);
            NodoTablero* nodo3 = tablero.obtenerNodo(i + 1, j);
            NodoTablero* nodo4 = tablero.obtenerNodo(i + 1, j + 1);

            if (nodo1 == nullptr || nodo2 == nullptr ||
                nodo3 == nullptr || nodo4 == nullptr) {
                continue;
                }

            char iniciales[4];
            iniciales[0] = nodo1->dueño;
            iniciales[1] = nodo2->dueño;
            iniciales[2] = nodo3->dueño;
            iniciales[3] = nodo4->dueño;

            if (iniciales[0] != ' ' && iniciales[0] == iniciales[1] &&
                iniciales[1] == iniciales[2] && iniciales[2] == iniciales[3]) {

                for (auto& est : estadisticas) {
                    if (est.jugador->getInicial() == iniciales[0]) {
                        est.cuadradosCerrados++;
                        std::cout << "CUADRO ENCONTRADO PARA " << est.jugador->getNombre()
                                  << " EN (" << i << "," << j << ")" << std::endl;
                        break;
                    }
                }
                }
        }
    }
}

void GestorFinJuego::calcularFilasGanadas(std::vector<EstadisticasJugador>& estadisticas) {

    for (int i = 0; i < filas; i++) {
        std::vector<int> conteoFila(estadisticas.size(), 0);

        for (int j = 0; j < columnas; j++) {
            NodoTablero* nodo = tablero.obtenerNodo(i, j);
            if (nodo == nullptr) {
                continue;
            }

            char contenido = nodo->dueño;
            if (contenido != ' ') {
                for (size_t k = 0; k < estadisticas.size(); k++) {
                    if (estadisticas[k].jugador->getInicial() == contenido) {
                        conteoFila[k]++;
                        break;
                    }
                }
            }
        }

        int maxCasillas = 0;
        for (int count : conteoFila) {
            maxCasillas = std::max(maxCasillas, count);
        }

        if (maxCasillas > 0) {
            for (size_t k = 0; k < estadisticas.size(); k++) {
                if (conteoFila[k] == maxCasillas) {
                    estadisticas[k].filasGanadas++;
                }
            }
        }
    }
}

void GestorFinJuego::calcularColumnasGanadas(std::vector<EstadisticasJugador>& estadisticas) {

    for (int j = 0; j < columnas; j++) {
        std::vector<int> conteoColumna(estadisticas.size(), 0);

        for (int i = 0; i < filas; i++) {
            NodoTablero* nodo = tablero.obtenerNodo(i, j);
            if (nodo == nullptr) {
                continue;
            }

            char contenido = nodo->dueño;
            if (contenido != ' ') {
                for (size_t k = 0; k < estadisticas.size(); k++) {
                    if (estadisticas[k].jugador->getInicial() == contenido) {
                        conteoColumna[k]++;
                        break;
                    }
                }
            }
        }

        int maxCasillas = 0;
        for (int count : conteoColumna) {
            maxCasillas = std::max(maxCasillas, count);
        }

        if (maxCasillas > 0) {
            for (size_t k = 0; k < estadisticas.size(); k++) {
                if (conteoColumna[k] == maxCasillas) {
                    estadisticas[k].columnasGanadas++;
                }
            }
        }
    }
}

void GestorFinJuego::calcularIslaMasGrande(std::vector<EstadisticasJugador>& estadisticas) {

    for (auto& est : estadisticas) {
        est.islaMasGrande = encontrarIslaMasGrande(est.jugador->getInicial());
        std::cout << "ISLA MAS GRANDE DE " << est.jugador->getNombre()
                  << ": " << est.islaMasGrande << std::endl;
    }
}

int GestorFinJuego::encontrarIslaMasGrande(char inicial) {
    std::vector<std::vector<bool>> visitado(filas, std::vector<bool>(columnas, false));
    int islaMasGrande = 0;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (!visitado[i][j]) {
                NodoTablero* nodo = tablero.obtenerNodo(i, j);
                if (nodo != nullptr && nodo->dueño == inicial) {
                    int tamanioActual = 0;
                    buscarIsla(visitado, i, j, inicial, tamanioActual);
                    islaMasGrande = std::max(islaMasGrande, tamanioActual);
                }
            }
        }
    }

    return islaMasGrande;
}

void GestorFinJuego::buscarIsla(std::vector<std::vector<bool>>& visitado, int x, int y,
                               char inicial, int& tamanioActual) {

    if (x < 0 || x >= filas || y < 0 || y >= columnas || visitado[x][y]) {
        return;
    }

    NodoTablero* nodo = tablero.obtenerNodo(x, y);
    if (nodo == nullptr || nodo->dueño != inicial) {
        return;
    }

    visitado[x][y] = true;
    tamanioActual++;

    buscarIsla(visitado, x - 1, y, inicial, tamanioActual);
    buscarIsla(visitado, x + 1, y, inicial, tamanioActual);
    buscarIsla(visitado, x, y - 1, inicial, tamanioActual);
    buscarIsla(visitado, x, y + 1, inicial, tamanioActual);
}

std::vector<EstadisticasJugador> GestorFinJuego::filtrarEmpate(
    const std::vector<EstadisticasJugador>& jugadores, int criterio) {

    if (jugadores.size() <= 1) return jugadores;

    int maxValor = 0;

    for (const auto& est : jugadores) {
        int valor = 0;
        switch (criterio) {
            case 1: valor = est.puntos; break;
            case 2: valor = est.cuadradosCerrados; break;
            case 3: valor = est.filasGanadas; break;
            case 4: valor = est.columnasGanadas; break;
            case 5: valor = est.islaMasGrande; break;
            case 6: valor = est.poderesUsados; break;
            default: valor = 0; break;
        }
        maxValor = std::max(maxValor, valor);
    }

    std::vector<EstadisticasJugador> resultado;
    for (const auto& est : jugadores) {
        int valor = 0;
        switch (criterio) {
            case 1: valor = est.puntos; break;
            case 2: valor = est.cuadradosCerrados; break;
            case 3: valor = est.filasGanadas; break;
            case 4: valor = est.columnasGanadas; break;
            case 5: valor = est.islaMasGrande; break;
            case 6: valor = est.poderesUsados; break;
            default: valor = 0; break;
        }
        if (valor == maxValor) {
            resultado.push_back(est);
        }
    }

    return resultado;
}


void GestorFinJuego::mostrarResultadoFinal(Jugador *ganador, const std::vector<EstadisticasJugador> &estadisticas) {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "JUEGO TERMINADO" << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    std::cout << "GANADOR: " << ganador->getNombre() << std::endl;
    std::cout << std::string(50, '=') << std::endl;
}
