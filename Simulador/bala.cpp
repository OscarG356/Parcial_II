#include "bala.h"

Bala::Bala(bool Type)
{
    if(Type==true){

    }

    setPixmap(QPixmap(":/new/prefix1/Bala.png"));
    setScale(0.5);

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bala::move()
{

}
