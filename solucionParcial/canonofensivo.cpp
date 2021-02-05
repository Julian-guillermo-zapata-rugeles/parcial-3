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
    scene()->addItem(new Proyectil(100,anguloDisparo,this->pos().x(),this->pos().y()));
    proyectil_fue_disparado=true;
}

signed short CanonOfensivo::getAnguloDisparo() const
{
    return anguloDisparo;
}

void CanonOfensivo::setAnguloDisparo(signed short value)
{
    anguloDisparo = value;
}




void CanonOfensivo::calcularTrayectorias()
{

}




CanonOfensivo::CanonOfensivo(short posx, short posy):Canon(posx,posy)
{
    proyectil_fue_disparado=false;
    anguloDisparo=80;
}
