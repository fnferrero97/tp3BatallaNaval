#ifndef SUBMARINO_H
#define SUBMARINO_H
#include "Barcos/barco.h"

namespace Navio {

class Submarino : public Barco {
public:
    Submarino(){}

    Submarino(int x, int y, char orientacion) : Barco(x, y, 3, orientacion, (char*)"Submarino") {
        this->codigo = Codigo::Submarino;
    }

    ~Submarino(){}

    bool golpe(int);

};

#endif // SUBMARINO_H

}
