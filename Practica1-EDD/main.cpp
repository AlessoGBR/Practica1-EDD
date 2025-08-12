#include <iostream>
#include "Objetos/Jugador.h"
#include <vector>
#include "Estructuras/Cola.h"

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
    do {
        std::cout << "INGRESE LA CANTIDAD DE JUGADORES (2-5): ";
        std::cin >> numJugadores;
        std::cin.ignore();
    } while (numJugadores < 2 || numJugadores > 5);

    // El ingreso de los jugadores es constante ya que solo
    // se podran jugar de 2 a 5 jugadores
    // Notacion O(1)
    Cola<Jugador> cola;
    for (int i = 0; i < numJugadores; ++i) {
        std::string nombre;
        std::cout << "INGRESE EL NOMBRE DEL JUGADOR " << (i + 1) << ": ";
        std::getline(std::cin, nombre);
        char primerCaracter = tolower(nombre.at(0));
        cola.encolar(Jugador(nombre, primerCaracter));
    }


    return 0;
}
