#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./View3DHeaders/view3d.h"
#include "controllerrubik.h"
#include "./View2DHeaders/view2d.h"

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
    View2D* m_view2D;
    View3D* m_view3D;
    ControllerRubik controllerRubik;

    void connectFlatButtonsToSlots();

private slots:
    void handleButton();
};

#endif // MAINWINDOW_H
