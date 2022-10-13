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

bool Tablero::cambiarCasilla(int x, int y, int codCasilla) {
    if ((x >= dimension || y >= dimension) || (x < 0 || y < 0)) return false;
    this->matriz[x][y] = codCasilla;
    return true;
}

int** Tablero::getMatriz() const{
    return matriz;
}

bool Tablero::verificarCoordenadas(int x, int y) {
    return ((x >= 0 && y >= 0) && (x < dimension && y < dimension));
}
