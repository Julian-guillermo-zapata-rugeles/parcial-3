#ifndef CANON_H
#define CANON_H
#include <QGraphicsRectItem>
#include <proyectil.h>
#include <QGraphicsScene>


class Canon : public QGraphicsRectItem
{
public:
    Canon(unsigned short int posx , unsigned short int posy);

    // métodos
    void subir();
    void bajar();
    void izquierda();
    void derecha();
    void disparoLibre();

};

#endif // CANON_H
