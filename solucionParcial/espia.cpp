#include "espia.h"

Espia::Espia(CanonOfensivo *canon_ofensivo, CanonDefensivo *canon_defensivo)
{
    ptr_canon_defensivo = canon_defensivo;
    ptr_canon_ofensivo  = canon_ofensivo;
    controladorEventos = new QTimer();
}

void Espia::actions()
{

}
