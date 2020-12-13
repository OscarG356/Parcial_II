#include "bala.h"

Bala::Bala(int x, int y, bool type)
{
    Xi=x;
    Yi=y;

    if(type){
        Rang=0.025*x;
    }
    else
        Rang=0.05*x;
}

bool Bala::impacto(int x, int y)
{

}
