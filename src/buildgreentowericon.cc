#include "buildgreentowericon.h"
#include "game.h"
#include "green_tower.h"


extern Game *game;
BuildGreenTowerIcon::BuildGreenTowerIcon()
{
  setPixmap(QPixmap(":/tower.ico"));
}


void BuildGreenTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  if(!game->build)
  {
    game->build = new GreenTower();
    game->setCursor(QString(":/tower.ico"));
  }
}



