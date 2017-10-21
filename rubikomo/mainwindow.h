#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./View3DHeaders/view3d.h"
#include "controllerrubik.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    View3D* m_view3D;
    ControllerRubik controllerRubik;
};

#endif // MAINWINDOW_H
