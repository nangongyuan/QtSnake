#pragma once

#include <QObject>
#include <QTimer>

class QGraphicsScene;
class QKeyEvent;

class Snake;
class Food;
class Wall;

class GameController : public QObject
{
	Q_OBJECT

public:
	GameController(QGraphicsScene &scene, QObject *parent = 0);
	~GameController();

	void snakeAteFood(Food *food);
	
	void snakeAteItself();

public slots:
void pause();
void resume();
void gameOver();

protected:
	bool eventFilter(QObject *object, QEvent *event);

private:

	void handleKeyPressed(QKeyEvent *event);
	void addNewFood();

	QTimer timer;

	QGraphicsScene &scene;

	Snake *snake;
	bool isPause;
};
