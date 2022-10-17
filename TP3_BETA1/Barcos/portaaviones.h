#ifndef PORTAAVIONES_H
#define PORTAAVIONES_H
#include "Barcos/barco.h"

namespace Navio {

class Portaaviones : public Barco {
public:
  Portaaviones(){}

  Portaaviones(int x, int y, char orientacion) : Barco(x, y, 5, orientacion, (char*)"Portaavion") {
    this->codigo = Codigo::Portaaviones;
  }

  ~Portaaviones(){}
};

#endif // PORTAAVIONES_H

}
