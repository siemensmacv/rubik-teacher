#ifndef ROTATINGEVENTHANDLER_H
#define ROTATINGEVENTHANDLER_H

#include <QObject>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QVector>
//#include <cuboid.h>
#include <./View3DHeaders/orbittransformcontroller.h>

class RotatingEventHandler : public QObject
{
    Q_OBJECT
public:
    RotatingEventHandler(QPushButton*, QPushButton*, OrbitTransformController *);
    void addAnimation(QPropertyAnimation*);
public slots:
    void buttonPressed();
    void button2Pressed();
    void animationEnded();
private:
    QVector<QPropertyAnimation*> vectAnimation;
    QPushButton *m_button, *m_button2;
    OrbitTransformController *cube2controller;

};

#endif // ROTATINGEVENTHANDLER_H
