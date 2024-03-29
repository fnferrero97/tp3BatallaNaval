﻿#include "jugador.h"

Jugador::Jugador(int dimensiones, int maxBarcos, char *nombre) {
    this->tableroBarcos = new TableroBarcos(dimensiones, maxBarcos);
    this->tableroAtaques = new TableroAtaques(dimensiones);
    this->nombre = nombre;
    this->dimensiones = dimensiones;
}

bool Jugador::agregarBarco(Barco* barco) {
    return tableroBarcos->agregarBarco(barco);
}

bool Jugador::isGameOver() {
    return this->tableroBarcos->gameOver();
}

bool Jugador::recibirAtaque(int x, int y) {
    return this->tableroBarcos->recibirAtaque(x, y);
}

bool Jugador::marcarAtaque(int x, int y) {
    return this->tableroAtaques->recibirAtaque(x, y);
}

void Jugador::moverLanchas() {
    this->tableroBarcos->moverLanchas();
}

TableroBarcos* Jugador::getTableroBarcos() const {
    return tableroBarcos;
}

TableroAtaques* Jugador::getTableroAtaques() const {
    return tableroAtaques;
}

char* Jugador::getNombre() const {
    return this->nombre;
}
