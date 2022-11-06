/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *cargarPartida;
    QPushButton *nuevoJuego;
    QWidget *configJuego;
    QPushButton *jugar;
    QLineEdit *tamanioMapa;
    QLineEdit *cantBarcos;
    QCheckBox *checkAleatorio;
    QWidget *mapas;
    QWidget *mapaJugador;
    QWidget *gridLayoutWidget_2;
    QGridLayout *mapGLayout;
    QWidget *mapaAtaque;
    QWidget *gridLayoutWidget;
    QGridLayout *attackGLayout;
    QTextBrowser *listaAtaquesJugador;
    QTextBrowser *infoBarcos;
    QTextBrowser *listaAtaquesIA;
    QPushButton *guardarPartida;
    QWidget *ponerBarcos;
    QPushButton *aniadirBarco;
    QLineEdit *posY;
    QComboBox *alineacion;
    QLineEdit *posX;
    QComboBox *listaBarcos;
    QLabel *barcosRestantes;
    QWidget *previewBarco;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *preview;
    QLabel *imagenBarco;
    QLabel *nombreBarco;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 768);
        MainWindow->setMinimumSize(QSize(1280, 768));
        MainWindow->setMaximumSize(QSize(1280, 768));
        QPalette palette;
        QBrush brush(QColor(198, 219, 245, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(177, 177, 177, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        QBrush brush2(QColor(212, 212, 212, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush2);
        QBrush brush3(QColor(64, 65, 66, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        QBrush brush4(QColor(160, 160, 160, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        MainWindow->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Source Code Pro Semibold"));
        font.setPointSize(11);
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setWindowTitle(QString::fromUtf8("Batalla Naval v1.01"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("applications-games");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"	border-image: url(:/images/bg.png);\n"
"}"));
        MainWindow->setIconSize(QSize(500, 500));
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(1280, 768));
        cargarPartida = new QPushButton(centralwidget);
        cargarPartida->setObjectName(QString::fromUtf8("cargarPartida"));
        cargarPartida->setGeometry(QRect(10, 316, 440, 90));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cargarPartida->sizePolicy().hasHeightForWidth());
        cargarPartida->setSizePolicy(sizePolicy);
        cargarPartida->setMinimumSize(QSize(0, 0));
        cargarPartida->setMaximumSize(QSize(480, 110));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Source Code Pro"));
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        cargarPartida->setFont(font1);
        cargarPartida->setStyleSheet(QString::fromUtf8("#cargarPartida {\n"
"  background-color: #ddd;\n"
"  border: 10px inset #5fcfbf;\n"
"  color: black;\n"
"  padding: 10px 20px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"  display: inline-block;\n"
"  margin: 4px 2px;\n"
"  cursor: pointer;\n"
"  border-radius: 40px;\n"
"}\n"
"\n"
"#cargarPartida:hover {\n"
"  background-color: #188c8c;\n"
"}\n"
"\n"
""));
        nuevoJuego = new QPushButton(centralwidget);
        nuevoJuego->setObjectName(QString::fromUtf8("nuevoJuego"));
        nuevoJuego->setGeometry(QRect(10, 220, 440, 90));
        nuevoJuego->setMinimumSize(QSize(0, 0));
        nuevoJuego->setMaximumSize(QSize(480, 110));
        nuevoJuego->setFont(font1);
        nuevoJuego->setStyleSheet(QString::fromUtf8("#nuevoJuego {\n"
"  background-color: #ddd;\n"
"  border: 10px inset #5fcfbf;\n"
"  color: black;\n"
"  padding: 10px 20px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"  display: inline-block;\n"
"  margin: 4px 2px;\n"
"  cursor: pointer;\n"
"  border-radius: 40px;\n"
"}\n"
"\n"
"#nuevoJuego:hover {\n"
"  background-color: #188c8c;\n"
"}\n"
"\n"
""));
        configJuego = new QWidget(centralwidget);
        configJuego->setObjectName(QString::fromUtf8("configJuego"));
        configJuego->setGeometry(QRect(20, 410, 411, 311));
        jugar = new QPushButton(configJuego);
        jugar->setObjectName(QString::fromUtf8("jugar"));
        jugar->setGeometry(QRect(10, 210, 371, 51));
        tamanioMapa = new QLineEdit(configJuego);
        tamanioMapa->setObjectName(QString::fromUtf8("tamanioMapa"));
        tamanioMapa->setGeometry(QRect(10, 35, 101, 40));
        tamanioMapa->setInputMethodHints(Qt::ImhDigitsOnly);
        cantBarcos = new QLineEdit(configJuego);
        cantBarcos->setObjectName(QString::fromUtf8("cantBarcos"));
        cantBarcos->setGeometry(QRect(120, 35, 101, 40));
        cantBarcos->setInputMethodHints(Qt::ImhDigitsOnly);
        checkAleatorio = new QCheckBox(configJuego);
        checkAleatorio->setObjectName(QString::fromUtf8("checkAleatorio"));
        checkAleatorio->setGeometry(QRect(230, 25, 211, 60));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        checkAleatorio->setFont(font2);
        mapas = new QWidget(centralwidget);
        mapas->setObjectName(QString::fromUtf8("mapas"));
        mapas->setGeometry(QRect(20, 140, 1231, 591));
        mapaJugador = new QWidget(mapas);
        mapaJugador->setObjectName(QString::fromUtf8("mapaJugador"));
        mapaJugador->setEnabled(true);
        mapaJugador->setGeometry(QRect(600, 30, 561, 291));
        mapaJugador->setAutoFillBackground(false);
        gridLayoutWidget_2 = new QWidget(mapaJugador);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(40, 10, 501, 241));
        mapGLayout = new QGridLayout(gridLayoutWidget_2);
        mapGLayout->setObjectName(QString::fromUtf8("mapGLayout"));
        mapGLayout->setContentsMargins(0, 0, 0, 0);
        mapaAtaque = new QWidget(mapas);
        mapaAtaque->setObjectName(QString::fromUtf8("mapaAtaque"));
        mapaAtaque->setGeometry(QRect(0, 30, 561, 291));
        mapaAtaque->setAutoFillBackground(false);
        gridLayoutWidget = new QWidget(mapaAtaque);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 10, 501, 241));
        attackGLayout = new QGridLayout(gridLayoutWidget);
        attackGLayout->setObjectName(QString::fromUtf8("attackGLayout"));
        attackGLayout->setContentsMargins(0, 0, 0, 0);
        listaAtaquesJugador = new QTextBrowser(mapas);
        listaAtaquesJugador->setObjectName(QString::fromUtf8("listaAtaquesJugador"));
        listaAtaquesJugador->setGeometry(QRect(670, 350, 471, 31));
        infoBarcos = new QTextBrowser(mapas);
        infoBarcos->setObjectName(QString::fromUtf8("infoBarcos"));
        infoBarcos->setGeometry(QRect(670, 40, 471, 291));
        listaAtaquesIA = new QTextBrowser(mapas);
        listaAtaquesIA->setObjectName(QString::fromUtf8("listaAtaquesIA"));
        listaAtaquesIA->setGeometry(QRect(670, 390, 471, 31));
        guardarPartida = new QPushButton(mapas);
        guardarPartida->setObjectName(QString::fromUtf8("guardarPartida"));
        guardarPartida->setGeometry(QRect(670, 450, 471, 90));
        guardarPartida->setMinimumSize(QSize(0, 0));
        guardarPartida->setMaximumSize(QSize(480, 110));
        guardarPartida->setFont(font1);
        guardarPartida->setStyleSheet(QString::fromUtf8("#guardarPartida {\n"
"  background-color: #ddd;\n"
"  border: 10px inset #5fcfbf;\n"
"  color: black;\n"
"  padding: 10px 20px;\n"
"  text-align: center;\n"
"  text-decoration: none;\n"
"  display: inline-block;\n"
"  margin: 4px 2px;\n"
"  cursor: pointer;\n"
"  border-radius: 40px;\n"
"}\n"
"\n"
"#guardarPartida:hover {\n"
"  background-color: #188c8c;\n"
"}"));
        ponerBarcos = new QWidget(centralwidget);
        ponerBarcos->setObjectName(QString::fromUtf8("ponerBarcos"));
        ponerBarcos->setGeometry(QRect(29, 440, 381, 160));
        ponerBarcos->setInputMethodHints(Qt::ImhDigitsOnly);
        aniadirBarco = new QPushButton(ponerBarcos);
        aniadirBarco->setObjectName(QString::fromUtf8("aniadirBarco"));
        aniadirBarco->setGeometry(QRect(281, 100, 91, 41));
        posY = new QLineEdit(ponerBarcos);
        posY->setObjectName(QString::fromUtf8("posY"));
        posY->setGeometry(QRect(180, 100, 41, 41));
        posY->setInputMethodHints(Qt::ImhDigitsOnly);
        alineacion = new QComboBox(ponerBarcos);
        alineacion->addItem(QString());
        alineacion->addItem(QString());
        alineacion->setObjectName(QString::fromUtf8("alineacion"));
        alineacion->setGeometry(QRect(130, 100, 41, 41));
        posX = new QLineEdit(ponerBarcos);
        posX->setObjectName(QString::fromUtf8("posX"));
        posX->setGeometry(QRect(230, 100, 41, 41));
        posX->setInputMethodHints(Qt::ImhDigitsOnly);
        listaBarcos = new QComboBox(ponerBarcos);
        listaBarcos->addItem(QString());
        listaBarcos->addItem(QString());
        listaBarcos->addItem(QString());
        listaBarcos->addItem(QString());
        listaBarcos->addItem(QString());
        listaBarcos->addItem(QString());
        listaBarcos->setObjectName(QString::fromUtf8("listaBarcos"));
        listaBarcos->setGeometry(QRect(1, 100, 121, 41));
        barcosRestantes = new QLabel(ponerBarcos);
        barcosRestantes->setObjectName(QString::fromUtf8("barcosRestantes"));
        barcosRestantes->setGeometry(QRect(0, 64, 371, 21));
        QFont font3;
        font3.setBold(true);
        barcosRestantes->setFont(font3);
        previewBarco = new QWidget(centralwidget);
        previewBarco->setObjectName(QString::fromUtf8("previewBarco"));
        previewBarco->setGeometry(QRect(120, 190, 491, 261));
        verticalLayoutWidget = new QWidget(previewBarco);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 10, 441, 241));
        preview = new QVBoxLayout(verticalLayoutWidget);
        preview->setObjectName(QString::fromUtf8("preview"));
        preview->setContentsMargins(0, 0, 0, 0);
        imagenBarco = new QLabel(verticalLayoutWidget);
        imagenBarco->setObjectName(QString::fromUtf8("imagenBarco"));
        imagenBarco->setAlignment(Qt::AlignCenter);

        preview->addWidget(imagenBarco);

        nombreBarco = new QLabel(verticalLayoutWidget);
        nombreBarco->setObjectName(QString::fromUtf8("nombreBarco"));
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(false);
        nombreBarco->setFont(font4);
        nombreBarco->setAutoFillBackground(false);
        nombreBarco->setScaledContents(false);
        nombreBarco->setAlignment(Qt::AlignCenter);
        nombreBarco->setWordWrap(true);

        preview->addWidget(nombreBarco);

        MainWindow->setCentralWidget(centralwidget);
        configJuego->raise();
        cargarPartida->raise();
        mapas->raise();
        ponerBarcos->raise();
        previewBarco->raise();
        nuevoJuego->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        cargarPartida->setText(QCoreApplication::translate("MainWindow", "Cargar Partida", nullptr));
        nuevoJuego->setText(QCoreApplication::translate("MainWindow", "Nuevo Juego", nullptr));
        jugar->setText(QCoreApplication::translate("MainWindow", "JUGAR", nullptr));
        tamanioMapa->setText(QString());
        cantBarcos->setText(QString());
        checkAleatorio->setText(QCoreApplication::translate("MainWindow", "A\303\261adir Aleatorio", nullptr));
        guardarPartida->setText(QCoreApplication::translate("MainWindow", "Guardar Partida", nullptr));
        aniadirBarco->setText(QCoreApplication::translate("MainWindow", "A\303\221ADIR", nullptr));
        alineacion->setItemText(0, QCoreApplication::translate("MainWindow", "V", nullptr));
        alineacion->setItemText(1, QCoreApplication::translate("MainWindow", "H", nullptr));

        alineacion->setCurrentText(QCoreApplication::translate("MainWindow", "V", nullptr));
        listaBarcos->setItemText(0, QCoreApplication::translate("MainWindow", "CRUCERO", nullptr));
        listaBarcos->setItemText(1, QCoreApplication::translate("MainWindow", "DESTRUCTOR", nullptr));
        listaBarcos->setItemText(2, QCoreApplication::translate("MainWindow", "FRAGATA", nullptr));
        listaBarcos->setItemText(3, QCoreApplication::translate("MainWindow", "LANCHA", nullptr));
        listaBarcos->setItemText(4, QCoreApplication::translate("MainWindow", "PORTAAVION", nullptr));
        listaBarcos->setItemText(5, QCoreApplication::translate("MainWindow", "SUBMARINO", nullptr));

        barcosRestantes->setText(QString());
        imagenBarco->setText(QString());
        nombreBarco->setText(QString());
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
