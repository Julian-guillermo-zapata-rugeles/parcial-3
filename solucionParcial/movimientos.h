#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
#include <math.h>

class Movimientos
{
public:
    Movimientos(short int limite_inferior,short int last , bool reverse_factor=false);


protected:

    // --------------------- Atributos de la clase Heredables --------------------------------//
    bool proyectil_en_movimiento , reverse ;
    float velocidad_x , velocidad_y , tiempo_transcurrido , posicion_y , posicion_x , lastPosition;
    short int velocidad_instantanea , angulo, limite_inferior;


    // ---------------------  Métodos de la clase Heredables  -------------------------------//

    void configurarProyectil(short velocidad_instantanea, short angulo, short int posx, short int posy);
    void moverParabolicamente();

    bool getProyectil_en_movimiento() const;
    void setProyectil_en_movimiento(bool value);
};

#endif // MOVIMIENTOS_H
