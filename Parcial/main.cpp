#include <iostream>
#include "bala.h"
#include "canon.h"

using namespace std;

int main()
{
    Canon *ofensivo; //cañon ofensivo
    Canon *defensivo; //cañon defensivo
    Bala *disparo; //disparo

    ofensivo = new Canon(20);
    defensivo = new Canon(100);



    return 0;
}
