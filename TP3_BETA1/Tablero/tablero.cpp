#include "tablero.h"


Tablero::Tablero(int dimension) {
    this->dimension = dimension;
    this->matriz = this->inicializarMatriz(Codigo::Agua);
}

int** Tablero::inicializarMatriz(int codCasilla) {
    int** aux = new int*[dimension];

    for (int i = 0; i < dimension; i++) {
        aux[i] = new int[dimension];
    }

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++)
            aux[i][j] = codCasilla;
    }
    return aux;
}

void Tablero::cambiarCasilla(int x, int y, int codCasilla) {
    this->matriz[x][y] = codCasilla;
}

int** Tablero::getMatriz() const{
    return matriz;
}
