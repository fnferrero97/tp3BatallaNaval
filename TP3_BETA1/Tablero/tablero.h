﻿#ifndef TABLERO_H
#define TABLERO_H
#include "Enums/info.h"
#include <iomanip>
#include <iostream>

class Tablero {
protected:
    int dimension;
    int** matriz;

public:
    Tablero(){}
    Tablero(int);
    ~Tablero(){}

    int** inicializarMatriz(int);
    bool cambiarCasilla(int, int, int);
    bool verificarCoordenadas(int, int);
    int** getMatriz() const;
};

#endif // TABLERO_H
