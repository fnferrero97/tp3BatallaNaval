#include "tablerobarcos.h"


TableroBarcos::TableroBarcos(int dimension, int maxBarcos) : Tablero(dimension) {
  this->cantBarcos = 0;
  this->maxBarcos = maxBarcos;
  this->randomRange = new RandomRange();
}

bool TableroBarcos::sePuedeAgregar(Barco barco) {
  if ((barco.getX() < 0 || barco.getY() < 0) ||
      (barco.getX() > dimension || barco.getY() > dimension))
    return false;

  if ((barco.getOrientacion() == 'H' &&
       barco.getX() + barco.getTamanio() > dimension) ||
      (barco.getOrientacion() == 'V' &&
       barco.getY() + barco.getTamanio() > dimension))
    return false;

  int inicioI, finalI;
  int inicioJ, finalJ;

  if (barco.getOrientacion() == 'H') {
    inicioI = (barco.getY() - 1) < 0 ? 0 : -1;
    finalI = (barco.getY() + barco.getTamanio()) > dimension - 1 ? 0 : 1;
    inicioJ = barco.getX() - 1 < 0 ? barco.getX() : barco.getX() - 1;
    finalJ = (barco.getX() + barco.getTamanio()) + 1 > dimension - 1 ? barco.getX() + barco.getTamanio() : barco.getX() + barco.getTamanio() + 1;

    for (int i = inicioI; i <= finalI; ++i) {
      for (int j = inicioJ; j < finalJ; j++) {
        if (matriz[j][barco.getY() + i] != Codigo::Agua)
          return false;
      }
    }
  }
  if (barco.getOrientacion() == 'V') {
    inicioI = (barco.getX() - 1) < 0 ? 0 : -1;
    finalI = (barco.getX() + barco.getTamanio()) > dimension - 1 ? 0 : 1;
    inicioJ = barco.getY() - 1 < 0 ? barco.getY() : barco.getY() - 1;
    finalJ = (barco.getY() + barco.getTamanio()) + 1 > dimension - 1 ? barco.getY() + barco.getTamanio() : barco.getY() + barco.getTamanio() + 1;

    for (int i = inicioI; i <= finalI; i++) {
      for (int j = inicioJ; j < finalJ; j++) {
        if (matriz[barco.getX() + i][j] != Codigo::Agua)
          return false;
      }
    }
  }
  return true;
}

bool TableroBarcos::agregarBarco(Barco barco) {
  if (!this->sePuedeAgregar(barco) || (this->cantBarcos > this->maxBarcos))
    return false;

  Barco* upcastingBarco = new Barco(barco);
  this->barcos.push_back(upcastingBarco);

  if (barco.getOrientacion() == 'H') {
    for (int i = barco.getX(); i < barco.getX() + barco.getTamanio(); i++) {
      matriz[i][barco.getY()] = barco.getCodigo();
    }
  }
  if (barco.getOrientacion() == 'V') {
    for (int i = barco.getY(); i < barco.getY() + barco.getTamanio(); i++) {
      matriz[barco.getX()][i] = barco.getCodigo();
    }
  }

  cantBarcos++;
  return true;
}

bool TableroBarcos::recibirAtaque(int x, int y) {
  if (!this->verificarCoordenadas(x, y)) return false;

  if (this->matriz[x][y] == Codigo::Dañado) return false;

  int posEnCuerpo = 0;
  this->matriz[x][y] = Codigo::Ataque;

  for (int i = 0; i < cantBarcos; i++) {
    if (barcos[i]->getOrientacion() == 'H' && (y == barcos[i]->getY()) && (x >= barcos[i]->getX() && x <= barcos[i]->getX() + barcos[i]->getTamanio())) {
      posEnCuerpo = (x - barcos[i]->getX());
      barcos[i]->golpe(posEnCuerpo);
      this->matriz[x][y] = Codigo::Dañado;
      return true;
    }

    if (barcos[i]->getOrientacion() == 'V' && (x == barcos[i]->getX()) && (y >= barcos[i]->getY() && y <= barcos[i]->getY() + barcos[i]->getTamanio())) {
      posEnCuerpo = (y - barcos[i]->getY());
      barcos[i]->golpe(posEnCuerpo);
      this->matriz[x][y] = Codigo::Dañado;
      return true;
    }
  }
  return false;
}

bool TableroBarcos::gameOver() {
  int barcosMuertos = 0;
  for (int i = 0; i < cantBarcos; i++) {
    if (this->barcos[i]->getGolpes() == this->barcos[i]->getTamanio())
      barcosMuertos++;
  }
  return (barcosMuertos == maxBarcos);
}

void TableroBarcos::info(bool info) {

    if(!info){
        std::cout << "TUS BARCOS\n";
        for (int i = 0; i < cantBarcos; i++) {
            Barco* barco = barcos[i];
            std::cout << std::left << std::setw(15) << std::setfill(' ') << barco->getNombre();
            std::cout << "(X: " << barco->getX() << ", Y: " << barco->getY() << ") - " << std::left << std::setw(3) << std::setfill(' ');
            if (!barco->isMuerto())
                std::cout << "Vida: " << (barco->getTamanio() - barco->getGolpes()) << "/" << barco->getTamanio() << " ";
            else
                std::cout << "HUNDIDO!";
            std::cout << "\n";
        }
    }

    if(info){
        std::cout << "BARCOS ENEMIGOS\n";
        for (int i = 0; i < cantBarcos; i++) {
            Barco* barco = barcos[i];
            std::cout << std::left << std::setw(15) << std::setfill(' ') << barco->getNombre();
            std::cout << std::left << std::setw(5) << std::setfill(' ');
            if (!barco->isMuerto())
                std::cout << "A FLOTE";
            else
                std::cout << "HUNDIDO!";
            std::cout << "\n";
        }
    }

}

std::vector<Barco*> TableroBarcos::getBarcos() const{
    return this->barcos;
}

int TableroBarcos::getCantBarcos() const{
    return cantBarcos;
}

void TableroBarcos::moverLanchas() {
  for (int i = 0; i < maxBarcos; ++i) {
    Barco* barcoAVerificar = this->barcos[i];
    if (barcoAVerificar->getCodigo() == 6 && !barcoAVerificar->isMuerto()) {
      int anteriorX = barcoAVerificar->getX();
      int anteriorY = barcoAVerificar->getY();
      int newX = randomRange->get(0, this->dimension - 1);
      int newY = randomRange->get(0, this->dimension - 1);

      barcoAVerificar->setX(newX);
      barcoAVerificar->setY(newY);

      while (!this->verificarCoordenadas(newX, newY) || !this->sePuedeAgregar(*barcoAVerificar)) {
        newX = randomRange->get(0, this->dimension - 1);
        newY = randomRange->get(0, this->dimension - 1);
        barcoAVerificar->setX(newX);
        barcoAVerificar->setY(newY);
      }

      this->cambiarCasilla(anteriorX, anteriorY, Codigo::Agua);
      this->cambiarCasilla(newX, newY, Codigo::Lancha);
    }
  }
}
