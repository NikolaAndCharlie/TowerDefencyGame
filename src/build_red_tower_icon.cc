#include "build_red_tower_icon.h"
#include "game.h"
#include "redtower.h"

extern Game  *game;

void BuildRedTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent*)
{
  if(!game->build)
  {
    game->build = new RedTower();
    game->setCursor(QString(":/tower.ico"));
  }
}

BuildRedTowerIcon::BuildRedTowerIcon()
{
  setPixmap(QPixmap(":/tower.ico"));
}



