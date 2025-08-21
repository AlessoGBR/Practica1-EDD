//
// Created by alesso on 12/08/25.
//

#include "Juego.h"



Juego::Juego(int fila, int columas, vector<Jugador> &jugadores) : tablero(fila, columas) {
    this->filas = fila;
    this->columnas = columas;
    for (auto &jugador: jugadores) {
        this->turnos.encolar(&jugador);
    }
    this->finJuego = false;
}

Juego::~Juego() {

}

void Juego::menu() {
    cout << "=====================================" << endl;
    cout << "MENU DE OPCIONES PARA JUGAR" << endl;
    cout << "INGRESA LA ACCION A REALIZAR: " << endl;
    cout << "1. PONER LINEA" << endl;
    cout << "2. VER PODERES" << endl;
    cout << "3. VER TURNOS" << endl;
    cout << "0. SALIR DEL JUEGO" << endl;
    int opcion;
    cin >> opcion;
    switch (opcion) {
        case 1:
            jugar();
            break;
        case 2:
            verPoderes();
            break;
        case 3:
            mostrarTurnos();
            break;
        case 0:
            cout << "SALIENDO DEL JUEGO" << endl;

            break;
        default:
            cout << "OPCION NO VALIDA..." << endl;
            menu();
            break;
    }
}


void Juego::jugar() {
    while (!finJuego) {
        tablero.mostrarTablero();
        jugadorActual = this->turnos.desencolar();
        cout << "TURNO DEL JUGADOR: " << jugadorActual->nombre << endl;

        int fila;
        int columna;
        char dir;
        cout << "INGRESE DE LA FILA" << endl;
        cin >> fila;
        cout << "INGRESE LA COLUMNA" << endl;
        cin >> columna;
        cout << "INGRESE LA DIRECCION (R/D)" << endl;
        cin >> dir;
        if (tablero.marcarLinea(fila, columna, toupper(dir))) {
            tablero.mostrarTablero();
            cout << "TURNO FINALIZADO JUGADOR: " << jugadorActual->nombre << endl;
            turnos.encolar(jugadorActual);
            cout << "TURNO DEL JUGADOR: " << jugadorActual->nombre << endl;

        }
        menu();
    }
}

void Juego::verPoderes() {
    cout << "TRABAJANDO EN ELLO" << endl;
}

void Juego::mostrarTurnos() {
    std::cout << "TURNOS ACTUALES: " << std::endl;
    turnos.imprimir();
}
