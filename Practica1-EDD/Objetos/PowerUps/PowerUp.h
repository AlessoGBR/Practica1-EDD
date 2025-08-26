//
// Created by alesso on 17/08/25.
//

#ifndef PRACTICA1_EDD_POWERUP_H
#define PRACTICA1_EDD_POWERUP_H
#include <iostream>
#include <memory>
#include <string>


struct PowerUp {
protected:
    std::string nombre;
    std::string simbolo;
    bool activo;
    int id;

public:
    PowerUp(int identificador, const std::string &nom, const std::string &sim)
        : id(identificador), nombre(nom), simbolo(sim), activo(true) {
    }

    PowerUp() : id(-1), nombre(""), simbolo(""), activo(false) {
    }

    std::string getNombre() const { return nombre; }
    std::string getSimbolo() const { return simbolo; }
    bool estaActivo() const { return activo; }
    int getId() const { return id; }

    void desactivar() { activo = false; }
    void activar() { activo = true; }

    void mostrarInfoBase() const {
        std::cout << "PODER: " << nombre << " (" << simbolo << ")" << std::endl;
    }

    PowerUp clonarBase() const {
        return PowerUp(id, nombre, simbolo);
    }
};


#endif //PRACTICA1_EDD_POWERUP_H
