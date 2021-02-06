#include "canon.h"


Canon::Canon(unsigned short posx, unsigned short posy)
{
    //this->setRect(0,0,50,50);
    this->setPixmap(QPixmap(":/recursos/canon.png"));
    this->setPos(posx,posy-this->boundingRect().height());
    this->setTransformOriginPoint(this->boundingRect().center());
    sonido= new QMediaPlayer();

}

void Canon::subir()
{
    this->setPos(pos().x(),pos().y()-10);
}

void Canon::bajar()
{
    this->setPos(pos().x(),pos().y()+10);
}

void Canon::izquierda()
{
    this->setPos(pos().x()-10,pos().y());
}

void Canon::derecha()
{
    this->setPos(pos().x()+10,pos().y());
}

void Canon::disparoLibre()
{
    scene()->addItem(new Proyectil(50,50,this->pos().x(),this->pos().y()));
}

void Canon::explotar()
{
            sonido-> setMedia ( QUrl ( "qrc:/recursos/explosion.mp3" ));
            sonido->play();
}

void Canon::alarma()
{
    sonido-> setMedia ( QUrl ( "qrc:/recursos/gpws.mp3" ));
    sonido->play();
}

