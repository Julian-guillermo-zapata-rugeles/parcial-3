#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QObject>
#include <QObject>
#include <QTimer>
#include <QGraphicsRectItem>
#include "movimientos.h"



class Proyectil : public QObject , public QGraphicsRectItem , public Movimientos
{
    Q_OBJECT
public:
    Proyectil(short int velocidad_instantanea, short int angulo , float posicion_x , float posicion_y);
    ~Proyectil();
private:
    QTimer *eventController;

private slots:
    void actions();
};

#endif // PROYECTIL_H
