#ifndef CRUCERO_H
#define CRUCERO_H
#include "Barcos/barco.h"

namespace Navio {

class Crucero : public Barco {
public:
  Crucero(){}

  Crucero(int x, int y, char orientacion) : Barco(x, y, 3, orientacion, (char*)"Crucero") {
    this->codigo = Codigo::Crucero;
  }

  ~Crucero(){}
};

#endif // CRUCERO_H

}
