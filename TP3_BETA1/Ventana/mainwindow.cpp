﻿#include "Ventana/mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    esconderTodo();
    setDefaultTexts();
    setValidators();
    setWindowIcon(QIcon(":/images/icon.png"));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setDefaultTexts(){
    ui->listaBarcos->setPlaceholderText(QStringLiteral("Elija Barco"));
    ui->listaBarcos->setCurrentIndex(-1);
    ui->tamanioMapa->setPlaceholderText(QStringLiteral("TAMANIO MAPA"));
    ui->cantBarcos->setPlaceholderText(QStringLiteral("CANT BARCOS"));
    ui->posX->setPlaceholderText(QStringLiteral("Y"));
    ui->posY->setPlaceholderText(QStringLiteral("X"));
}

void MainWindow::pintarMapa(bool band, QPushButton* button){
    band ? button->setStyleSheet("background-color:green;") : button->setStyleSheet("background-color:blue;");
}

void MainWindow::describirAtaque(bool ataqueJugador, int x1, int y1, bool ataqueIA, int x2, int y2){
    ataqueJugador ? ui->listaAtaquesJugador->setText(QString::fromStdString("Ataque EXITOSO en coordenadas x: " + std::to_string(x1) + " / y: " + std::to_string(y1))) : ui->listaAtaquesJugador->setText(QString::fromStdString("Ataque FALLIDO en coordenadas x: " + std::to_string(x1) + " / y: " + std::to_string(y1)));
    ataqueIA ? ui->listaAtaquesIA->setText(QString::fromStdString("Ataque EXITOSO en coordenadas x: " + std::to_string(x2) + " / y: " + std::to_string(y2))) : ui->listaAtaquesIA->setText(QString::fromStdString("Ataque FALLIDO en coordenadas x: " + std::to_string(x2) + " / y: " + std::to_string(y2)));
}

void MainWindow::esconderTodo(){
    ui->configJuego->hide();
    ui->mapas->hide();
    ui->ponerBarcos->hide();
}

void MainWindow::on_nuevoJuego_clicked(){
    ui->nuevoJuego->hide();
    ui->cargarPartida->hide();
    ui->configJuego->show();
}

void MainWindow::on_jugar_clicked() {
    if (ui->cantBarcos->text().isEmpty() || ui->tamanioMapa->text().isEmpty()){
        QMessageBox::information(this, "ALERTA", "Los campos no pueden estar vacios!");
    } else {
        this->tamanioMapa = ui->tamanioMapa->text().toInt();
        this->juego = new Juego(this->tamanioMapa, ui->cantBarcos->text().toInt());
        crearMapas();
        ui->configJuego->hide();
        ui->mapas->show();

        if (!this->ui->checkAleatorio->isChecked()) {
            ui->ponerBarcos->show();
            ui->previewBarco->show();
            ui->mapaAtaque->hide();
            ui->listaAtaquesJugador->hide();
            ui->listaAtaquesIA->hide();
            ui->infoBarcos->hide();
            setContadorBarcos(0, ui->cantBarcos->text().toInt());
        } else {
            this->juego->colocarBarcosAleatorio(Turno::Jugador);
            this->juego->colocarBarcosAleatorio(Turno::IA);
            dibujarPremapa();
            listarInfo();
        }
    }
}

void MainWindow::crearMapas(){
    this->buttons = new QPushButton**[this->tamanioMapa];
    this->labels = new QLabel**[this->tamanioMapa];

    for (int i = 0; i < this->tamanioMapa; ++i) {
        this->buttons[i] = new QPushButton*[this->tamanioMapa];
        this->labels[i] = new QLabel*[this->tamanioMapa];

        for (int j = 0; j < this->tamanioMapa; ++j) {
            this->buttons[i][j] = new QPushButton();
            ui->attackGLayout->addWidget(buttons[i][j], i, j);
            connect(buttons[i][j], &QPushButton::released, this,
                    [=]() { handleButton(i, j); });


            this->labels[i][j] = new QLabel("--");
            this->labels[i][j]->setStyleSheet("outline: #87CEEB solid 5px; background-color: #87CEEB;");
            this->labels[i][j]->setAlignment(Qt::AlignCenter);
            ui->mapGLayout->addWidget(labels[i][j], i, j);
        }
    }
}

void MainWindow::listarInfo(){
    ui->infoBarcos->clear();

    ui->infoBarcos->append(QString::fromStdString("TUS BARCOS"));
    for (auto barco : this->juego->getJugador()->getTableroBarcos()->getBarcos()){
        std::string x = std::to_string(barco->getX());
        std::string y = std::to_string(barco->getY());
        std::string tamanio = std::to_string(barco->getTamanio());
        std::string nombre(barco->getNombre());
        std::string vida = std::to_string(barco->getTamanio() - barco->getGolpes());
        if (!barco->isMuerto()){
            ui->infoBarcos->append(QString::fromStdString(nombre + " (X: " + x + ", Y: " + y + ") - Vida: " + vida + "/" + tamanio));
        } else {
            ui->infoBarcos->append(QString::fromStdString(nombre + " (X: " + x + ", Y: " + y + ") - HUNDIDO!"));
        }
    }

    ui->infoBarcos->append(QString::fromStdString("\nBARCOS ENEMIGOS"));
    for (auto barco : this->juego->getIA()->getTableroBarcos()->getBarcos()){
        std::string nombre(barco->getNombre());
        if (!barco->isMuerto()){
            ui->infoBarcos->append(QString::fromStdString(nombre + " - A FLOTE!"));
        } else {
            ui->infoBarcos->append(QString::fromStdString(nombre + " - HUNDIDO!"));
        }
    }
}

void MainWindow::dibujarPremapa(){
    int** matriz = this->juego->getJugador()->getTableroBarcos()->getMatriz();

    for (int i = 0; i < this->tamanioMapa; i++) {
        for (int j = 0; j < this->tamanioMapa; j++) {
            if (matriz[i][j] == Codigo::Agua) this->labels[i][j]->setText(QString::fromStdString("--"));
            else if (matriz[i][j] == Codigo::Ataque) this->labels[i][j]->setText(QString::fromStdString("**"));
            else if (matriz[i][j] == Codigo::Dañado) this->labels[i][j]->setText(QString::fromStdString("XX"));
            else this->labels[i][j]->setText(QString::fromStdString(std::to_string(matriz[i][j])));
        }
    }
}

void MainWindow::actualizarMapa(){
}

void MainWindow::on_aniadirBarco_clicked(){
    int opcionBarco, x, y;
    char orientacion;
    ui->alineacion->currentIndex() == 0 ? orientacion = 'H' : orientacion = 'V';
    opcionBarco = ui->listaBarcos->currentIndex() + 1;
    x = ui->posY->text().toInt();
    y = ui->posX->text().toInt();

    if ((!ui->posX->text().isEmpty() && !ui->posY->text().isEmpty()) && this->juego->colocarBarcosManual(opcionBarco, x, y, orientacion) && ui->listaBarcos->currentIndex() != -1){
        this->barcosAgregados++;
        setContadorBarcos(this->barcosAgregados, ui->cantBarcos->text().toInt());
        dibujarPremapa();
    } else {
        QMessageBox::information(this, "ALERTA", "Error en algun parametro\nIntente de nuevo.");
    }

    if (this->barcosAgregados + 1 > ui->cantBarcos->text().toInt()) {
        ui->ponerBarcos->hide();
        ui->mapaAtaque->show();
        ui->listaAtaquesJugador->show();
        ui->listaAtaquesIA->show();
        ui->infoBarcos->show();
        ui->previewBarco->hide();
        this->juego->colocarBarcosAleatorio(Turno::IA);
        listarInfo();
    }
    ui->posX->clear();
    ui->posY->clear();
}

void MainWindow::setValidators() {
    ui->cantBarcos->setValidator(new QIntValidator(1, 10, this));
    ui->tamanioMapa->setValidator(new QIntValidator(1, 20, this));
    ui->posX->setValidator(new QIntValidator(0, 20, this));
    ui->posY->setValidator(new QIntValidator(0, 20, this));
}

void MainWindow::setContadorBarcos(int valor, int total){
    ui->barcosRestantes->setText(QString::fromStdString("Barcos agregados: " + std::to_string(valor) + " / " + std::to_string(total)));
}

void MainWindow::on_cargarPartida_clicked(){
    QString filtro = "Maicena Files (*.maicena)";
    QString filepath = QFileDialog::getOpenFileName(this, "Elija el archivo a cargar", ":/saves/", filtro);
    QMessageBox::information(this, "ABRISTE", filepath);
}

void MainWindow::on_listaBarcos_currentIndexChanged(int index){
    switch (index) {
    case 0: {
        QPixmap imgBarco(":/images/crucero.png");
        ui->nombreBarco->setText(QString::fromStdString("Crucero - 3 Puntos de vida"));
        ui->imagenBarco->setPixmap(imgBarco.scaled(300, 300, Qt::KeepAspectRatio));
        break;
    }
    case 1: {
        QPixmap imgBarco(":/images/destructor.png");
        ui->nombreBarco->setText(QString::fromStdString("Destructor - 4 Puntos de vida"));
        ui->imagenBarco->setPixmap(imgBarco.scaled(150, 150, Qt::KeepAspectRatio));
        break;
    }
    case 2: {
        QPixmap imgBarco(":/images/fragata.png");
        ui->nombreBarco->setText(QString::fromStdString("Fragata - 2 Puntos de vida"));
        ui->imagenBarco->setPixmap(imgBarco.scaled(200, 200, Qt::KeepAspectRatio));
        break;
    }
    case 3: {
        QPixmap imgBarco(":/images/lancha.png");
        ui->nombreBarco->setText(QString::fromStdString("Lancha - 1 Punto de vida - Si no es alcanzada entonces se re posiciona aleatoreamiente en algún lugar disponible."));
        ui->imagenBarco->setPixmap(imgBarco.scaled(100, 100, Qt::KeepAspectRatio));
        break;
    }
    case 4: {
        QPixmap imgBarco(":/images/portaavion.png");
        ui->nombreBarco->setText(QString::fromStdString("Portaavion - 5 Puntos de Vida"));
        ui->imagenBarco->setPixmap(imgBarco.scaled(350, 350, Qt::KeepAspectRatio));
        break;
    }
    case 5: {
        QPixmap imgBarco(":/images/submarino.png");
        ui->nombreBarco->setText(QString::fromStdString("Submarino - 3 Puntos de Vida - Es eliminado con un golpe a su centro."));
        ui->imagenBarco->setPixmap(imgBarco.scaled(200, 200, Qt::KeepAspectRatio));
        break;
    }
    }
}