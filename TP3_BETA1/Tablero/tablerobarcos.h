#ifndef TABLEROBARCOS_H
#define TABLEROBARCOS_H
#include "Barcos/barco.h"
#include "Enums/barcos.h"
#include "Enums/randomrange.h"
#include "Tablero/tablero.h"
#include <vector>
#include <cstdlib>

class TableroBarcos : public Tablero {
private:
    int cantBarcos = 0;
    int maxBarcos;
    int cantMuertos = 0;
    bool tieneLancha = false;
    std::vector<Barco*> barcos;
    RandomRange* randomRange;

public:
    TableroBarcos();
    TableroBarcos(int, int);
    ~TableroBarcos(){}

    bool sePuedeAgregar(Barco);
    bool agregarBarco(Barco);
    bool recibirAtaque(int, int);
    bool gameOver();
    void info(bool = false);
    void moverLanchas();
    std::vector<Barco*> getBarcos() const;
    int getCantBarcos() const;
    void setTieneLancha(bool);
};

#endif // TABLEROBARCOS_H
