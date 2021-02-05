#ifndef CANONOFENSIVO_H
#define CANONOFENSIVO_H
#include "canon.h"

class CanonOfensivo : public Canon
{
public:

    CanonOfensivo(short int posx, short int posy);


    // ------------------ metodos setter y getter --------------------- //
    bool getProyectil_fue_disparado() const;
    void setProyectil_fue_disparado(bool value);
    void disparoLibre(); // método que será redefinido (se hereda igualmente desde canon)
    signed short getAnguloDisparo() const;
    void setAnguloDisparo(signed short value);

private:
    bool proyectil_fue_disparado;
    signed short int anguloDisparo;
};

#endif // CANONOFENSIVO_H
