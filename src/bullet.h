#ifndef  BULLET_H_
#define BULLET_H_
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bullet: public QObject,public QGraphicsPixmapItem
{
public:
  Bullet(QGraphicsItem* parent =0);
  public slots :
    void move();
    double GetMaxRange();
    double GetDistannceTravelled();
    void SetMaxRange(double rng);
    void SetDistanceTravelled(double dist);

private:
  double max_rang_;
  double distance_travelled_;
};


#endif
