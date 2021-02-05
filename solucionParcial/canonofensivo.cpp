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




bool CanonOfensivo::calcularTrayectorias(qreal enemy_pos_x, qreal enemy_pos_y)
{
    //this->posicion_x = pos().x();
    //this->posicion_y = pos().x();
    for(unsigned short int gradosInclinacion = 1 ; gradosInclinacion < 90 ; gradosInclinacion++){
        // mager para grados de 1 a 180
        //qDebug()<<" buscando en "<<gradosInclinacion << " grados "<<endl;
        for(unsigned short int velocidadProyectil=1; velocidadProyectil<100;velocidadProyectil++){
            // margen para velocidad 1 a 100
            qDebug()<<"prueba para "<<gradosInclinacion <<"grados con "<<velocidad_instantanea<<" velocidad " << endl;
            bool exahustedSearch = false;


            // CONFIGURACIONES PARA LA TRAYECTORIA
            lastPosition=pos().y();
            intervaloSuma=0.1;
            configurarProyectil(velocidadProyectil,gradosInclinacion,pos().x(),pos().y());
            //---------------------------------


            while (exahustedSearch==false) {
                // se trazará una trayectoria ficticia que permitirá obtener coordenadas de avace
                //qDebug()<< "pos x : "<<posicion_x<<" pos y :"<<posicion_y<< endl;
                if(posicion_y>=550){
                    exahustedSearch=true;

                }
                else{
                    moverParabolicamente();
                    // BUG PARA SOLUCIONAR -- EL CICLO SE DETIENE //
                    /*
                    if(comprobarCercania(enemy_pos_x,enemy_pos_y)){
                        return true;
                        anguloImpacto=gradosInclinacion;
                        velocidadImpacto=velocidadProyectil;
                        qDebug ()<< "se encontró que el angulo "<< anguloImpacto << " y velocidad "<<velocidadImpacto << "es la trayectoria indicada "<<endl;
                    }*/
                }

            }

        }
    }
    qDebug()<<" se acabó la busqueda " << endl;
    return false;
}




CanonOfensivo::CanonOfensivo(short posx, short posy)
    :Canon(posx,posy),Movimientos(600,0)
{
    proyectil_fue_disparado=false;
    anguloDisparo=80;
}
