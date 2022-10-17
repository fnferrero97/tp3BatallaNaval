#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <time.h>
#include <Enums/barcos.h>
#include <Juego/juego.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void handleButton(int x, int y) {
        auto button = qobject_cast<QPushButton*>(sender());
        if (button->isEnabled()) {
            button->setDisabled(true);
            button->setStyleSheet(QString("color: #ff0000"));
            bool resultadoAtaque = this->juego->atacarIA(x, y);
            pintarMapa(resultadoAtaque, button);
            describirAtaque(resultadoAtaque, x, y);
        }
    }

    void pintarMapa(bool band, QPushButton* button);
    void crearBarco(int, int, char, int);
    void esconderTodo();
    void crearMapas();
    void setDefaultTexts();
    void describirAtaque(bool, int, int);
    void setValidators();
    void setContadorBarcos(int, int);
    void listarInfo();
    void dibujarPremapa();
    void actualizarMapa();

private slots:
    void on_jugar_clicked();
    void on_nuevoJuego_clicked();
    void on_aniadirBarco_clicked();
    void on_cargarPartida_clicked();
    void on_listaBarcos_currentIndexChanged(int);

private:
    Ui::MainWindow* ui;
    QPushButton*** buttons;
    QLabel*** labels;
    Juego* juego = nullptr;
    int barcosAgregados = 0;
    int** mapita;
};
#endif // MAINWINDOW_H
