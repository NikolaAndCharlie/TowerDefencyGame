#ifndef  TOWER_H_
#define  TOWER_H_
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>

class Tower:public QObject,public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Tower();
  virtual void Fire();
  double DistanceTo(QGraphicsItem*);
  QPointF attact_dest;
  bool has_target_;
private:
  QGraphicsPolygonItem *attact_area;
public slots:
  void AcquireTarget();
  
};



#endif
