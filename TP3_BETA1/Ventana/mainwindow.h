#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Enums/barcos.h>
#include <Juego/juego.h>
#include <QFileDialog>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <fstream>
#include <iostream>
#include <time.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void handleButton(int x, int y) {
    auto button = qobject_cast<QPushButton *>(sender());
    button->setDisabled(true);

    bool resultadoAtaqueJugador = this->juego->atacarIA(x, y);
    int xIA = this->juego->getRandomRange()->get(0, this->tamanioMapa - 1);
    int yIA = this->juego->getRandomRange()->get(0, this->tamanioMapa - 1);
    bool resultadoAtaqueIA = this->juego->atacarJugador(xIA, yIA);
    pintarMapa(resultadoAtaqueJugador, button);
    describirAtaque(resultadoAtaqueJugador, x, y, resultadoAtaqueIA, xIA, yIA);

    this->juego->moverLanchas();
    dibujarPremapa();
    listarInfo();

    if (this->juego->getJugador()->isGameOver() ||
        this->juego->getIA()->isGameOver()) {
      // deshabilitarCarga();
      this->juego->getIA()->isGameOver()
          ? QMessageBox::information(this, "JUEGO TERMINADO", "GANASTE!")
          : QMessageBox::information(this, "JUEGO TERMINADO", "PERDISTE!");

      this->esconderTodo();
      this->resetearParametros();

      this->goMenuPrincipal();
    }
  }

  void pintarMapa(bool band, QPushButton *button);
  void crearBarco(int, int, char, int);
  void esconderTodo();
  void crearMapas();
  void setDefaultTexts();
  void describirAtaque(bool, int, int, bool, int, int);
  void setValidators();
  void setContadorBarcos(int, int);
  void listarInfo();
  void dibujarPremapa();
  void moverMapaJugador();
  void deshabilitarCarga();
  void eliminarSubmarino(Barco *, class Jugador *);
  void goMenuPrincipal();
  void resetearParametros();

private slots:
  void on_jugar_clicked();
  void on_nuevoJuego_clicked();
  void on_aniadirBarco_clicked();
  void on_cargarPartida_clicked();
  void on_listaBarcos_currentIndexChanged(int);

  void on_guardarPartida_clicked();

private:
  Ui::MainWindow *ui;
  QPushButton ***buttons;
  QLabel ***labels;
  Juego *juego = nullptr;
  int barcosAgregados = 0;
  int tamanioMapa;
  char *rutaPartidaGuardada = (char *)"partida.dat";
};
#endif // MAINWINDOW_H
