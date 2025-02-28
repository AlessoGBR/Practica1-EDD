#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include "OBJETOS/Cola.h"
#include "OBJETOS/Ficha.h"
#include "OBJETOS/Jugador.h"
#include "OBJETOS/Tablero.h"
#include "UTILIDADES/Juego.h"
#include "UTILIDADES/Utilidades.h"
#include "OBJETOS/ListaEnlazada.h"


void inicioJuego() {
    std::string arte = R"(
  ______    ______   _______    ______   _______   _______   __       ________
 /      \  /      \ |       \  /      \ |       \ |       \ |  \     |        \
|  $$$$$$\|  $$$$$$\| $$$$$$$\|  $$$$$$\| $$$$$$$\| $$$$$$$\| $$     | $$$$$$$$
| $$___\$$| $$   \$$| $$__| $$| $$__| $$| $$__/ $$| $$__/ $$| $$     | $$__
 \$$    \ | $$      | $$    $$| $$    $$| $$    $$| $$    $$| $$     | $$  \
 _\$$$$$$\| $$   __ | $$$$$$$\| $$$$$$$$| $$$$$$$\| $$$$$$$\| $$     | $$$$$
|  \__| $$| $$__/  \| $$  | $$| $$  | $$| $$__/ $$| $$__/ $$| $$_____| $$_____
 \$$    $$ \$$    $$| $$  | $$| $$  | $$| $$    $$| $$    $$| $$     \ $$     \
  \$$$$$$   \$$$$$$  \$$   \$$ \$$   \$$ \$$$$$$$  \$$$$$$$  \$$$$$$$$\$$$$$$$$
   )";

    std:: cout << arte << std::endl;
}

int main() {
    srand(time(0));
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
    std::vector<Jugador> jugadores;
    for (int i = 0; i < numJugadores; ++i) {
        std::string nombre;
        std::cout << "INGRESE EL NOMBRE DEL JUGADOR " << (i + 1) << ": ";
        std::getline(std::cin, nombre);
        jugadores.push_back(Jugador(nombre));
    }

    std::string nombreArchivo;
    std::cout << "INGRESE LA DIRECCION DE LAS PALABRAS (SIN EL .CVS): ";
    std::getline(std::cin, nombreArchivo);
    nombreArchivo += ".csv";
    std::vector<std::string> palabras = cargarPalabrasDesdeCSV(nombreArchivo);
    if (palabras.empty()) {
        std::cerr << "NO SE PUDO CARGAR EL ARCHIVO." << std::endl;
        return 1;
    }

    Pila<std::string> pilaPalabras = apilarPalabrasEncontradas(palabras,palabras);
    pilaPalabras.mostrar();
    ListaEnlazada<Ficha> fichas = generarFichas(palabras);

    Utilidades utilidades;
    utilidades.utilidades(jugadores, fichas);
    Juego juego;
    juego.juego(jugadores, pilaPalabras);
    std::cout << "----------------------------------\n";
    std::cout <<"FIN DEL JUEGO GRACAS POR JUGAR";

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.