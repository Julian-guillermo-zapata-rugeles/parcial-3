#include "espia.h"

Espia::Espia(CanonOfensivo *canon_ofensivo, CanonDefensivo *canon_defensivo)
{
    ptr_canon_defensivo = canon_defensivo;
    ptr_canon_ofensivo  = canon_ofensivo;
    controladorEventos = new QTimer();
    connect(controladorEventos,SIGNAL(timeout()),this,SLOT(actions()));
    controladorEventos->start(100);
}

void Espia::actions()
{
    ptr_canon_defensivo->derecha();
}
