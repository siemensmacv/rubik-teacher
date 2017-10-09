#include "MainWindow.h"
#include <QGuiApplication>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    connect(ui.myButton,&QPushButton::clicked,
            this, &MainWindow::on_myButton_pressed);
}

void MainWindow::on_myButton_pressed()
{
    QApplication::quit();
}
