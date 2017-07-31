#ifndef  GAME_H_
#define  GAME_H_
#include "tower.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class Game :public QGraphicsView
{
public:
  Game();
  void mousePressEvent(QMouseEvent *event);
  void setCursor(QString filename);
  void mouseMoveEvent(QMouseEvent *event);
  Tower *build;
  QGraphicsScene *scene_;
private:
  QGraphicsPixmapItem *cursor;

};




#endif
