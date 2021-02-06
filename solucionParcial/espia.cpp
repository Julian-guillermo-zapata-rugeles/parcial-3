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
}




bool Espia::ofensiveRuntimeService()
{
    ptr_canon_ofensivo->setPosicionEnemigaX(ptr_canon_defensivo->pos().x());
    ptr_canon_ofensivo->setPosicionEnemigaY(ptr_canon_defensivo->pos().y());
    if(ptr_canon_ofensivo->getProyectil_fue_disparado()==true){
        intervalo_adv_defensivo-=100;
    }
    if(intervalo_adv_defensivo<0){
        intervalo_adv_defensivo=2000;
        return true;
    }
    return false;
}




void Espia::actions()
{
    if(ofensiveRuntimeService()==true){
        ptr_canon_defensivo->disparoLibre();
        ptr_canon_ofensivo->setProyectil_fue_disparado(false); // restablezco nuevamente el estado
    }
}
