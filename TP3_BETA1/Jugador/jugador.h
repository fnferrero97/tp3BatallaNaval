#ifndef JUGADOR_H
#define JUGADOR_H
#include "Tablero/tableroataques.h"
#include "Tablero/tablerobarcos.h"

class Jugador {
private:
  TableroBarcos* tableroBarcos;
  TableroAtaques* tableroAtaques;
  Jugador* oponente;
  char* nombre;
  int dimensiones;

public:
  Jugador() {}
  Jugador(int, int, char *);
  ~Jugador() {}

  void dibujar(bool = true);
  bool agregarBarco(Barco*);
  char* getNombre() const;
  bool isGameOver();
  bool recibirAtaque(int, int);
  bool marcarAtaque(int, int);
  void moverLanchas();
  TableroBarcos* getTableroBarcos() const;
  TableroAtaques* getTableroAtaques() const;
};

#endif // JUGADOR_H
