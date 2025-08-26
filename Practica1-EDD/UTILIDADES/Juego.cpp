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
            std::exit(0);
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
        cout << "TURNO DEL JUGADOR: " << jugadorActual->getNombre() << endl;

        int fila, columna;
        char dir;
        cout << "INGRESE LA FILA: ";
        cin >> fila;
        cout << "INGRESE LA COLUMNA: ";
        cin >> columna;
        cout << "INGRESE LA DIRECCION (H (HORIZONTAL)/ V (VERTICAL): ";
        cin >> dir;
        dir = toupper(dir);

        bool cerro = tablero.marcarLinea(fila, columna, dir, jugadorActual->getInicial());
        tablero.mostrarTablero();
        if (cerro) {
            jugadorActual->agregarPunto();
            cout << "CUADRO CERRADO POR " << jugadorActual->getNombre() << " SUMAS UN PUNTO" << endl;
            cout << "CONTINUA JUGANDO " << jugadorActual->getNombre() << endl;
        } else {
            turnos.encolar(jugadorActual);
            cout << "TURNO FINALIZADO: " << jugadorActual-> getNombre() << endl;
        }

        if (tablero.juegoTerminado()) {
            finJuego = true;
            cout << "¡Juego terminado!" << endl;
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
