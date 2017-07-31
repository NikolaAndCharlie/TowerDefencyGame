#ifndef GREEN_TOWER_H_
#define GREEN_TOWER_H_
#include "tower.h"

class GreenTower:public Tower
{
  Q_OBJECT
public:
  GreenTower(QGraphicsItem*parent = 0);
  void Fire() override;
public:
  void aquire_target();

};



#endif
