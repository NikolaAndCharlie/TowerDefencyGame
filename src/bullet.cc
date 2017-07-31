#include "game.h"
#include "bullet.h"
#include <qmath.h>
#include <QTimer>


Bullet::Bullet(QGraphicsItem* parent):QObject(),QGraphicsPixmapItem(parent)
{
  setPixmap(QPixmap(":/arrow.ico"));

  QTimer *move_timer = new QTimer(this);
  connect(move_timer, &QTimer::timeout, this, &Bullet::move);
  move_timer->start(50);


  max_rang_ = 100;
  distance_travelled_ = 50;
}

void Bullet::move()
{
  int step_size = 30;
  double theta = rotation();
  double dy = step_size*qSin(qDegreesToRadians(theta));
  double dx = step_size*qCos(qDegreesToRadians(theta));

  setPos(x() + dx, y() + dy);
}

double Bullet::GetMaxRange()
{
  return max_rang_;
}

double Bullet::GetDistannceTravelled()
{
  return distance_travelled_;
}

void Bullet::SetMaxRange(double rng)
{
  max_rang_ = rng;
}

void Bullet::SetDistanceTravelled(double dist)
{
  distance_travelled_ = dist;
}





  
