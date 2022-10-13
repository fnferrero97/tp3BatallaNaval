#include "juego.h"

Juego::Juego(int dimensiones, int maxBarcos) {
    this->dimensiones = dimensiones;
    this->maxBarcos = maxBarcos;
    this->inicializarConfiguracion();
    this->randomRange = new RandomRange();
}

void Juego::inicializarConfiguracion() {
    this->jugador = new class Jugador(this->dimensiones, this->maxBarcos, (char*)"Jugador");
    this->IA = new class Jugador(this->dimensiones, this->maxBarcos, (char*)"IA");
}


bool Juego::colocarBarcosManual(int opcionBarco, int x, int y, char orientacion) {
        bool colocacionExitosa = this->colocarBarcos(this->jugador, opcionBarco, x, y, orientacion);
        if (colocacionExitosa) this->barcosElegidosJugador.push_back(opcionBarco);

    return colocacionExitosa;
}

bool Juego::colocarBarcosAleatorio(int turno) {
    int i = 0;
    bool colocacionExitosa;
    
    while (i < maxBarcos) {
        int opcionBarco = randomRange->get(0, 6);
        int x = randomRange->get(0, this->dimensiones - 1);
        int y = randomRange->get(0, this->dimensiones - 1);
        char orientacion = randomRange->get(0, 2) == 1 ? 'H' : 'V';
        
        class Jugador* jugadorConTurno = (turno == 0) ? this->jugador : this->IA;

        if (turno == Turno::IA){
            colocacionExitosa = this->colocarBarcos(jugadorConTurno, this->barcosElegidosJugador[i], x, y, orientacion);
        } else {
            colocacionExitosa = this->colocarBarcos(jugadorConTurno, opcionBarco, x, y, orientacion);
        }
        
        if (colocacionExitosa) {
            i++;
        }
        
        if (colocacionExitosa && (turno == Turno::Jugador)){
            this->barcosElegidosJugador.push_back(opcionBarco);
        }
        
    }
    return true;
}

bool Juego::colocarBarcos(class Jugador* jugadorConTurno, int opcion, int x, int y, char orientacion) {
      
    switch (opcion) {
    case 1: {
        Navio::Crucero cru(x, y, orientacion);
        return jugadorConTurno->agregarBarco(cru);
    } break;
    case 2: {

        Navio::Destructor des(x, y, orientacion);
        return jugadorConTurno->agregarBarco(des);
    } break;
    case 3: {
        Navio::Fragata fra(x, y, orientacion);
        return jugadorConTurno->agregarBarco(fra);
    } break;
    case 4: {
        Navio::Lancha lancha(x, y, orientacion);
        return jugadorConTurno->agregarBarco(lancha);
    } break;
    case 5: {

        Navio::Submarino sub(x, y, orientacion);
        return jugadorConTurno->agregarBarco(sub);

    } break;
    case 6: {
        Navio::Portaaviones porta(x, y, orientacion);
        return jugadorConTurno->agregarBarco(porta);
    } break;
    default:
        return false;
    }
}

bool Juego::atacarIA(int x, int y) {
    jugador->marcarAtaque(x, y);
    return IA->recibirAtaque(x, y);
}

bool Juego::atacarJugador() {
    int x = randomRange->get(0, this->dimensiones - 1);
    int y = randomRange->get(0, this->dimensiones - 1);
    IA->marcarAtaque(x, y);
    return jugador->recibirAtaque(x, y);
}

void Juego::moverLanchas() {
    this->jugador->moverLanchas();
    this->IA->moverLanchas();
}

class Jugador* Juego::getJugador() const{
    return jugador;
}
