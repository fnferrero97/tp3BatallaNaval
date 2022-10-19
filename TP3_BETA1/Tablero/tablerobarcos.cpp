#include "tablerobarcos.h"

TableroBarcos::TableroBarcos(int dimension, int maxBarcos)
    : Tablero(dimension) {
    ;
    this->maxBarcos = maxBarcos;
    this->randomRange = new RandomRange();
}

bool TableroBarcos::sePuedeAgregar(Barco* barco) {
    if (barco->getX() > dimension || barco->getY() > dimension)
        return false;

    if ((barco->getOrientacion() == 'H' && barco->getX() + barco->getTamanio() > dimension) || (barco->getOrientacion() == 'V' &&  barco->getY() + barco->getTamanio() > dimension))
        return false;

    if (barco->getX() == Codigo::Ataque || barco->getY() == Codigo::Ataque || barco->getX() == Codigo::Dañado || barco->getY() == Codigo::Dañado)
        return false;

    int inicioI, finalI;
    int inicioJ, finalJ;

    if (barco->getOrientacion() == 'H') {
        inicioI = (barco->getY() - 1) < 0 ? 0 : -1;
        finalI  = (barco->getY() + barco->getTamanio()) > dimension ? 0 : 1;
        inicioJ = (barco->getX() - 1) < 0 ? barco->getX() : barco->getX() - 1;
        finalJ  = (barco->getX() + barco->getTamanio()) + 1 > dimension - 1 ? barco->getX() + barco->getTamanio() : barco->getX() + barco->getTamanio() + 1;

        for (int i = inicioI; i <= finalI; ++i) {
            for (int j = inicioJ; j < finalJ; j++) {
                if (matriz[j][barco->getY() + i] != Codigo::Agua)
                    return false;
            }
        }
    }

    if (barco->getOrientacion() == 'V') {
        inicioI = (barco->getX() - 1) < 0 ? 0 : -1;
        finalI  = (barco->getX() + barco->getTamanio()) > dimension ? 0 : 1;
        inicioJ = (barco->getY() - 1) < 0 ? barco->getY() : barco->getY() - 1;
        finalJ  = (barco->getY() + barco->getTamanio()) + 1 > dimension - 1 ? barco->getY() + barco->getTamanio() : barco->getY() + barco->getTamanio() + 1;

        for (int i = inicioI; i <= finalI; i++) {
            for (int j = inicioJ; j < finalJ; j++) {
                if (matriz[barco->getX() + i][j] != Codigo::Agua)
                    return false;
            }
        }
    }
    return true;
}

bool TableroBarcos::agregarBarco(Barco* barco) {
    if (!this->sePuedeAgregar(barco) || (this->cantBarcos > this->maxBarcos))
        return false;

    this->barcos.push_back(barco);

    if (barco->getOrientacion() == 'H') {
        for (int i = barco->getX(); i < barco->getX() + barco->getTamanio(); i++) {
            this->matriz[i][barco->getY()] = barco->getCodigo();
        }
    }
    if (barco->getOrientacion() == 'V') {
        for (int i = barco->getY(); i < barco->getY() + barco->getTamanio(); i++) {
            this->matriz[barco->getX()][i] = barco->getCodigo();
        }
    }

    cantBarcos++;
    return true;
}

bool TableroBarcos::recibirAtaque(int x, int y) {
    int posEnCuerpo = 0;

    this->matriz[x][y] = Codigo::Ataque;

    for (int i = 0; i < cantBarcos; i++) {
        if (barcos[i]->getOrientacion() == 'H' && (y == barcos[i]->getY()) && (x >= barcos[i]->getX() && x < barcos[i]->getX() + barcos[i]->getTamanio())) {
            posEnCuerpo = (x - barcos[i]->getX());
            if (barcos[i]->golpe(posEnCuerpo)) this->cantMuertos++;
            this->matriz[x][y] = Codigo::Dañado;
            return true;
        }

        if (barcos[i]->getOrientacion() == 'V' && (x == barcos[i]->getX()) && (y >= barcos[i]->getY() && y < barcos[i]->getY() + barcos[i]->getTamanio())) {
            posEnCuerpo = (y - barcos[i]->getY());
            if (barcos[i]->golpe(posEnCuerpo)) this->cantMuertos++;
            this->matriz[x][y] = Codigo::Dañado;
            return true;
        }
    }
    return false;
}

bool TableroBarcos::gameOver() {
    return this->cantMuertos == maxBarcos;
}

std::vector<Barco*> TableroBarcos::getBarcos() const {
    return this->barcos;
}

int TableroBarcos::getCantBarcos() const {
    return cantBarcos;
}

void TableroBarcos::moverLanchas() {
    if (this->tieneLancha) {
        for (int i = 0; i < maxBarcos; i++) {
            int contador = 0;
            bool bandera = false;
            Barco* barcoAVerificar = this->barcos[i];
            if (barcoAVerificar->getCodigo() == Codigo::Lancha && !barcoAVerificar->isMuerto()) {
                int anteriorX = barcoAVerificar->getX();
                int anteriorY = barcoAVerificar->getY();
                int newX = randomRange->get(0, this->dimension);
                int newY = randomRange->get(0, this->dimension);
                barcoAVerificar->setX(newX);
                barcoAVerificar->setY(newY);

                while (!bandera && contador < 1000) {
                    newX = randomRange->get(0, this->dimension);
                    newY = randomRange->get(0, this->dimension);
                    barcoAVerificar->setX(newX);
                    barcoAVerificar->setY(newY);
                    contador++;
                    bandera = this->sePuedeAgregar(barcoAVerificar);
                }

                if (bandera){
                    this->cambiarCasilla(anteriorX, anteriorY, Codigo::Agua);
                    this->cambiarCasilla(newX, newY, Codigo::Lancha);
                } else {
                    barcoAVerificar->setX(anteriorX);
                    barcoAVerificar->setY(anteriorY);
                }
            }
        }
    }
}

void TableroBarcos::setTieneLancha(bool tieneLancha) {
    this->tieneLancha = tieneLancha;
}
