#ifndef CANON_H
#define CANON_H
#include <QGraphicsRectItem>
#include <proyectil.h>
#include <QGraphicsScene>


class Canon : public QGraphicsRectItem
{
public:
    Canon(unsigned short int posx , unsigned short int posy);
    void subir();
    void bajar();
    void izquierda();
    void derecha();
};

#endif // CANON_H
