#ifndef CANONDEFENSIVO_H
#define CANONDEFENSIVO_H
#include <canon.h>
#include <movimientos.h>
#include <QDebug>

class CanonDefensivo : public Canon , public Movimientos
{
public:
    CanonDefensivo(short int posx, short int posy);
    void disparoLibre();
    bool alerta_disparo( qreal x, qreal y, short int angle , short int velocidad_disparo); // para implementar

};

#endif // CANONDEFENSIVO_H
