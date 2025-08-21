#include <iostream>
#include "Objetos/Jugador.h"
#include <vector>
#include "Estructuras/Cola/Cola.h"
#include "UTILIDADES/Juego.h"

void inicioJuego() {
    std::string arte = R"(
 /$$$$$$$$ /$$$$$$  /$$$$$$$$ /$$$$$$ /$$$$$$$$ /$$$$$$         /$$$$$$  /$$   /$$ /$$$$$$ /$$   /$$  /$$$$$$
|__  $$__//$$__  $$|__  $$__/|_  $$_/|__  $$__//$$__  $$       /$$__  $$| $$  | $$|_  $$_/| $$$ | $$ /$$__  $$
   | $$  | $$  \ $$   | $$     | $$     | $$  | $$  \ $$      | $$  \__/| $$  | $$  | $$  | $$$$| $$| $$  \ $$
   | $$  | $$  | $$   | $$     | $$     | $$  | $$  | $$      | $$      | $$$$$$$$  | $$  | $$ $$ $$| $$  | $$
   | $$  | $$  | $$   | $$     | $$     | $$  | $$  | $$      | $$      | $$__  $$  | $$  | $$  $$$$| $$  | $$
   | $$  | $$  | $$   | $$     | $$     | $$  | $$  | $$      | $$    $$| $$  | $$  | $$  | $$\  $$$| $$  | $$
   | $$  |  $$$$$$/   | $$    /$$$$$$   | $$  |  $$$$$$/      |  $$$$$$/| $$  | $$ /$$$$$$| $$ \  $$|  $$$$$$/
   |__/   \______/    |__/   |______/   |__/   \______/        \______/ |__/  |__/|______/|__/  \__/ \______/
   )";

    std::cout << arte << std::endl;
}

int main() {
    inicioJuego();
    int numJugadores;
    int fila;
    int columna;
    do {
        std::cout << "INGRESE LA CANTIDAD DE JUGADORES (2-5): ";
        std::cin >> numJugadores;
        std::cin.ignore();
    } while (numJugadores < 2 || numJugadores > 5);
    std::vector<Jugador> jugadores;
    for (int i = 0; i < numJugadores; ++i) {
        std::string nombre;
        std::cout << "INGRESE EL NOMBRE DEL JUGADOR " << (i + 1) << ": ";
        std::getline(std::cin, nombre);
        char primerCaracter = toupper(nombre.at(0));
        jugadores.push_back(Jugador(nombre, primerCaracter));
    }
    std::cout << "MINIMO DE 3*3" << std::endl;
    std::cout << "INGRESE EL TAMANIO DE LAS FILAS: " << std::endl;
    std::cin >> fila;
    std::cout << "INGRESE EL TAMANIO DE LAS COLUMNAS: " << std::endl;
    std::cin >> columna;
    Juego juego = Juego(fila, columna, jugadores);

    juego.menu();
    return 0;
}
