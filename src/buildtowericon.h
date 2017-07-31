#ifndef BUILDTOWERICON_H_
#define BUILDTOWERICON_H_
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>


class BuildTowerIcon:public QGraphicsPixmapItem
{
public:
  BuildTowerIcon(QGraphicsItem *paraent = 0);
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
};



#endif
