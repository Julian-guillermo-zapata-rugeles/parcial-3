#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,1200,500);
    ui->graphicsView->setScene(scene);
    Canon_ofensivo = new CanonOfensivo(50,500);
    Canon_defensivo = new CanonDefensivo(1100,500);
    ChivoExpiatorio = new Espia(Canon_ofensivo,Canon_defensivo);
    scene->addItem(Canon_defensivo);
    scene->addItem(Canon_ofensivo);
    ui->visor_angulo->setText(QString::number( Canon_ofensivo->getAnguloDisparo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}








// ---------------- COMANDOS PARA EL CAÑON #1 --------------------//

void MainWindow::on_btn_subir_clicked()
{
     Canon_ofensivo->subir();
}

void MainWindow::on_btn_bajar_clicked()
{
     Canon_ofensivo->bajar();
}

void MainWindow::on_btn_derecha_clicked()
{
     Canon_ofensivo->derecha();
}

void MainWindow::on_btn_izquierda_clicked()
{
     Canon_ofensivo->izquierda();
}

void MainWindow::on_btn_fuego_clicked()
{
     //Canon_ofensivo->disparoLibre();
    Canon_ofensivo->calcularTrayectorias(1000,500);
}

// --------------- COMANDOS PARA EL CAÑON #2 ----------------------//





void MainWindow::on_btn_subir_2_clicked()
{
    Canon_defensivo->subir();
}

void MainWindow::on_btn_izquierda_2_clicked()
{
    Canon_defensivo->izquierda();
}

void MainWindow::on_btn_derecha_2_clicked()
{
    Canon_defensivo->derecha();
}

void MainWindow::on_btn_bajar_2_clicked()
{
    Canon_defensivo->bajar();
}

void MainWindow::on_btn_fuego_2_clicked()
{
    Canon_defensivo->disparoLibre();
}

void MainWindow::on_subir_grados_clicked()
{
    // para subir grados usaré un método setter de un atributo privado de el cañon ofensivo
    Canon_ofensivo->setAnguloDisparo(Canon_ofensivo->getAnguloDisparo()+1);
    ui->visor_angulo->setText(QString::number( Canon_ofensivo->getAnguloDisparo()));
}

void MainWindow::on_bajar_grados_clicked()
{
    Canon_ofensivo->setAnguloDisparo(Canon_ofensivo->getAnguloDisparo()-1);
    ui->visor_angulo->setText(QString::number( Canon_ofensivo->getAnguloDisparo()));
}
