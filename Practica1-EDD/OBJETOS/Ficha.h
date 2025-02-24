//
// Created by alesso on 18/02/25.
//

#ifndef FICHA_H
#define FICHA_H

class Ficha {
public:
    char letra;
    int valor;
    int id;

    Ficha(char letra, int valor);
    Ficha(char letra, int valor, int id);
    char getLetra() const;
    int getValor() const;
    int getId() const;
};


#endif //FICHA_H
