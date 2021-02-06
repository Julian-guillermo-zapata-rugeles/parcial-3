#include "canondefensivo.h"

CanonDefensivo::CanonDefensivo(short posx, short posy):Canon(posx,posy),Movimientos(600,0)
{
    setRotation(-100);
}

void CanonDefensivo::disparoLibre()
{
    scene()->addItem(new Proyectil(50,50,this->pos().x(),this->pos().y(),true));
}

bool CanonDefensivo::alerta_disparo(qreal x, qreal y, short angle, short velocidad_disparo)
{
      qDebug()<<" ----------------------------Alerta generada---------------------------------------------"<<endl;
      qDebug() << "pos Y : "<< x << "pos x: "<<y<<" this --> "<<pos().x()<<" + "<<pos().y() << "angulo "<<angle << " velocidad "<< velocidad_disparo << endl;
      lastPosition=y;
      qDebug() << "last position : "<< lastPosition << endl;
      configurarProyectil(velocidad_disparo,angle,x,y);
      while (posicion_y<600) {
          qDebug() << "mov x : "<<posicion_x <<"mov y : "<<posicion_y << endl;
          moverParabolicamente();
          if(comprobarCercania(posicion_x,posicion_y,pos().x(),pos().y())==true){
              scene()->addItem(new Proyectil(velocidad_disparo,angle,this->pos().x(),this->pos().y(),true));
              //scene()->addItem(new Proyectil(velocidad_disparo,angle,this->pos().x(),this->pos().y(),true));
              //disparoLibre();
          }
      }
}
