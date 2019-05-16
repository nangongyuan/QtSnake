#include "SnakeWindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>

#define TILE_SIZE 20

SnakeWindow::SnakeWindow(QWidget *parent):
	QMainWindow(parent),scene(new QGraphicsScene(this)),
	view(new QGraphicsView(scene, this)), game(new GameController(*scene, this))
{
	setCentralWidget(view);

	setFixedSize(600, 600);
	setWindowIcon(QIcon(":/SnakeWindow/snake.ico"));

	createActions();
	createMenus();

	initScene();
	initSceneBackground();

	QTimer::singleShot(0, this, SLOT(adjustViewSize()));


}

void SnakeWindow::adjustViewSize()
{
	view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);

}

void SnakeWindow::createActions()
{
	newGameAction = new QAction(tr("&New Game"), this);
	newGameAction->setShortcut(QKeySequence::New);
	newGameAction->setStatusTip(tr("Start a new game"));
	connect(newGameAction, &QAction::triggered, this, &SnakeWindow::newGame);

	exitAction = new QAction(tr("&Exit"), this);
	exitAction->setShortcut(tr("Ctrl+Q"));
	exitAction->setStatusTip(tr("Exit the game"));
	connect(exitAction, &QAction::triggered, this, &SnakeWindow::close);

	pauseAction = new QAction(tr("&Pause"), this);
	pauseAction->setStatusTip(tr("Pause..."));
	connect(pauseAction, &QAction::triggered, game, &GameController::pause);

	resumeAction = new QAction(tr("&Resume"), this);
	resumeAction->setStatusTip("&Resume...");
	connect(resumeAction, &QAction::triggered, game, &GameController::resume);

	gameHelpAction = new QAction(tr("Game &Help"), this);
	gameHelpAction->setShortcut(tr("Ctrl+H"));
	gameHelpAction->setStatusTip(tr("Help on this game"));
	connect(gameHelpAction, &QAction::triggered, this, &SnakeWindow::gameHelp);

	aboutAction = new QAction(tr("About"), this);
	aboutAction->setStatusTip(tr("Show the application's about box"));
	connect(aboutAction, &QAction::triggered, this, &SnakeWindow::about);

	aboutQtAction = new QAction(tr("About &Qt"), this);
	aboutQtAction->setStatusTip(tr("Show the qt library's About box"));
	connect(aboutQtAction, &QAction::triggered, qApp, &QApplication::aboutQt);

}

void SnakeWindow::createMenus()
{
	QMenu *options = menuBar()->addMenu(tr("&Options"));
	options->addAction(newGameAction);
	options->addSeparator();
	options->addAction(pauseAction);
	options->addAction(resumeAction);
	options->addSeparator();
	options->addAction(exitAction);

	QMenu *help = menuBar()->addMenu(tr("&Help"));
	help->addAction(gameHelpAction);
	help->addAction(aboutAction);
	help->addAction(aboutQtAction);
}

void SnakeWindow::initScene()
{
	//左上角的坐标 -100, 100 长度和宽度为200
	scene->setSceneRect(-100, -100, 200, 200);

}

void SnakeWindow::initSceneBackground()
{
	QPixmap bg(TILE_SIZE, TILE_SIZE);
	QPainter p(&bg);
	p.setBrush(QBrush(Qt::gray));
	p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);

	view->setBackgroundBrush(QBrush(bg));
}

void SnakeWindow::newGame()
{
	QTimer::singleShot(0, game, &GameController::gameOver);
}

void SnakeWindow::about()
{
	QMessageBox::about(this, tr("About this Game"), tr("<h2>Snake Game</h2>"
		"<p>Copyright &copy; XXX."
		"<p>This game is a small Qt application. It is based on the demo in the GitHub written by Devbean."));

}

void SnakeWindow::gameHelp()
{
	QMessageBox::about(this, tr("Game Help"), tr("Using direction keys to control the snake to eat the food"
		"<p>Space - pause & resume"));
}