#ifndef FRAGATA_H
#define FRAGATA_H
#include "Barcos/barco.h"

namespace Navio {

class Fragata : public Barco {
public:
    Fragata(){}

    Fragata(int x, int y, char orientacion) : Barco(x, y, 2, orientacion, (char*)"Fragata") {
        this->codigo = Codigo::Fragata;
    }

    ~Fragata(){}
};

#endif // FRAGATA_H

}
