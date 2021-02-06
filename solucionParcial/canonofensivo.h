#ifndef CANONOFENSIVO_H
#define CANONOFENSIVO_H
#include "canon.h"
#include "movimientos.h"
#include "QDebug"
#include <proyectilEnemigo.h>

class CanonOfensivo : public Canon , public Movimientos
{
public:

    CanonOfensivo(short int posx, short int posy);


    // ------------------ metodos setter y getter --------------------- //
    bool getProyectil_fue_disparado() const;
    void setProyectil_fue_disparado(bool value);
    qreal posicionEnemigaX;
    qreal posicionEnemigaY;
    void disparoLibre(); // método que será redefinido (se hereda igualmente desde canon)
    signed short getAnguloDisparo() const;

    void setAnguloDisparo(signed short value);
    bool calcularTrayectorias();
    void disparoCertero();
    void setPosicionEnemigaX(const qreal &value);

    void setPosicionEnemigaY(const qreal &value);

    qreal getAnguloImpacto() const;

    qreal getVelocidadImpacto() const;

private:
    bool proyectil_fue_disparado;
    signed short int anguloDisparo;
    qreal anguloImpacto , velocidadImpacto;


};

#endif // CANONOFENSIVO_H
