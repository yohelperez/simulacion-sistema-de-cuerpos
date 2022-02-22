#include "cuerpo.h"
#include <math.h>
#include <cmath>

cuerpo:: cuerpo(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_)//constructor sobrecargado con las cosas
{
    px = posX_;
    py = posY_;
    masa = masa_;
    R = radio_;
    vx = velX_;
    vy = velY_;
    ax = 0;
    ay = 0;
    g = 9.8;
    K = K_;
    e = e_;
    v = 0;
    dt = 0.1;

}
cuerpo::~cuerpo()//destructor por defecto
{

}
void cuerpo::actualizar(){// actualiza las pociciones del cuerpo con las ecuaciones de movimiento.

    v = pow((pow(vx,2)+pow(vy,2)),(1/2));

    alfa = atan2(vy,vx);
    ax = -((K*pow(v,2)*pow(R,2))/masa)*cos(alfa);
    ay = (-((K*(v*v)*(R*R))/masa)*sin(alfa))-g;

    px += ((vx*(dt))) + (((ax*(dt*dt)))/2);
    py += ((vy*(dt))) + (((ay*(dt*dt)))/2);
    vx += ax*dt;
    vy += ay*dt;

}

float cuerpo::get_posX(){//retorna la posicion en x
    return px;
}

float cuerpo::get_posY(){//retorna la posicion en y.
    return py;
}

float cuerpo::get_Radio(){//retorna el radio
    return R;
}

float cuerpo::get_velX(){//retorna la velocidad en x.
    return vx;
}

float cuerpo::get_velY(){//retorna la velocidad en y.
    return vy;
}

float cuerpo::get_masa(){//retorna la masa
    return masa;
}

float cuerpo::get_e(){//retorna el coeficiente de restitucion.
    return e;
}

void cuerpo::set_vel(float vx_, float vy_, float px_, float py_){//asigna las velocidad y posiciones del cuerpo.
    vx = vx_;
    vy = vy_;
    px = px_;
    py = py_;
}
