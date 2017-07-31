#include "redtower.h"
#include <QTimer>
#include "game.h"
#include "bullet.h"

extern Game *game;

RedTower::RedTower()
{
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &RedTower::AcquiredTarget);
  timer->start(1000);
  
  attact_dest = QPointF(0, 0);
  has_target_ = false;
}

void RedTower::Fire()
{
  Bullet *bullet = new Bullet;
  bullet->setPixmap(QPixmap(":/redbullet.ico"));
  bullet->setPos(x() + 24, y() + 24);

  QLineF ln(QPointF(x() + 24, y() + 24), attact_dest);
  int angle = -1 * ln.angle();

  bullet->setRotation(angle);
  game->scene_->addItem(bullet);
}

void RedTower::AcquiredTarget()
{
  Tower::AcquireTarget();
}
