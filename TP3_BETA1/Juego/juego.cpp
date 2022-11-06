#include "juego.h"

Juego::Juego(int dimensiones, int maxBarcos) {
  this->dimensiones = dimensiones;
  this->maxBarcos = maxBarcos;
  this->inicializarConfiguracion();
  this->randomRange = new RandomRange();
}

void Juego::inicializarConfiguracion() {
  this->jugador =
      new class Jugador(this->dimensiones, this->maxBarcos, (char *)"Jugador");
  this->IA =
      new class Jugador(this->dimensiones, this->maxBarcos, (char *)"IA");
}

bool Juego::colocarBarcosManual(int opcionBarco, int x, int y,
                                char orientacion) {
  bool colocacionExitosa =
      this->colocarBarcos(this->jugador, opcionBarco, x, y, orientacion);
  if (colocacionExitosa)
    this->barcosElegidosJugador.push_back(opcionBarco);

  return colocacionExitosa;
}

bool Juego::colocarBarcosAleatorio(int turno) {
  int i = 0;
  bool colocacionExitosa;

  while (i < maxBarcos) {
    int x = randomRange->get(0, this->dimensiones - 1);
    int y = randomRange->get(0, this->dimensiones - 1);
    int opcionBarco = randomRange->get(1, 5);
    char orientacion = randomRange->get(0, 2) == 1 ? 'H' : 'V';

    class Jugador *jugadorConTurno = (turno == 0) ? this->jugador : this->IA;

    if (turno == Turno::IA) {
      colocacionExitosa = this->colocarBarcos(
          jugadorConTurno, this->barcosElegidosJugador[i], x, y, orientacion);
    } else {
      colocacionExitosa =
          this->colocarBarcos(jugadorConTurno, opcionBarco, x, y, orientacion);
    }

    if (colocacionExitosa) {
      i++;
    }

    if (colocacionExitosa && (turno == Turno::Jugador)) {
      this->barcosElegidosJugador.push_back(opcionBarco);
    }
  }
  return true;
}

bool Juego::colocarBarcos(class Jugador *jugadorConTurno, int opcion, int x,
                          int y, char orientacion) {

  switch (opcion) {
  case 1: {
    Barco *cru = new Navio::Crucero(x, y, orientacion);
    return jugadorConTurno->agregarBarco(cru);
  } break;
  case 2: {
    Barco *des = new Navio::Destructor(x, y, orientacion);
    return jugadorConTurno->agregarBarco(des);
  } break;
  case 3: {
    Barco *fra = new Navio::Fragata(x, y, orientacion);
    return jugadorConTurno->agregarBarco(fra);
  } break;
  case 4: {
    Barco *lancha = new Navio::Lancha(x, y, orientacion);
    this->jugador->getTableroBarcos()->setTieneLancha(true);
    this->IA->getTableroBarcos()->setTieneLancha(true);
    return jugadorConTurno->agregarBarco(lancha);
  } break;
  case 5: {
    Barco *porta = new Navio::Portaaviones(x, y, orientacion);
    return jugadorConTurno->agregarBarco(porta);
  } break;
  case 6: {
    Barco *sub = new Navio::Submarino(x, y, orientacion);
    return jugadorConTurno->agregarBarco(sub);
  } break;
  default:
    return false;
  }
}

bool Juego::atacarIA(int x, int y) {
  jugador->marcarAtaque(x, y);
  this->ataques.push_back({x, y});
  return IA->recibirAtaque(x, y);
}

bool Juego::atacarJugador(int x, int y) {
  IA->marcarAtaque(x, y);
  this->ataques.push_back({x, y});
  return jugador->recibirAtaque(x, y);
}

void Juego::moverLanchas() {
  this->jugador->moverLanchas();
  this->IA->moverLanchas();
}

class Jugador *Juego::getJugador() const {
  return jugador;
}

class Jugador *Juego::getIA() const {
  return IA;
}

RandomRange *Juego::getRandomRange() const { return randomRange; }

const std::vector<std::pair<int, int>> &Juego::getAtaques() const {
  return ataques;
}

int Juego::getMaxBarcos() const { return maxBarcos; }

void Juego::setMaxBarcos(int newMaxBarcos) { maxBarcos = newMaxBarcos; }
