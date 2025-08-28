//
// Created by alesso on 5/08/25.
//

#include "ListaEnlazada.h"

ListaEnlazadaTablero::~ListaEnlazadaTablero() {
    if (inicio == nullptr) {
        return;
    }

    NodoTablero *filaActual = inicio;

    while (filaActual != nullptr) {
        NodoTablero *siguienteFila = filaActual->abajoNodo;

        NodoTablero *nodoActual = filaActual;
        while (nodoActual != nullptr) {
            NodoTablero *siguienteNodo = nodoActual->siguiente;
            delete nodoActual;
            nodoActual = siguienteNodo;
        }

        filaActual = siguienteFila;
    }

    inicio = nullptr;
}

void ListaEnlazadaTablero::construirTablero() {
    NodoTablero *filaAnterior = nullptr;
    for (int i = 0; i < filas; i++) {
        NodoTablero *filaInicio = nullptr;
        NodoTablero *nodoAnterior = nullptr;

        for (int j = 0; j < columnas; j++) {
            NodoTablero *nuevo = new NodoTablero(i, j);
            if (j == 0) filaInicio = nuevo;
            if (nodoAnterior) nodoAnterior->siguiente = nuevo;
            if (filaAnterior) {
                NodoTablero *arriba = filaAnterior;
                for (int k = 0; k < j; k++) arriba = arriba->siguiente;
                arriba->abajoNodo = nuevo;
            }
            nodoAnterior = nuevo;
        }
        if (i == 0) inicio = filaInicio;
        filaAnterior = filaInicio;
    }
}

bool ListaEnlazadaTablero::marcarLinea(int x, int y, char direccion, char inicial) {
    NodoTablero *actual = obtenerNodo(x, y);
    if (!actual) return false;

    bool cerro = false;
    int cuadrosCerrados = 0;

    if (direccion == 'H' && actual->siguiente) {
        if (actual->derecha) {
            std::cout << "YA EXISTE ESA LINEA NO PUEDES SOBREPONER"  << std::endl;
            return false;
        }
        actual->derecha = true;

        if (x > 0 && y < columnas - 1 && cuadroCerrado(x - 1, y)) {
            marcarCuadro(x - 1, y, inicial);
            cuadrosCerrados++;
        }

        if (x < filas - 1 && y < columnas - 1 && cuadroCerrado(x, y)) {
            marcarCuadro(x, y, inicial);
            cuadrosCerrados++;
        }

        cerro = cuadrosCerrados > 0;
    } else if (direccion == 'V' && actual->abajoNodo) {
        if (actual->abajo) {
            std::cout << "YA EXISTE ESA LINEA NO PUEDES SOBREPONER" << std::endl;
            return false;
        }
        actual->abajo = true;

        if (y > 0 && x < filas - 1 && cuadroCerrado(x, y - 1)) {
            marcarCuadro(x, y - 1, inicial);
            cuadrosCerrados++;
        }

        if (y < columnas - 1 && x < filas - 1 && cuadroCerrado(x, y)) {
            marcarCuadro(x, y, inicial);
            cuadrosCerrados++;
        }

        cerro = cuadrosCerrados > 0;
    }

    if (cerro) {
        std::cout << "CUADRO CERRADO" << cuadrosCerrados << std::endl;
    }

    return cerro;
}

NodoTablero *ListaEnlazadaTablero::obtenerNodo(int x, int y) {
    NodoTablero *temp = inicio;
    for (int i = 0; i < x && temp; i++) temp = temp->abajoNodo;
    for (int j = 0; j < y && temp; j++) temp = temp->siguiente;
    return temp;
}

void ListaEnlazadaTablero::mostrarTablero() {
    NodoTablero *fila = inicio;

    std::cout << "   ";
    for (int j = 0; j < columnas; j++) {
        std::cout << " " << j << "  ";
    }
    std::cout << "\n";

    int filaActual = 0;
    while (fila) {
        std::cout << filaActual << "  ";
        NodoTablero *actual = fila;
        while (actual) {
            std::cout << "0";
            std::cout << (actual->derecha ? "---" : "   ");
            actual = actual->siguiente;
        }
        std::cout << "\n";

        if (fila->abajoNodo) {
            std::cout << "   ";
            actual = fila;
            while (actual) {
                std::cout << (actual->abajo ? "|" : " ");

                if (actual->dueño != ' ') {
                    std::cout << " " << actual->dueño << " ";
                } else {
                    std::cout << "   ";
                }

                actual = actual->siguiente;
            }
            std::cout << "\n";
        }

        fila = fila->abajoNodo;
        filaActual++;
    }
    std::cout << "\n";
}

bool ListaEnlazadaTablero::cuadroCerrado(int x, int y) {
    if (x < 0 || y < 0 || x >= filas - 1 || y >= columnas - 1) {
        return false;
    }

    NodoTablero *esquinaSuperiorIzq = obtenerNodo(x, y);
    if (!esquinaSuperiorIzq) return false;

    NodoTablero *esquinaSuperiorDer = esquinaSuperiorIzq->siguiente;
    NodoTablero *esquinaInferiorIzq = esquinaSuperiorIzq->abajoNodo;

    if (!esquinaSuperiorDer || !esquinaInferiorIzq) return false;

    NodoTablero *esquinaInferiorDer = esquinaInferiorIzq->siguiente;
    if (!esquinaInferiorDer) return false;

    bool lineaSuperior = esquinaSuperiorIzq->derecha;
    bool lineaInferior = esquinaInferiorIzq->derecha;
    bool lineaIzquierda = esquinaSuperiorIzq->abajo;
    bool lineaDerecha = esquinaSuperiorDer->abajo;

    return lineaSuperior && lineaInferior && lineaIzquierda && lineaDerecha;
}

void ListaEnlazadaTablero::marcarCuadro(int x, int y, char inicial) {
    NodoTablero *nodo = obtenerNodo(x, y);
    if (nodo && nodo->dueño == ' ') {
        nodo->dueño = inicial;
        std::cout << "CUADRO MARCADO (" << x << "," << y << ") PARA JUGADOR: " << inicial << std::endl;
    }
}

int ListaEnlazadaTablero::contarCuadros(char jugador) {
    int contador = 0;
    NodoTablero *fila = inicio;

    for (int i = 0; i < filas - 1 && fila; i++) {
        NodoTablero *actual = fila;
        for (int j = 0; j < columnas - 1 && actual; j++) {
            if (actual->dueño == jugador) {
                contador++;
            }
            actual = actual->siguiente;
        }
        fila = fila->abajoNodo;
    }

    return contador;
}

bool ListaEnlazadaTablero::juegoTerminado() {
    NodoTablero *fila = inicio;

    for (int i = 0; i < filas - 1 && fila; i++) {
        NodoTablero *actual = fila;
        for (int j = 0; j < columnas - 1 && actual; j++) {
            if (actual->dueño == ' ') {
                return false;
            }
            actual = actual->siguiente;
        }
        fila = fila->abajoNodo;
    }

    return true;
}

bool ListaEnlazadaTablero::agregarFilaAlFinal() {
    if (filas == 0 || columnas == 0) {
        std::cout << "SIN TABLERO" << std::endl;
        return false;
    }

    NodoTablero *ultimaFila = inicio;
    for (int i = 0; i < filas - 1; i++) {
        if (!ultimaFila->abajoNodo) break;
        ultimaFila = ultimaFila->abajoNodo;
    }

    NodoTablero *nuevaFilaInicio = nullptr;
    NodoTablero *nodoAnterior = nullptr;

    for (int j = 0; j < columnas; j++) {
        NodoTablero *nuevo = new NodoTablero(filas, j);

        if (j == 0) {
            nuevaFilaInicio = nuevo;
        }

        if (nodoAnterior) {
            nodoAnterior->siguiente = nuevo;
        }

        NodoTablero *nodoArriba = ultimaFila;
        for (int k = 0; k < j; k++) {
            nodoArriba = nodoArriba->siguiente;
        }
        nodoArriba->abajoNodo = nuevo;

        nodoAnterior = nuevo;
    }

    filas++;
    std::cout << "NUEVA FILA AGREGADA. TABLERO DE: " << filas << "x" << columnas << std::endl;
    return true;
}

bool ListaEnlazadaTablero::agregarColumnaAlFinal() {
    if (filas == 0 || columnas == 0) {
        std::cout << "SIN TABLERO" << std::endl;
        return false;
    }

    NodoTablero *filaActual = inicio;

    for (int i = 0; i < filas; i++) {
        NodoTablero *ultimoNodo = filaActual;
        for (int j = 0; j < columnas - 1; j++) {
            ultimoNodo = ultimoNodo->siguiente;
        }

        NodoTablero *nuevo = new NodoTablero(i, columnas);
        ultimoNodo->siguiente = nuevo;

        if (i > 0) {
            NodoTablero *filaAnterior = inicio;
            for (int k = 0; k < i - 1; k++) {
                filaAnterior = filaAnterior->abajoNodo;
            }

            NodoTablero *nodoArriba = filaAnterior;
            for (int k = 0; k < columnas; k++) {
                nodoArriba = nodoArriba->siguiente;
            }

            nodoArriba->abajoNodo = nuevo;
        }

        filaActual = filaActual->abajoNodo;
    }

    columnas++;
    std::cout << "NUEVA COLUMNA. TABLERO DE: " << filas << "x" << columnas << std::endl;
    return true;
}

bool ListaEnlazadaTablero::eliminarUltimaFila() {
    if (filas <= 2) {
        std::cout << "NO SE PUEDE ELIMINAR. MINIMO DE DOS FILAS" << std::endl;
        return false;
    }

    NodoTablero *penultimaFila = inicio;
    for (int i = 0; i < filas - 2; i++) {
        penultimaFila = penultimaFila->abajoNodo;
    }

    NodoTablero *ultimaFila = penultimaFila->abajoNodo;

    NodoTablero *nodoActual = ultimaFila;
    while (nodoActual != nullptr) {
        NodoTablero *siguiente = nodoActual->siguiente;
        delete nodoActual;
        nodoActual = siguiente;
    }

    NodoTablero *temp = penultimaFila;
    while (temp != nullptr) {
        temp->abajoNodo = nullptr;
        temp = temp->siguiente;
    }

    filas--;
    std::cout << "ULTIMA FILA ELIMINADA. TABLERO DE: " << filas << "x" << columnas << std::endl;
    return true;
}

bool ListaEnlazadaTablero::eliminarUltimaColumna() {
    if (columnas <= 2) {
        std::cout << "NO SE PUEDE ELIMINAR. MINIMO DE DOS COLUMNAS" << std::endl;
        return false;
    }

    NodoTablero *filaActual = inicio;

    for (int i = 0; i < filas; i++) {
        NodoTablero *penultimoNodo = filaActual;
        for (int j = 0; j < columnas - 2; j++) {
            penultimoNodo = penultimoNodo->siguiente;
        }

        NodoTablero *ultimoNodo = penultimoNodo->siguiente;
        delete ultimoNodo;
        penultimoNodo->siguiente = nullptr;

        filaActual = filaActual->abajoNodo;
    }

    columnas--;
    std::cout << "COLUMNA ELIMINADA. TABLERO DE: " << filas << "x" << columnas << std::endl;
    return true;
}

bool ListaEnlazadaTablero::eliminarNodo(int x, int y) {
    if (!estaEnBorde(x, y)) {
        std::cout << "SOLO SE ELIMINAN NODOS EN BORDES " << std::endl;
        return false;
    }

    if ((x == 0 || x == filas - 1) && filas <= 2) {
        std::cout << "NO SE PUEDE ELIMINAR" << std::endl;
        return false;
    }

    if ((y == 0 || y == columnas - 1) && columnas <= 2) {
        std::cout << "NO SE PUEDE ELIMINAR" << std::endl;
        return false;
    }

    if ((x == 0 || x == filas - 1) && (y == 0 || y == columnas - 1)) {
        if (x == filas - 1) {
            return eliminarUltimaFila();
        } else if (y == columnas - 1) {
            return eliminarUltimaColumna();
        }
    }

    std::cout << "NODO EN POSICION (" << x << ", " << y << ") ESTA EN EL BORDE PERO NO SE PUEDE ELIMINAR" << std::endl;
    return false;
}

bool ListaEnlazadaTablero::estaEnBorde(int x, int y) {
    if (x < 0 || x >= filas || y < 0 || y >= columnas) {
        return false;
    }

    return (x == 0 || x == filas - 1 || y == 0 || y == columnas - 1);
}

bool ListaEnlazadaTablero::esSeguroEliminar(int x, int y) {
    NodoTablero *nodo = obtenerNodo(x, y);
    if (!nodo) return false;

    if (nodo->derecha || nodo->abajo) {
        return false;
    }

    if (x > 0) {
        NodoTablero *nodoArriba = obtenerNodo(x - 1, y);
        if (nodoArriba && nodoArriba->abajo) return false;
    }

    if (y > 0) {
        NodoTablero *nodoIzq = obtenerNodo(x, y - 1);
        if (nodoIzq && nodoIzq->derecha) return false;
    }

    return true;
}

void ListaEnlazadaTablero::reconstruirConexiones() {
    NodoTablero *filaActual = inicio;

    for (int i = 0; i < filas; i++) {
        NodoTablero *nodoActual = filaActual;

        for (int j = 0; j < columnas; j++) {
            if (nodoActual) {
                nodoActual->x = i;
                nodoActual->y = j;
                nodoActual = nodoActual->siguiente;
            }
        }

        if (filaActual) {
            filaActual = filaActual->abajoNodo;
        }
    }
}
