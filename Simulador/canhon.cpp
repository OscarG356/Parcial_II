#include "canhon.h"

Canhon::Canhon(QGraphicsItem *parent,bool bando)
{
    if (bando == true){
        setPixmap(QPixmap(":/new/prefix1/Canhon_D.png"));
        setScale(0.20);
    }
    else{
        setPixmap(QPixmap(":/new/prefix1/Canhon_A.png"));
        setScale(0.20);
    }
}

void Canhon::keyPressEvent(QKeyEvent *event)
{

}
