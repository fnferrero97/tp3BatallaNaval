#ifndef SUBMARINO_H
#define SUBMARINO_H
#include "barco.h"

namespace Navio {

class Submarino : public Barco {
public:
  Submarino(){}

  Submarino(int x, int y, char orientacion) : Barco(x, y, 3, orientacion, (char*)"Submarino") {
    this->codigo = Codigo::Submarino;
  }

  bool golpe(int x){
      if (x == 1) {
        for (int i = 0; i < this->tamanio; ++i) {
          this->cuerpo[i] = Codigo::Dañado;
          this->golpes = 3;
          return true;
        }
      } else {
          Barco::golpe(x);
      }
      return false;
  }

  ~Submarino(){}
};

#endif // SUBMARINO_H

}
