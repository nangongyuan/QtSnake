#pragma once

#include <QGraphicsItem>

class Food : public QGraphicsItem
{


public:

	Food(qreal x, qreal y);
	~Food();

	QRectF boundingRect() const;

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

	QPainterPath shape() const;
};
