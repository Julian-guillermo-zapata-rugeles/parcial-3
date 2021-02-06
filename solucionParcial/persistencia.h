#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <QObject>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>

class Persistencia : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
public:
    Persistencia(qreal x, qreal y);
private:
    QTimer * time_life;
    short int desaparicion =1000;
    qreal opacidad = 1;
private slots:
    void actions();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PERSISTENCIA_H
