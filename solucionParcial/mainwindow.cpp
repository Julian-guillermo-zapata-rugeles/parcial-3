#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,1200,500);
    ui->graphicsView->setScene(scene);
    disparo=new Proyectil(100,100,0,500);
    scene->addItem(disparo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

