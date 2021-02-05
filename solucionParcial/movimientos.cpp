#include "movimientos.h"





Movimientos::Movimientos(short limite_inferior_)
{
    this->limite_inferior=limite_inferior_;
    this->proyectil_en_movimiento=false;
}



bool Movimientos::getProyectil_en_movimiento() const
{
    return proyectil_en_movimiento;
}

void Movimientos::setProyectil_en_movimiento(bool value)
{
    proyectil_en_movimiento = value;
}







void Movimientos::configurarProyectil(short int velocidad_instantanea , short int angulo , short int posx , short int posy)
{
    this->posicion_x=posx;
    this->posicion_y=posy;
    velocidad_x = velocidad_instantanea * cos((angulo*3.1416)/180);
    velocidad_y = velocidad_instantanea * sin((angulo*3.1416)/180);
}





void Movimientos::moverParabolicamente()
{

    if(proyectil_en_movimiento==true){
        posicion_y=limite_inferior - float(0+velocidad_y*tiempo_transcurrido+(0.5*(-9.8*tiempo_transcurrido*tiempo_transcurrido)));
        posicion_x=posicion_x+velocidad_x;
        tiempo_transcurrido=tiempo_transcurrido+0.1;
        if(posicion_y>limite_inferior){
            proyectil_en_movimiento=false;
            posicion_y=limite_inferior;
            tiempo_transcurrido=0;
        }
    }
}
