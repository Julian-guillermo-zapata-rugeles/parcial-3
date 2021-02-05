#include "canon.h"


Canon::Canon(unsigned short posx, unsigned short posy)
{
    this->setRect(0,0,50,50);
    this->setPos(50,500-this->boundingRect().height());
}

void Canon::subir()
{
    this->setPos(pos().x(),pos().y()-5);
}

void Canon::bajar()
{
    this->setPos(pos().x(),pos().y()+5);
}

void Canon::izquierda()
{
    this->setPos(pos().x()-5,pos().y());
}

void Canon::derecha()
{
    this->setPos(pos().x()+5,pos().y());
}
