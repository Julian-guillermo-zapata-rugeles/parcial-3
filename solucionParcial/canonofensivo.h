#ifndef CANONOFENSIVO_H
#define CANONOFENSIVO_H
#include "canon.h"
#include "movimientos.h"
#include "QDebug"

class CanonOfensivo : public Canon , public Movimientos
{
public:

    CanonOfensivo(short int posx, short int posy);


    // ------------------ metodos setter y getter --------------------- //
    bool getProyectil_fue_disparado() const;
    void setProyectil_fue_disparado(bool value);
    void disparoLibre(); // método que será redefinido (se hereda igualmente desde canon)
    signed short getAnguloDisparo() const;

    void setAnguloDisparo(signed short value);
    bool calcularTrayectorias(qreal enemy_pos_x, qreal enemy_pos_y);

private:
    bool proyectil_fue_disparado;
    signed short int anguloDisparo;


};

#endif // CANONOFENSIVO_H
