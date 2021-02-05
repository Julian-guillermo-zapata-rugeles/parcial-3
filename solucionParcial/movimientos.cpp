#include "movimientos.h"
#include <QDebug>



Movimientos::Movimientos(short limite_inferior_, short last, bool reverse_factor)
{
    this->reverse = reverse_factor;
    this->posicion_x=0;
    this->posicion_y=0;
    this->angulo=0;
    this->limite_inferior=limite_inferior_;
    this->proyectil_en_movimiento=false;
    this->lastPosition=last;
    this->tiempo_transcurrido=0;
}



bool Movimientos::getProyectil_en_movimiento() const
{
    return proyectil_en_movimiento;
}

void Movimientos::setProyectil_en_movimiento(bool value)
{
    proyectil_en_movimiento = value;
}







void Movimientos::configurarProyectil(short int velocidad_instantanea_ , short int angulo_ , short int posx , short int posy)
{
    this->posicion_x=posx;
    this->posicion_y=posy;
    this->angulo = angulo_;
    this->velocidad_instantanea=velocidad_instantanea_;
    velocidad_x = velocidad_instantanea * cos((angulo_*3.1416)/180);
    velocidad_y = velocidad_instantanea * sin((angulo_*3.1416)/180);

    qDebug() <<" posicion X : "<<posicion_x << " posicion Y : "<< posicion_y << endl;
    qDebug() <<" velocidad X : "<<velocidad_x << " velocidad Y : "<< velocidad_y << endl;
}





void Movimientos::moverParabolicamente()
{

    if(proyectil_en_movimiento==true){
        posicion_y=lastPosition - float(0+velocidad_y*tiempo_transcurrido+(0.5*(-9.8*tiempo_transcurrido*tiempo_transcurrido)));
        if(reverse==true){
             posicion_x=posicion_x-velocidad_x;
        }else{
             posicion_x=posicion_x+velocidad_x;
        }

        tiempo_transcurrido=tiempo_transcurrido+0.2;
        if(posicion_y>limite_inferior){
            proyectil_en_movimiento=false;
            posicion_y=limite_inferior;
            tiempo_transcurrido=0;
        }
    }
}
