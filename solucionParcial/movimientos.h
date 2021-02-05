#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
#include <math.h>

class Movimientos
{
public:
    Movimientos();
protected:

    // --------------------- Atributos de la clase Heredables --------------------------------//
    bool proyectil_en_movimiento;
    float velocidad_x , velocidad_y , tiempo_transcurrido , posicion_y ;
    short int velocidad_instantanea , angulo, limite_inferior;


    // ---------------------  Métodos de la clase Heredables  -------------------------------//

    void configurarProyectil();
    void moverParabolicamente();
};

#endif // MOVIMIENTOS_H
