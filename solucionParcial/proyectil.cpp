#include "proyectil.h"

Proyectil::Proyectil(short velocidad_instantanea, short angulo):
    Movimientos(600)
{
    this->configurarProyectil(velocidad_instantanea,angulo);
    this->setRect(0,0,100,100);
}
