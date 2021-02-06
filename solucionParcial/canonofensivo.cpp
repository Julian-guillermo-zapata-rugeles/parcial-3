#include "canonofensivo.h"


bool CanonOfensivo::getProyectil_fue_disparado() const
{
    return proyectil_fue_disparado;
}

void CanonOfensivo::setProyectil_fue_disparado(bool value)
{
    proyectil_fue_disparado = value;
}

void CanonOfensivo::setPosicionEnemigaY(const qreal &value)
{
    posicionEnemigaY = value;
}

qreal CanonOfensivo::getAnguloImpacto() const
{
    return anguloImpacto;
}

qreal CanonOfensivo::getVelocidadImpacto() const
{
    return velocidadImpacto;
}

void CanonOfensivo::setPosicionEnemigaX(const qreal &value)
{
    posicionEnemigaX = value;
}

void CanonOfensivo::disparoLibre()
{
    scene()->addItem(new Proyectil(100,anguloDisparo,this->pos().x(),this->pos().y()));
    proyectil_fue_disparado=true;
     explotar();
}

signed short CanonOfensivo::getAnguloDisparo() const
{
    return anguloDisparo;
}

void CanonOfensivo::setAnguloDisparo(signed short value)
{
    anguloDisparo = value;
}




bool CanonOfensivo::calcularTrayectorias()
{
    //this->posicion_x = pos().x();
    //this->posicion_y = pos().x();
    for(unsigned short int gradosInclinacion = 89 ; gradosInclinacion > 1 ; gradosInclinacion--){
        // mager para grados de 1 a 180
        //qDebug()<<" buscando en "<<gradosInclinacion << " grados "<<endl;
        for(unsigned short int velocidadProyectil=80; velocidadProyectil>5;velocidadProyectil--){
            // margen para velocidad 1 a 100
            //qDebug()<<"prueba para "<<gradosInclinacion <<"grados con "<<velocidad_instantanea<<" velocidad " << endl;
            bool exahustedSearch = false;


            // CONFIGURACIONES PARA LA TRAYECTORIA
            lastPosition=pos().y();
            intervaloSuma=0.2;
            configurarProyectil(velocidadProyectil,gradosInclinacion,pos().x(),pos().y());
            //---------------------------------


            while (exahustedSearch==false) {
                // se trazará una trayectoria ficticia que permitirá obtener coordenadas de avace
                //qDebug()<< "pos x : "<<posicion_x<<" pos y :"<<posicion_y<< endl;
                if(posicion_y>=550){
                    exahustedSearch=true;

                }
                else{
                    moverParabolicamente();
                    // BUG PARA SOLUCIONAR -- EL CICLO SE DETIENE //

                    if(comprobarCercania(posicion_x,posicion_y,posicionEnemigaX,posicionEnemigaY)==true){
                        //return true;
                        //anguloImpacto=gradosInclinacion;
                        //velocidadImpacto=velocidadProyectil;
                        //qDebug ()<< "se encontró que el angulo "<< gradosInclinacion << " y velocidad "<<velocidadProyectil << "es la trayectoria indicada "<<endl;
                        //qDebug() << posicionEnemigaX << " + " << posicionEnemigaY << " --> "<< posicion_x << " + "<< posicion_y << endl;
                        velocidadImpacto=velocidadProyectil;
                        anguloImpacto=gradosInclinacion;
                        proyectil_fue_disparado=true;
                        setRotation(anguloImpacto*-1);
                        return true;
                    }
                }

            }

        }
    }
    qDebug()<<" se acabó la busqueda " << endl;
    return false;
}

void CanonOfensivo::disparoCertero()
{
    if(calcularTrayectorias()==true){

       //scene()->addItem(new Proyectil(0,0,0,false));
        scene()->addItem(new ProyectilEnemigo(velocidadImpacto,anguloImpacto,pos().x(),pos().y()));
         explotar();
    }
    //if(calcularTrayectorias(){
    //    scene()->addItem(new Proyectil(velocidadImpacto,anguloImpacto,pos().x(),pos().y()));
    //}
}




CanonOfensivo::CanonOfensivo(short posx, short posy)
    :Canon(posx,posy),Movimientos(600,0)
{
    proyectil_fue_disparado=false;
    anguloDisparo=80;
    this->setTransformOriginPoint(this->boundingRect().center());
}
