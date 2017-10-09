#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QtWidgets>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private slots:
    void on_myButton_pressed();

private:
    QPushButton *myButton;
	Ui::MainWindowClass ui;
};
