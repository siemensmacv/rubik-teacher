#ifndef VIEW3D_H
#define VIEW3D_H

#include <QWidget>
#include <QObject>

#include "./View3DHeaders/cube3d.h"
#include "modelrubik.h"
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
    View3D(ModelRubik *model3D, Ui::MainWindow *ui);

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

    void resetCamera();

    void onAnimationEnded();

    void onInput(int load);

private:
    void toggleAllButtons(bool toggle);
    void reset();
    void refreshCubeColors();
    void initScene();
    void getLight(QVector3D position);


    QTimer *timer;
    Ui::MainWindow *m_ui;

    void initCube3D();

    Qt3DCore::QEntity *rootEntity;
    Qt3DCore::QEntity *cubeEntity;

    Qt3DRender::QCamera *cameraEntity;

    Cube3D *theCube;
    ModelRubik* m_model3D;
    QWidget * container;
    Qt3DExtras::Qt3DWindow *view;

};
#endif // VIEW3D_H
