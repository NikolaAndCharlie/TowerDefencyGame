#include "game.h"
#include "tower.h"
#include "enemy.h"
#include "bullet.h"
#include "buildtowericon.h"
#include <QGraphicsScene>
#include "build_red_tower_icon.h"
#include  "buildgreentowericon.h"

Game::Game()
{
  scene_ = new QGraphicsScene(this);
  scene_->setSceneRect(0, 0, 800, 600);
  setScene(scene_);
  Tower *tower = new Tower;
  tower->setPos(250, 250);
  scene_->addItem(tower);


  cursor = nullptr;
  build = nullptr;
  setMouseTracking(true);
  setFixedSize(800, 600);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  
  Enemy *enemy = new Enemy;
  scene()->addItem(enemy);

 // BuildTowerIcon *ic = new BuildTowerIcon;
  BuildGreenTowerIcon *bt = new BuildGreenTowerIcon;
  BuildRedTowerIcon *rt = new BuildRedTowerIcon;

//  scene_->addItem(ic);
  bt->setPos(0, 0);
  rt->setPos(0, 100);
  scene_->addItem(bt);
  scene_->addItem(rt);

}


void Game::setCursor(QString filename) {
  if (cursor) {
    scene_->removeItem(cursor);
    delete cursor;
  }

  cursor = new QGraphicsPixmapItem();
  cursor->setPixmap(QPixmap(filename));
  scene_->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event) {
  if (cursor) {
    cursor->setPos(event->pos());
  }
}

void Game::mousePressEvent(QMouseEvent *event) {
  if (build) {
    

    QList<QGraphicsItem*>items = cursor->collidingItems();
    for(size_t i = 0;i<items.size();i++)
    {
      if(dynamic_cast<Tower*>(items[i]))
      {
        return;
      }
    }

    scene_->addItem(build);
    build->setPos(event->pos());
    cursor = nullptr;
    build = nullptr;
  }
  else {
    QGraphicsView::mousePressEvent(event);
  }

}