#ifndef _RED_TOWER_H_
#define _RED_TOWER_H_
#include "tower.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class RedTower:public Tower
{
public:
  RedTower();
  void Fire() override;
private:
  void AcquiredTarget();
};

#endif
