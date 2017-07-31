#ifndef ENEMY_H_
#define ENEMY_H_
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Enemy:public QObject,public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Enemy();
  void rotateToPoint(QPointF p);
public slots:
    void MoveForward();
private:
  QList<QPointF> points_;
  QPointF dest_;
  int point_index_;
};



#endif
