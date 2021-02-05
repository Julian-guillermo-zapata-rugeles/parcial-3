#include "proyectil.h"

Proyectil::Proyectil(short velocidad_instantanea, short angulo, float posicion_x_, float posicion_y_):
    Movimientos(500)
{
    this->configurarProyectil(velocidad_instantanea,angulo , posicion_x_ , posicion_y_);
    this->proyectil_en_movimiento=true;
    this->setRect(0,0,20,20);
    this->setPos(posicion_x_,posicion_y_-this->rect().height());
    this->eventController = new QTimer;
    connect(eventController,SIGNAL(timeout()),this,SLOT(actions()));
    this->eventController->start(20);

}

void Proyectil::actions()
{

    if(proyectil_en_movimiento==true){
        this->moverParabolicamente();
        this->setPos(this->pos().x(),posicion_y);
    }
}
