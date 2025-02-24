//
// Created by alesso on 21/02/25.
//

#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "../OBJETOS/Pila.h"
#include "../OBJETOS/Ficha.h"
#include "../OBJETOS/Jugador.h"
#include "../OBJETOS/ListaEnlazada.h"
#include <string>
#include <vector>

class Utilidades {
public:
    Utilidades();
    void utilidades(std::vector<Jugador>& jugadores, ListaEnlazada<Ficha>);
};

std::vector<std::string> cargarPalabrasDesdeCSV(const std::string& nombreArchivo);
Pila<std::string> apilarPalabrasEncontradas(const std::vector<std::string>& palabrasDisponibles, const std::vector<std::string>& palabrasEncontradas);

ListaEnlazada<Ficha> generarFichas(const std::vector<std::string> &palabras);



#endif // UTILIDADES_H
