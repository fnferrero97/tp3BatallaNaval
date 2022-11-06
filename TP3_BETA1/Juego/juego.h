#ifndef JUEGO_H
#define JUEGO_H
#include "Enums/barcos.h"
#include "Enums/info.h"
#include "Enums/randomrange.h"
#include "Jugador/jugador.h"
#include <vector>

class Juego {
private:
  class Jugador *jugador;
  class Jugador *IA;
  RandomRange *randomRange;
  int dimensiones;
  int maxBarcos;
  std::vector<int> barcosElegidosJugador;
  std::vector<std::pair<int, int>> ataques;

public:
  Juego(int, int);
  ~Juego() {
    delete this->jugador;
    delete this->IA;
    delete this->randomRange;
  }

  void inicializarConfiguracion();

  // Colocacion de barcos
  bool colocarBarcosManual(int, int, int, char);
  bool colocarBarcosAleatorio(int);
  bool colocarBarcos(class Jugador *, int, int, int, char);

  // Ataques
  bool atacarIA(int, int);
  bool atacarJugador(int, int);

  // mover la lancha en cada turno
  void moverLanchas();

  class Jugador *getJugador() const;
  class Jugador *getIA() const;
  RandomRange *getRandomRange() const;
  const std::vector<std::pair<int, int>> &getAtaques() const;
  int getMaxBarcos() const;
  void setMaxBarcos(int newMaxBarcos);
};

#endif // JUEGO_H
