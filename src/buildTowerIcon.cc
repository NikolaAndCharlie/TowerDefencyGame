#include  "buildtowericon.h"
#include "game.h"

extern Game *game;

BuildTowerIcon::BuildTowerIcon(QGraphicsItem* paraent)
{
  setPixmap(QPixmap(":/tower.ico"));
}

void BuildTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  if(!game->build)
  {
    game->build = new Tower();
    game->setCursor(QString(":/tower.ico"));
  }
}

