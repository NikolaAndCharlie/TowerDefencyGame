#include "game.h"
#include "tower.h"
#include "Bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QPixmap>
#include<QVector>
#include <QPolygonF>


extern Game *game;
Tower::Tower()
{
  setPixmap(QPixmap(":/tower.ico"));


  //ploygon 
  QVector<QPointF>points;
  points << QPoint(1, 0) << QPointF(2, 0) << QPointF(3, 1) << QPointF(3, 2) << QPointF(2, 3) << QPointF(1, 3) << QPointF(0, 2) << QPointF(0, 1);

  for(size_t i = 0,n = points.size();i<n;i++)
  {
    points[i] *= 60;
  }
  QPolygonF polygon(points);
  attact_area = new QGraphicsPolygonItem(polygon,this);
  
  QPointF attact_center(1.5, 1.5);
  attact_center *= 60;
//  attact_center = mapToScene(attact_center);
  QPointF tower_center(x() + 24, y() + 24);
  QLineF ln(attact_center, tower_center);
  attact_area->setPos(x() + ln.dx(), y() + ln.dy());
  double a = x() + ln.dx();
  double b = y() + ln.dy();
  
  QTimer *timer = new QTimer();
  connect(timer, &QTimer::timeout, this, &Tower::AcquireTarget);
  timer->start(1000);

  attact_dest = QPointF(0,0);
  has_target_ = false;
}

void Tower::AcquireTarget()
{
  has_target_ = false;
  QList<QGraphicsItem*> colliding_items = attact_area->collidingItems();
  if(colliding_items.size() == 1)
  {
    has_target_ = false;
    return;
  }
  double closeset_dist = 300;
  QPointF closest_pt = QPointF(0, 0);
  for(size_t i = 0,n = colliding_items.size();i<n;i++)
  {
    Enemy *enemy = dynamic_cast<Enemy*>(colliding_items[i]);
    if(enemy)
    {
      double this_dist = DistanceTo(enemy);
      if(this_dist<closeset_dist)
      {
        closeset_dist = this_dist;
        closest_pt = colliding_items[i]->pos();
        has_target_ = true;
      }
    }
  }
  if(has_target_)
  {
    
  attact_dest = closest_pt;
  Fire();
  }
}

void Tower::Fire()
{
  Bullet *bullet = new Bullet;
  bullet->setPos(x() + 24, y() + 24);
  QLineF ln(QPointF(x() + 24, y() + 24), attact_dest+QPointF(20,30));
  int angle = -1 * ln.angle();
  bullet->setRotation(angle);
  game->scene()->addItem(bullet);
  
}

double Tower::DistanceTo(QGraphicsItem*item)
{
  QLineF ln(pos(), item->pos());
  return ln.length();
}