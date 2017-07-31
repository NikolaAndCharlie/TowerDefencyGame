#include "green_tower.h"
#include "bullet.h"
#include "game.h"
#include <QGraphicsScene>
#include <QTimer>

extern Game* game;

GreenTower::GreenTower(QGraphicsItem* parent)
{
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &GreenTower::aquire_target);
  timer->start(1000);

  attact_dest = QPointF(0, 0);
  has_target_ = false;
}
void GreenTower::Fire()
{
  Bullet *bullet1 = new Bullet();
  Bullet *bullet2 = new Bullet();
  Bullet *bullet3 = new Bullet();

  bullet1->setPixmap(QPixmap(":/greenbullet.ico"));
  bullet2->setPixmap(QPixmap(":/greenbullet.ico"));
  bullet3->setPixmap(QPixmap(":/greenbullet.ico"));

  bullet1->setPos(x() + 24, y() + 24);
  bullet2->setPos(x() + 24, y() + 24);
  bullet3->setPos(x() + 24, y() + 24);

  QLineF ln(QPointF(x() + 44, y() + 44), attact_dest);
  int angle = -1 * ln.angle();

  bullet1->setRotation(angle);
  bullet2->setRotation(angle + 10);
  bullet3->setRotation(angle - 10);

  game->scene_->addItem(bullet1);
  game->scene_->addItem(bullet2);
  game->scene_->addItem(bullet3);


}

void GreenTower::aquire_target()
{
  Tower::AcquireTarget();
}




