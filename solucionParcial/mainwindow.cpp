#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,1200,500);
    ui->graphicsView->setScene(scene);
    CanonOfensivo = new Canon(50,500);
    scene->addItem(CanonOfensivo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

