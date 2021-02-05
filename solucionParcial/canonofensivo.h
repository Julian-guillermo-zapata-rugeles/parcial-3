#ifndef CANONOFENSIVO_H
#define CANONOFENSIVO_H
#include "canon.h"

class CanonOfensivo : public Canon
{
public:
    bool proyectil_fue_disparado;
    CanonOfensivo(short int posx, short int posy);



    // ------------------ metodos setter y getter --------------------- //
    bool getProyectil_fue_disparado() const;
    void setProyectil_fue_disparado(bool value);
    void disparoLibre(); // método que será redefinido (se hereda igualmente desde canon)
};

#endif // CANONOFENSIVO_H
