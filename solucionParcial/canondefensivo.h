#ifndef CANONDEFENSIVO_H
#define CANONDEFENSIVO_H
#include <canon.h>

class CanonDefensivo : public Canon
{
public:
    CanonDefensivo(short int posx, short int posy);
    void disparoLibre();
    void alerta_disparo( qreal x, qreal y, short int angle , short int velocidad_disparo); // para implementar

};

#endif // CANONDEFENSIVO_H
