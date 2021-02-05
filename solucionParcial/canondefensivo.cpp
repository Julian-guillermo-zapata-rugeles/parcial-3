#include "canondefensivo.h"

CanonDefensivo::CanonDefensivo(short posx, short posy):Canon(posx,posy)
{

}

void CanonDefensivo::disparoLibre()
{
    scene()->addItem(new Proyectil(50,50,this->pos().x(),this->pos().y(),true));
}
