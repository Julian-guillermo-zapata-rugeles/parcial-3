#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <canon.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_subir_clicked();

    void on_btn_bajar_clicked();

    void on_btn_derecha_clicked();

    void on_btn_izquierda_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Canon *CanonOfensivo;
};
#endif // MAINWINDOW_H
