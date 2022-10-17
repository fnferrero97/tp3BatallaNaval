#ifndef JUEGO_H
#define JUEGO_H
#include "Enums/barcos.h"
#include "Enums/info.h"
#include "Enums/randomrange.h"
#include "Jugador/jugador.h"
#include <vector>

class Juego {
private:
  class Jugador* jugador;
  class Jugador* IA;
  RandomRange* randomRange;
  int dimensiones;
  int maxBarcos;
  std::vector<int> barcosElegidosJugador;

public:
  Juego(int, int);
  ~Juego(){}

  void inicializarConfiguracion();

  // Colocacion de barcos
  bool colocarBarcosManual(int, int, int, char);
  bool colocarBarcosAleatorio(int);
  bool colocarBarcos(class Jugador*, int, int, int, char);

  // Ataques
  bool atacarIA(int, int);
  bool atacarJugador();

  // mover la lancha en cada turno
  void moverLanchas();

  class Jugador* getJugador() const;
};

#endif // JUEGO_H
