#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
#include <math.h>

class Movimientos
{
public:
    Movimientos();
protected:
    float velocidad_x , velocidad_y , tiempo_transcurrido ;
    short int velocidad_instantanea , angulo ;
    void configurarProyectil();
};

#endif // MOVIMIENTOS_H
