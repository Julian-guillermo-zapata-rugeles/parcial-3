#ifndef ProyectilEnemigo_H
#define ProyectilEnemigo_H

#include <QObject>
#include <QObject>
#include <QTimer>
#include <QGraphicsRectItem>
#include "movimientos.h"
#include <QPainter>
#include <QVector>
#include <QDebug>
#include <persistencia.h>



class ProyectilEnemigo : public QObject , public QGraphicsPixmapItem , public Movimientos
{
    Q_OBJECT
public:
    ProyectilEnemigo(short int velocidad_instantanea, short int angulo , float posicion_x , float posicion_y , bool reverse = false);
    ~ProyectilEnemigo();
protected:
    QTimer *eventController;
    short int min=0;

protected slots:
    void actions();

    // QGraphicsItem interface
public:
    //QRectF boundingRect() const;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ProyectilEnemigo_H
