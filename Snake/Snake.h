#pragma once

#include <QGraphicsItem>
#include "GameController.h"
#include "constants.h"

class Snake : public QGraphicsItem
{


public:
	enum Direction
	{
		NoMove,
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown
	};

	Snake(GameController &controller);
	~Snake();

	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = Q_NULLPTR */);

	void setMoveDirection(Direction direction);
	Direction currentDirection();

protected:
	void advance(int step);

private:
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void handleCollisions();

	QPointF head;
	int growing;
	int speed;
	QList<QPointF> tail;
	int tickCounter;
	Direction moveDirection;
	GameController &controller;
};
