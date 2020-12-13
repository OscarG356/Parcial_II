#ifndef CANON_H
#define CANON_H


class Canon
{
private:
    int d=800;//Distancia entre los cañones
    int Hi; //Altura de los cañones

public:
    Canon(int _h); // Ya que la distancia entre los cañones siempre
                   // es la misma solo requiere variar la altura

    //Para pasar datos a los metodos que los requieren
    int getHi() const;
    int getD() const;

};

#endif // CANON_H
