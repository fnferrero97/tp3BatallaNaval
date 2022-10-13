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
    int cantBarcos;
    int maxBarcos;
    std::vector<Barco*> barcos;
    RandomRange* randomRange;

public:
    TableroBarcos();
    TableroBarcos(int, int);
    ~TableroBarcos(){}

    bool sePuedeAgregar(Barco);
    bool agregarBarco(Barco);
    virtual bool recibirAtaque(int, int);
    bool gameOver();
    void info(bool = false);
    void moverLanchas();
    std::vector<Barco*> getBarcos() const;
    int getCantBarcos() const;
};

#endif // TABLEROBARCOS_H
