//
// Created by alesso on 26/08/25.
//

#ifndef PRACTICA1_EDD_POWERUPWRAPPER_H
#define PRACTICA1_EDD_POWERUPWRAPPER_H

#include "Bloqueo.h"
#include "DobleLinea.h"
#include "Escurridizo.h"
#include "LlaveSecreta.h"
#include "Pase.h"
#include "PowerUp.h"
#include "TrampaSecreta.h"
#include <string>

class PowerUpWrapper {

private:
    PowerUp *poder;
    int tipoId;

    DobleLinea *dobleLinea;
    TrampaSecreta *trampaSecreta;
    Bloqueo *bloqueo;
    LlaveSecreta *llaveSecreta;
    Pase *pase;
    Escurridizo *escurridizo;

public:
    PowerUpWrapper() : poder(nullptr), tipoId(-1), dobleLinea(nullptr),
                       trampaSecreta(nullptr), bloqueo(nullptr),
                       llaveSecreta(nullptr), pase(nullptr), escurridizo(nullptr) {
    }

    PowerUpWrapper(const DobleLinea &dl) : tipoId(1) {
        dobleLinea = new DobleLinea(dl);
        poder = dobleLinea;
        inicializarNulos();
    }

    PowerUpWrapper(const TrampaSecreta &ts) : tipoId(2) {
        trampaSecreta = new TrampaSecreta(ts);
        poder = trampaSecreta;
        inicializarNulos();
    }

    PowerUpWrapper(const Bloqueo &bl) : tipoId(3) {
        bloqueo = new Bloqueo(bl);
        poder = bloqueo;
        inicializarNulos();
    }

    PowerUpWrapper(const LlaveSecreta &ls) : tipoId(4) {
        llaveSecreta = new LlaveSecreta(ls);
        poder = llaveSecreta;
        inicializarNulos();
    }

    PowerUpWrapper(const Pase &p) : tipoId(5) {
        pase = new Pase(p);
        poder = pase;
        inicializarNulos();
    }

    PowerUpWrapper(const Escurridizo &e) : tipoId(6) {
        escurridizo = new Escurridizo(e);
        poder = escurridizo;
        inicializarNulos();
    }

    PowerUpWrapper(const PowerUpWrapper &otro) : tipoId(otro.tipoId) {
        if (otro.poder) {
            switch (tipoId) {
                case 1:
                    dobleLinea = new DobleLinea(otro.dobleLinea->clonar());
                    poder = dobleLinea;
                    break;
                case 2:
                    trampaSecreta = new TrampaSecreta(otro.trampaSecreta->clonar());
                    poder = trampaSecreta;
                    break;
                case 3:
                    bloqueo = new Bloqueo(otro.bloqueo->clonar());
                    poder = bloqueo;
                    break;
                case 4:
                    llaveSecreta = new LlaveSecreta(otro.llaveSecreta->clonar());
                    poder = llaveSecreta;
                    break;
                case 5:
                    pase = new Pase(otro.pase->clonar());
                    poder = pase;
                    break;
                case 6:
                    escurridizo = new Escurridizo(otro.escurridizo->clonar());
                    poder = escurridizo;
                    break;
            }
            inicializarNulos();
        }
    }

    ~PowerUpWrapper() {
        limpiar();
    }

    PowerUpWrapper &operator=(const PowerUpWrapper &otro) {
        if (this != &otro) {
            limpiar();
            tipoId = otro.tipoId;
            if (otro.poder) {
                switch (tipoId) {
                    case 1:
                        dobleLinea = new DobleLinea(otro.dobleLinea->clonar());
                        poder = dobleLinea;
                        break;
                    case 2:
                        trampaSecreta = new TrampaSecreta(otro.trampaSecreta->clonar());
                        poder = trampaSecreta;
                        break;
                        // faltan agregar casos
                }
                inicializarNulos();
            }
        }
        return *this;
    }

    bool esValido() const { return poder != nullptr; }
    int getTipo() const { return tipoId; }
    std::string getNombre() const { return poder ? poder->getNombre() : ""; }
    std::string getSimbolo() const { return poder ? poder->getSimbolo() : ""; }
    bool estaActivo() const { return poder ? poder->estaActivo() : false; }

    bool aplicarEfecto(Jugador *jugador, ListaEnlazadaTablero *tablero,
                       int x, int y, char direccion) {
        if (!poder || !poder->estaActivo()) return false;

        switch (tipoId) {
            case 1:
                return dobleLinea->aplicarEfectoDobleLinea(jugador, tablero, x, y, direccion);
            case 2:
                return trampaSecreta->aplicarEfectoTrampa(jugador, tablero, x, y, direccion);
            case 3:
                return bloqueo->aplicarEfectoBloqueo(jugador, tablero, x, y, direccion);
            case 4:
                return llaveSecreta->aplicarEfectoLlave(jugador, tablero, x, y, direccion);
            case 5:
                return pase->aplicarEfectoPase(jugador);
            case 6:
                return escurridizo->aplicarEfectoEscurridizo(jugador, tablero, x, y, direccion);
            default:
                return false;
        }
    }

    void mostrarInfo() const {
        if (!poder) {
            std::cout << "PODER INVALIDO" << std::endl;
            return;
        }

        switch (tipoId) {
            case 1: dobleLinea->mostrarInfo();
                break;
            case 2: trampaSecreta->mostrarInfo();
                break;
            case 3: bloqueo->mostrarInfo();
                break;
            case 4: llaveSecreta->mostrarInfo();
                break;
            case 5: pase->mostrarInfo();
                break;
            case 6: escurridizo->mostrarInfo();
                break;
            default: poder->mostrarInfoBase();
                break;
        }
    }

    DobleLinea *getDobleLinea() { return (tipoId == 1) ? dobleLinea : nullptr; }
    TrampaSecreta *getTrampaSecreta() { return (tipoId == 2) ? trampaSecreta : nullptr; }
    Bloqueo *getBloqueo() { return (tipoId == 3) ? bloqueo : nullptr; }
    LlaveSecreta *getLlaveSecreta() { return (tipoId == 4) ? llaveSecreta : nullptr; }
    Pase *getPase() { return (tipoId == 5) ? pase : nullptr; }
    Escurridizo *getEscurridizo() { return (tipoId == 6) ? escurridizo : nullptr; }

private:
    void inicializarNulos() {
        if (tipoId != 1) dobleLinea = nullptr;
        if (tipoId != 2) trampaSecreta = nullptr;
        if (tipoId != 3) bloqueo = nullptr;
        if (tipoId != 4) llaveSecreta = nullptr;
        if (tipoId != 5) pase = nullptr;
        if (tipoId != 6) escurridizo = nullptr;
    }

    void limpiar() {
        delete dobleLinea;
        delete trampaSecreta;
        delete bloqueo;
        delete llaveSecreta;
        delete pase;
        delete escurridizo;

        dobleLinea = nullptr;
        trampaSecreta = nullptr;
        bloqueo = nullptr;
        llaveSecreta = nullptr;
        pase = nullptr;
        escurridizo = nullptr;
        poder = nullptr;
        tipoId = -1;
    }
};


#endif //PRACTICA1_EDD_POWERUPWRAPPER_H
