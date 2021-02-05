#include "proyectil.h"

Proyectil::Proyectil(short velocidad_instantanea, short angulo, float posicion_x, float posicion_y):
    Movimientos(600)
{
    this->configurarProyectil(velocidad_instantanea,angulo);
    this->setRect(0,0,20,20);
    this->setPos(posicion_x,posicion_y-this->rect().height());
}
