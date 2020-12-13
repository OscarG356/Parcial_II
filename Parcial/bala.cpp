#include "bala.h"

Bala::Bala(int x, int y, bool type)
{
    Xi=x;
    Yi=y;

    if(type){
        Rang=0.025*800;
    }
    else
        Rang=0.05*800;
}

bool Bala::impacto(int x, int y,float Xb,float Yb, int R) //Distancia entre dos puntos
{
    bool flag= false;

    if(sqrt(pow((x - Xb),2)+pow((y - Yb),2)) < R){
        flag = true;
    }

    return flag;
}

float Bala::getRang() const
{
    return Rang;
}
