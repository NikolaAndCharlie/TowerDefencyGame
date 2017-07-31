#ifndef BUILD_RED_TOWER_ICON_H_
#define BUILD_RED_TOWER_ICON_H_
#include <QGraphicsPixmapItem>
#include<QGraphicsSceneMouseEvent>

class BuildRedTowerIcon:public QGraphicsPixmapItem
{
public:
  void mousePressEvent(QGraphicsSceneMouseEvent *);
  BuildRedTowerIcon();

};



#endif
