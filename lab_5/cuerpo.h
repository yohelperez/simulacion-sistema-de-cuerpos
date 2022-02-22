#ifndef CUERPO_H
#define CUERPO_H
// clase que me genera las posiciones (movimiento)
class cuerpo
{
private:
    float px;//posicion en x
    float py;//posicion en y
    float masa;//masa del cuerpo
    float R;//radio del cuerpo
    float vx;//velocidad en x
    float vy;//velocidad en y
    float alfa;//angulo en el que va el cuerpo.
    float ax;//aceleracion en x
    float ay;//aceleracion en y
    float g;//gravedad
    float K;//resistencia del aire
    float e;//coeficiente de restitucion.
    float v;//vector velocidad.
    float dt;//delta de tiempo.
public:
    cuerpo(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_);
    ~cuerpo();
    void actualizar();
    float get_posX();
    float get_posY();
    float get_Radio();
    float get_e();
    float get_velX();
    float get_velY();
    float get_masa();
    void set_vel(float vx_, float vy_, float px_, float py_);
};

#endif // CUERPOS_H
