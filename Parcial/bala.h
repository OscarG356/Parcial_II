#ifndef BALA_H
#define BALA_H

#include "canon.h"

class Bala
{
protected:
    float Xi; //Posicion de la bala en X y Y
    float Yi;

    float Rang; //Rango de daño de la bala

    float Angle; //Angulo de disparo

    float VelX; //Velocidad inicial
    float VelY;

public:
    Bala(int x,int y,bool type); // X y Y en este caso es la posicion inicial
                                 // la cual traigo del cañon, mientras que el
                                 // el boleano me ayuda a determina el rango
                                 // pasando un true si es defensivo o false
                                 // si ofensivo.

    bool impacto (int x, int y);

};

#endif // BALA_H
