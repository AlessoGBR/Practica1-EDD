//
// Created by alesso on 12/08/25.
//

#include "Juego.h"

#include <limits>


Juego::Juego(int fila, int columas, vector<Jugador> &jugadores) : tablero(fila, columas) {
    this->filas = fila;
    this->columnas = columas;
    for (auto &jugador: jugadores) {
        this->turnos.encolar(&jugador);
    }
    this->finJuego = false;
    this->finalJuego = false;
}

Juego::~Juego() {
    this->turnos.desencolar();
}

void Juego::menu() {
    while (!finJuego) {
        if (primera) {
            jugadorActual = this->turnos.desencolar();
            this->primera = false;
        }

        cout << "\n=====================================\n";
        cout << "MENU DE OPCIONES - TURNO DE: " << jugadorActual->getNombre() << endl;
        cout << "=====================================\n";
        cout << "1. PONER LINEA" << endl;
        cout << "2. VER PODERES"<< endl;
        cout << "3. VER TURNOS"<< endl;
        cout << "4. AGREGAR FILAS O COLUMNAS"<< endl;
        cout << "5. ELIMINAR NODO DE BORDE"<< endl;
        cout << "0. TERMINAR JUEGO - VER GANADOR"<< endl;
        cout << "=====================================\n";
        cout << "SELECCIONA UNA OPCION: ";

        int opcion;
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "ENTRADA INVALIDA"<< endl;
            continue;
        }

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

            case 4: {
                char option;
                cout << "QUIERES AGREGAR FILAS (F) O COLUMNAS (C) ";
                cin >> option;
                if (option == 'F' || option == 'f') {
                    tablero.agregarFilaAlFinal();
                } else if (option == 'C' || option == 'c') {
                    tablero.agregarColumnaAlFinal();
                } else {
                    cout << "OPCION NO VALIDA"<< endl;;
                }
                tablero.mostrarTablero();
                break;
            }

            case 5: {
                int x, y;
                cout << "INGRESA X: ";
                cin >> x;
                cout << "INGRESA Y: ";
                cin >> y;
                if (tablero.eliminarNodo(x,y)) {
                    tablero.mostrarTablero();
                }

                break;
            }

            case 0:
                cout << "SALIENDO DEL JUEGO...\n";
                fin();
                return;

            default:
                cout << "OPCION NO VALIDA. INTENTA DE NUEVO.\n";
                break;
        }
    }

    turnos.encolar(jugadorActual);
    fin();
}


void Juego::jugar() {
    tablero.mostrarTablero();

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
        cout << "TURNO FINALIZADO: " << jugadorActual->getNombre() << endl;
        jugadorActual = this->turnos.desencolar();
    }

    if (tablero.juegoTerminado()) {
        finJuego = true;
        finalJuego = true;
        cout << "JUEGO TERMINADO" << endl;
    }

    menu();
}

void Juego::verPoderes() {
    cout << "TRABAJANDO EN ELLO" << endl;
}

void Juego::mostrarTurnos() {
    std::cout << "TURNOS ACTUALES: " << std::endl;
    turnos.imprimir();
}

void Juego::fin() {
    GestorFinJuego gest(tablero, filas, columnas);
    ganador = gest.determinarGanador(turnos);
    std::cout << "EL GANADOR ES: " << ganador->getNombre() << std::endl;
    std::exit(0);
}
