#include "canonofensivo.h"


bool CanonOfensivo::getProyectil_fue_disparado() const
{
    return proyectil_fue_disparado;
}

void CanonOfensivo::setProyectil_fue_disparado(bool value)
{
    proyectil_fue_disparado = value;
}

void CanonOfensivo::disparoLibre()
{
    scene()->addItem(new Proyectil(50,50,this->pos().x(),this->pos().y()));
    proyectil_fue_disparado=true;
}

CanonOfensivo::CanonOfensivo(short posx, short posy):Canon(posx,posy)
{
    proyectil_fue_disparado=false;
}
