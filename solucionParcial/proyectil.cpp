#include "proyectil.h"
#include <QGraphicsScene>
Proyectil::Proyectil(short velocidad_instantanea, short angle, float pos_x_const, float pos_y_const, bool reverse):
    Movimientos(500,pos_y_const,reverse)
{
    this->setRect(0,0,20,20);
    this->configurarProyectil(velocidad_instantanea, angle , pos_x_const , pos_y_const);
    this->proyectil_en_movimiento=true;
    this->setPos(Movimientos::posicion_x,Movimientos::posicion_y+this->rect().height());
    this->eventController = new QTimer;
    connect(eventController,SIGNAL(timeout()),this,SLOT(actions()));
    this->eventController->start(50);


}

Proyectil::~Proyectil()
{
 scene()->removeItem(this);

}

void Proyectil::actions()
{

    if(proyectil_en_movimiento==true){
        this->moverParabolicamente();
        this->setPos(Movimientos::posicion_x,Movimientos::posicion_y);
    }else{
        delete this;
    }
}
