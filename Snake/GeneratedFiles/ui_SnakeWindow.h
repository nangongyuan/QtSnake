/********************************************************************************
** Form generated from reading UI file 'SnakeWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAKEWINDOW_H
#define UI_SNAKEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SnakeWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SnakeWindowClass)
    {
        if (SnakeWindowClass->objectName().isEmpty())
            SnakeWindowClass->setObjectName(QStringLiteral("SnakeWindowClass"));
        SnakeWindowClass->resize(600, 400);
        menuBar = new QMenuBar(SnakeWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SnakeWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SnakeWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SnakeWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SnakeWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SnakeWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SnakeWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SnakeWindowClass->setStatusBar(statusBar);

        retranslateUi(SnakeWindowClass);

        QMetaObject::connectSlotsByName(SnakeWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SnakeWindowClass)
    {
        SnakeWindowClass->setWindowTitle(QApplication::translate("SnakeWindowClass", "SnakeWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SnakeWindowClass: public Ui_SnakeWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKEWINDOW_H
