#ifndef LANCHA_H
#define LANCHA_H
#include "Barcos/barco.h"

namespace Navio {

class Lancha : public Barco {
public:
  Lancha(){}

  Lancha(int x, int y, char orientacion) : Barco(x, y, 1, orientacion, (char*)"Lancha") {
    this->codigo = Codigo::Lancha;
  }

  ~Lancha(){}

  void actualizar(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

#endif // LANCHA_H

}
