#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtCore/QTimer>
#include "GameController.h"
#include <QAction>

class SnakeWindow : public QMainWindow
{
	Q_OBJECT

public:
	SnakeWindow(QWidget *parent = Q_NULLPTR);

private slots:
	void adjustViewSize();
	void newGame();
	void gameHelp();
	void about();

private:
	void createActions();
	void createMenus();

	QGraphicsScene *scene;
	QGraphicsView *view;

	GameController *game;

	QAction *newGameAction;
	QAction *pauseAction;
	QAction *resumeAction;
	QAction *exitAction;
	QAction *gameHelpAction;
	QAction *aboutAction;
	QAction *aboutQtAction;

	void initScene();
	void initSceneBackground();
};
