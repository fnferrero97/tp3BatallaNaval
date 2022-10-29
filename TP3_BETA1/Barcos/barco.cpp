#include "Barcos/barco.h"

Barco::Barco(int x, int y, int tamanio, char orientacion, char *nombre) {
  this->x = x;
  this->y = y;
  this->tamanio = tamanio;
  this->orientacion = orientacion;
  this->nombre = nombre;
  this->cuerpo = inicializaCuerpo();
}

Barco::~Barco() {}

std::vector<Codigo> Barco::inicializaCuerpo() {
  std::vector<Codigo> cuerpo(this->tamanio, Codigo::Sano);
  return cuerpo;
}

bool Barco::golpe(int x) {
  // FIJARSE PORQUE ESTO NO ANDA CON POLIMORFISMO
  this->cuerpo[x] = Codigo::Dañado;
  this->golpes++;

  if (this->golpes == this->tamanio) {
    this->muerto = true;
    return true;
  }
  return false;
}

int Barco::getX() const { return this->x; }

int Barco::getY() const { return this->y; }

int Barco::getTamanio() const { return this->tamanio; }

char Barco::getOrientacion() const { return this->orientacion; }

char *Barco::getNombre() const { return this->nombre; }

int Barco::getCodigo() const { return this->codigo; }

int Barco::getGolpes() const { return golpes; }

BarcoStr Barco::getStruct() {
  BarcoStr barcoStr{this->codigo, this->getX(), this->y, this->orientacion};
  return barcoStr;
}

bool Barco::isMuerto() const { return this->muerto; }

void Barco::setX(int x) { this->x = x; }

void Barco::setY(int y) { this->y = y; }

void Barco::setHundido(bool hundido) { this->hundido = hundido; }

bool Barco::isHundido() { return this->hundido; }
