#ifndef BARCO_H
#define BARCO_H
#include "Enums/info.h"
#include <vector>

class Barco {
protected:
  int x;
  int y;
  int tamanio;
  int golpes;
  int codigo;
  char orientacion;
  char* nombre;
  bool muerto;
  std::vector<Codigo> cuerpo;

public:
  Barco(){}
  Barco(int, int, int, char, char*);
  ~Barco();

  virtual bool golpe(int);
  int getX() const;
  int getY() const;
  int getTamanio() const;
  char getOrientacion() const;
  char* getNombre() const;
  int getCodigo() const;
  int getGolpes() const;
  bool isMuerto() const;
  void setX(int newX);
  void setY(int newY);
  std::vector<Codigo> inicializaCuerpo();
};


#endif // BARCO_H
