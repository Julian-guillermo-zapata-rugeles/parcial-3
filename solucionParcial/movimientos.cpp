#include "movimientos.h"

Movimientos::Movimientos()
{

}

void Movimientos::configurarProyectil()
{
    velocidad_x = velocidad_instantanea * cos((angulo*3.1416)/180);
    velocidad_y = velocidad_instantanea * sin((angulo*3.1416)/180);
}
