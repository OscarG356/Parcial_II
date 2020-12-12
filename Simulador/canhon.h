#ifndef CANHON_H
#define CANHON_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>
#include <QObject>

class Canhon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int d=800;
    int Hi;
public:
    Canhon(QGraphicsItem *parent=0,bool bando=true);
    void keyPressEvent(QKeyEvent *event);
};

#endif // CANHON_H
