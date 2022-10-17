#include "Ventana/mainwindow.h"
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

void MainWindow::describirAtaque(bool band, int x, int y){
    band ? ui->listaAtaques->setText(QString::fromStdString("Ataque EXITOSO en coordenadas x: " + std::to_string(x) + " / y: " + std::to_string(y))) : ui->listaAtaques->setText(QString::fromStdString("Ataque FALLIDO en coordenadas x: " + std::to_string(x) + " / y: " + std::to_string(y)));
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
        this->juego = new Juego(ui->tamanioMapa->text().toInt(), ui->cantBarcos->text().toInt());
        ui->configJuego->hide();
        crearMapas();
        ui->mapas->show();

        if (!this->ui->checkAleatorio->isChecked()) {
            ui->ponerBarcos->show();
            ui->previewBarco->show();
            ui->mapaAtaque->hide();
            ui->listaAtaques->hide();
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
    int sizeMap = ui->tamanioMapa->text().toInt();

    this->buttons = new QPushButton**[sizeMap];
    this->labels = new QLabel**[sizeMap];

    for (int i = 0; i < sizeMap; ++i) {
        this->buttons[i] = new QPushButton*[sizeMap];
        this->labels[i] = new QLabel*[sizeMap];

        for (int j = 0; j < sizeMap; ++j) {
            QPushButton* button = new QPushButton();

            connect(button, &QPushButton::released, this,
                    [=]() { handleButton(i, j); });

            this->buttons[i][j] = button;
            ui->attackGLayout->addWidget(button, i, j);
            QLabel* label = new QLabel("-");

            this->labels[i][j] = label;
            ui->mapGLayout->addWidget(label, i, j);
        }
    }
}

void MainWindow::listarInfo(){
    for (auto barco : this->juego->getJugador()->getTableroBarcos()->getBarcos()){
        std::string x = std::to_string(barco->getX());
        std::string y = std::to_string(barco->getY());
        std::string tamanio = std::to_string(barco->getTamanio());
        std::string nombre(barco->getNombre());
        std::string vida = std::to_string(barco->getTamanio() - barco->getGolpes());
        std::string orientacion(1, barco->getOrientacion());
        ui->infoBarcos->append(QString::fromStdString(nombre + " (X: " + x + ", Y: " + y + ") - Vida: " + vida + "/"
                                                      + tamanio + " - Orientacion: " + orientacion));
    }
}

void MainWindow::dibujarPremapa()
{
    int sizeMap = ui->tamanioMapa->text().toInt();

   int ** matriz = this->juego->getJugador()->getTableroBarcos()->getMatriz();


    for (int i = 0; i < sizeMap; ++i) {


        for (int j = 0; j < sizeMap; ++j) {


            this->labels[i][j]->setText(QString::fromStdString(std::to_string(matriz[i][j])));
            this->labels[i][j]->setStyleSheet("color:white"); //que sea una table cuyo interior se pinte para saber onta el barco



        }
    }
}

void MainWindow::actualizarMapa()
{




}





void MainWindow::on_aniadirBarco_clicked(){
//    std::string orientacion = ;

    char orientacion;
    if (ui->alineacion->currentIndex() == 0)
        orientacion = 'H';
    else
    orientacion = 'V';
int op, x,y;


op = ui->listaBarcos->currentIndex()+1;
x =  ui->posX->text().toInt();
y =  ui->posY->text().toInt();
    if ((!ui->posX->text().isEmpty() || !ui->posY->text().isEmpty()) && this->juego->colocarBarcosManual(
           op ,x, y, orientacion) && ui->listaBarcos->currentIndex() != -1){
        this->barcosAgregados++;
        setContadorBarcos(this->barcosAgregados, ui->cantBarcos->text().toInt());

        dibujarPremapa();
        //dibujar pre mapa


    } else {
        QMessageBox::information(this, "ALERTA", "Error en algun parametro\nIntente de nuevo.");
    }

    if (this->barcosAgregados + 1 > ui->cantBarcos->text().toInt()) {
        ui->ponerBarcos->hide();
        ui->mapaAtaque->show();
        ui->listaAtaques->show();
        ui->infoBarcos->show();
        ui->previewBarco->hide();
        listarInfo();
        this->juego->colocarBarcosAleatorio(Turno::IA);

    }

    ui->posX->clear();
    ui->posY->clear();
}

void MainWindow::setValidators() {
    ui->cantBarcos->setValidator(new QIntValidator(0,10,this));
    ui->tamanioMapa->setValidator(new QIntValidator(0,100,this));
    ui->posX->setValidator(new QIntValidator(0,100,this));
    ui->posY->setValidator(new QIntValidator(0,100,this));
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
