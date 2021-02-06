#include "delimitantes.h"

Delimitantes::Delimitantes(qreal x, qreal y)
{
    this->setRect(0,0,200,200);
    this->setPos(x-this->boundingRect().width()/2,y-this->boundingRect().height()/2);
}

QRectF Delimitantes::boundingRect() const
{
    return QRectF(0,0,500,500);
}

void Delimitantes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::blue);
    painter->setPen(Qt::NoBrush);
    painter->drawEllipse(boundingRect());
}
