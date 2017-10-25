#ifndef ROTATINGEVENTHANDLER_H
#define ROTATINGEVENTHANDLER_H

#include <QObject>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QVector>
#include <cuboid.h>
#include <orbittransformcontroller.h>
#include <QTimer>
#include <axishandler.h>

class RotatingEventHandler : public QObject
{
    Q_OBJECT
public:
    RotatingEventHandler(Cuboid *cube);

public slots:
    void UC();
    void UCC();

//    void DC();
//    void DCC();

//    void LC();
//    void LCC();

    void RC();
    void RCC();

    void FC();
    void FCC();

//    void BC();
//    void BCC();

private slots:
    void rotate();

//    void uc();
//    void ucc();

//    void DC();
//    void DCC();

//    void LC();
//    void LCC();

//    void rc();
//    void rcc();

//    void fc();
//    void fcc();

private:
    //QVector3D getCenterPointRight();
   // QVector3D getCentrePointUp();
   // QVector3D getCenterPointFront();

    //QVector<QPropertyAnimation*> vectAnimation;
    //OrbitTransformController *cube2controller;
    Qt3DCore::QTransform *transform;
//    QMatrix4x4 RightC, RightCC, UpC, UpCC,
//        FrontC, FrontCC;

    int count = 0;
    QTimer *timer;

    Cuboid* m_cube;
    QMatrix4x4 rotationMatrix;
};

#endif // ROTATINGEVENTHANDLER_H
