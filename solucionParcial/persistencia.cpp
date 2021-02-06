#include "persistencia.h"

Persistencia::Persistencia(qreal x, qreal y)
{
    this->setRect(0,0,20,20);
    this->setPos(x,y);
    time_life = new QTimer();
    connect(time_life,SIGNAL(timeout()),this,SLOT(actions()));
    time_life->start(80);
}

void Persistencia::actions()
{
   desaparicion=desaparicion-100;
   if(desaparicion<0){
       scene()->removeItem(this);
       delete this;
   }
   opacidad=opacidad-0.1;
   //setOpacity(opacidad);
}

QRectF Persistencia::boundingRect() const
{
    return QRectF(0,0,30,30);
}

void Persistencia::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::yellow);
    painter->setPen(Qt::NoBrush);
    painter->drawEllipse(boundingRect());
}
