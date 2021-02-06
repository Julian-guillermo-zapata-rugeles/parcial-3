#ifndef CANON_H
#define CANON_H
#include <QGraphicsRectItem>
#include <proyectil.h>
#include <QGraphicsScene>
#include <QMediaPlayer>
class Canon : public QGraphicsPixmapItem
{
public:
    Canon(unsigned short int posx , unsigned short int posy);

    // métodos
    void subir();
    void bajar();
    void izquierda();
    void derecha();
    void disparoLibre();
    void explotar();
    void alarma();
protected:
    QMediaPlayer *sonido;

};

#endif // CANON_H
