#ifndef BUILDGREENTOWERICON_H_
#define BUILDGREENTOWERICON_H_
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildGreenTowerIcon:public QGraphicsPixmapItem
{
public:
  BuildGreenTowerIcon();
  void mousePressEvent(QGraphicsSceneMouseEvent*);

};



#endif
