#ifndef DELIMITANTES_H
#define DELIMITANTES_H

#include <QGraphicsRectItem>
#include <QPainter>

class Delimitantes : public QGraphicsRectItem
{
public:
    Delimitantes(qreal x, qreal y);

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // DELIMITANTES_H
