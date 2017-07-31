#include "enemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>



Enemy::Enemy()
{
  setPixmap(QPixmap(":/enemy.ico"));
  
  points_ << QPointF(200, 200) << QPointF(400, 200);
  point_index_ = 0;
  dest_ = points_[point_index_];
  rotateToPoint(dest_);
  setScale(0.5);

  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &Enemy::MoveForward);
  timer->start(150);
}


void Enemy::rotateToPoint(QPointF p)
{
  QLineF ln(pos(), p);
  setRotation(-1 * ln.angle());
}

void Enemy::MoveForward()
{
  QLineF ln(pos(), dest_);
  if(ln.length()<5)
  {
    point_index_++;
    if(point_index_>=points_.size())
    {
      return ;
    }
    dest_ = points_[point_index_];
    rotateToPoint(dest_);
  }


  int step_size = 5;
  double theta = rotation();

  double dx = step_size *qSin(qDegreesToRadians(theta));
  double dy = step_size *qCos(qDegreesToRadians(theta));


  setPos(x() + dx, y() + dy);
}



