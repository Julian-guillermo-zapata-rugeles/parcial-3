
#include <QGraphicsScene>
#include <proyectilEnemigo.h>

ProyectilEnemigo::ProyectilEnemigo(short velocidad_instantanea, short angle, float pos_x_const, float pos_y_const, bool reverse):
    Movimientos(500,pos_y_const,reverse)
{
    //this->setRect(0,0,20,20);
    this->setPixmap(QPixmap(":/recursos/bala.png"));
    setScale(0.1);
    this->configurarProyectil(velocidad_instantanea, angle , pos_x_const , pos_y_const);
    this->proyectil_en_movimiento=true;
    this->setPos(Movimientos::posicion_x,Movimientos::posicion_y+boundingRect().height());
    this->eventController = new QTimer;
    connect(eventController,SIGNAL(timeout()),this,SLOT(actions()));
    this->eventController->start(50);


}

ProyectilEnemigo::~ProyectilEnemigo()
{
scene()->removeItem(this);
qDebug()<<"Destructor Enemigo "<<endl;
}

void ProyectilEnemigo::actions()
{
    min=min+1;
    if(proyectil_en_movimiento==true){
        this->moverParabolicamente();
        this->setPos(Movimientos::posicion_x,Movimientos::posicion_y);
        scene()->addItem(new Persistencia(posicion_x,posicion_y));

    }else{
        qDebug()<<"ProyectilEnemigo salió de pantalla "<<endl;
        delete this;
    }



}

/*
QRectF ProyectilEnemigo::boundingRect() const
{
    return QRectF(0,0,20,20);
}

void ProyectilEnemigo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}
*/
