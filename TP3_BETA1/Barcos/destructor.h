#ifndef DESTRUCTOR_H
#define DESTRUCTOR_H
#include "Barcos/barco.h"

namespace Navio {

class Destructor : public Barco {
public:
    Destructor(){}

    Destructor(int x, int y, char orientacion) : Barco(x, y, 4, orientacion, (char*)"Destructor") {
        this->codigo = Codigo::Destructor;
    }

    ~Destructor(){}
};

#endif // DESTRUCTOR_H

}
