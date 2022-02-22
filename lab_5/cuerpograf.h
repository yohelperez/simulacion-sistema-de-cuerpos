//clase que me genera las esferas
#ifndef CUERPOGRAF_H
#define CUERPOGRAF_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "cuerpo.h"
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */

class cuerpograf: public QGraphicsItem          //Clase para graficar las esferas
{
public:
    cuerpograf();
    ~cuerpograf();
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
    void setEscala(float s);
    void actualizar(float v_lim);
    cuerpo* getEsf();
private:
    cuerpo* esf; //se crea un puntero tipo cuerpo para las posiciones
    float escala;//se crea una escala
};

#endif // CUERPOGRAF_H
