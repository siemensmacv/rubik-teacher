#ifndef VIEW3D_H
#define VIEW3D_H

#include <QWidget>
#include <QObject>

#include "./View3DHeaders/cube3d.h"
#include "modelrubik_cornersedges.h"
#include <QHBoxLayout>
#include <QMainWindow>
#include "ui_mainwindow.h"

#define ANIMATION_DURATION 1100

namespace Ui {
class MainWindow;
};

class View3D : public QObject{
    Q_OBJECT
public:
    View3D(ModelRubik_CornersEdges *model3D,Ui::MainWindow *ui);

    QWidget *getContainer() const;

    //to be destroyed
public slots:
    void UpC();//
    void UpCC();
    void DownC();
    void DownCC();
    void FrontC();
    void FrontCC();
    void BackC();
    void BackCC();
    void RightC();//
    void RightCC();
    void LeftC();
    void LeftCC();

    void onAnimationEnded();

private:
    void toggleAllButtons(bool toggle);

    QTimer *timer;
    Ui::MainWindow *m_ui;
    void initCube3D();
    Cube3D *theCube;
    ModelRubik_CornersEdges* m_model3D;
    QWidget * container;

};
#endif // VIEW3D_H
