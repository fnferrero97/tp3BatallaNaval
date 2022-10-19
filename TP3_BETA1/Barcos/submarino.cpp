#include "Barcos/submarino.h"

namespace Navio {


bool Submarino::golpe(int x){
        if (x == 1) {
            for (int i = 0; i < this->tamanio; i++) {
                this->cuerpo[i] = Codigo::Dañado;
                this->golpes = 3;
                this->muerto = true;
                return true;
            }
        } else {
            this->cuerpo[x] = Codigo::Dañado;
            this->golpes++;
        }
        return false;
    }

}
