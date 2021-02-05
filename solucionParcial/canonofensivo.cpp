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




void CanonOfensivo::calcularTrayectorias(qreal enemy_pos_x, qreal enemy_pos_y)
{
    //this->posicion_x = pos().x();
    //this->posicion_y = pos().x();
    for(unsigned short int gradosInclinacion = 1 ; gradosInclinacion < 180 ; gradosInclinacion++){
        // mager para grados de 1 a 180
        for(unsigned short int velocidadProyectil=1; velocidadProyectil<100;velocidadProyectil++){
            // margen para velocidad 1 a 100
            bool exahustedSearch = false;
            configurarProyectil(velocidad_instantanea,gradosInclinacion,pos().x(),pos().y());
            while (exahustedSearch==false) {
                // se trazará una trayectoria ficticia que permitirá obtener coordenadas de avace

            }
        }
    }
}




CanonOfensivo::CanonOfensivo(short posx, short posy)
    :Canon(posx,posy),Movimientos(500,0)
{
    proyectil_fue_disparado=false;
    anguloDisparo=80;
}
