#ifndef BALA_H
#define BALA_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Bala: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    float Xi,Yi;
    float Range;
    float Vx,Vy;
    bool Type;

public:
    Bala(bool Type);
public slots:
    void move();
};

#endif // BALA_H
