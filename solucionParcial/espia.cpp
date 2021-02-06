#include "espia.h"

Espia::Espia(CanonOfensivo *canon_ofensivo, CanonDefensivo *canon_defensivo)
{
    ptr_canon_defensivo = canon_defensivo;
    ptr_canon_ofensivo  = canon_ofensivo;
    intervalo_adv_defensivo= 2000;
    intervalo_adv_ofensivo=1000;
    controladorEventos = new QTimer();
    connect(controladorEventos,SIGNAL(timeout()),this,SLOT(actions()));
    controladorEventos->start(100);
    this->respuesta=false;
    this->multiple=false;
}

void Espia::setMultiple(bool value)
{
    multiple = value;
}

void Espia::setRespuesta(bool value)
{
    respuesta = value;
}




bool Espia::ofensiveRuntimeService()
{
    ptr_canon_ofensivo->setPosicionEnemigaX(ptr_canon_defensivo->pos().x());
    ptr_canon_ofensivo->setPosicionEnemigaY(ptr_canon_defensivo->pos().y());
    if(ptr_canon_ofensivo->getProyectil_fue_disparado()==true){
        intervalo_adv_defensivo-=100;
        if(multiple==true){
            if(intervalo_adv_defensivo==500){
                ptr_canon_ofensivo->disparoCertero();
            }
            if(intervalo_adv_defensivo==100){
               ptr_canon_ofensivo->disparoCertero();
               multiple=false;
            }
        }

    }
    if(intervalo_adv_defensivo<0){
        intervalo_adv_defensivo=2000;
        return true;
    }
    return false;
}




void Espia::actions()
{
    if(ofensiveRuntimeService()==true && respuesta==true){
        ptr_canon_defensivo->alerta_disparo(ptr_canon_ofensivo->pos().x(),
                                            ptr_canon_ofensivo->pos().y(),
                                            ptr_canon_ofensivo->getAnguloImpacto(),
                                            ptr_canon_ofensivo->getVelocidadImpacto());
        respuesta=false;

        ptr_canon_ofensivo->setProyectil_fue_disparado(false); // restablezco nuevamente el estado
    }
}
