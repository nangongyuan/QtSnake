#include "SnakeWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SnakeWindow w;
	w.show();
	return a.exec();
}
