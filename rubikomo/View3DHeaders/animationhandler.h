#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include "./View3DHeaders/cuboid.h"

#include <Qt3DCore>

class AnimationHandler : public QObject
{
    Q_OBJECT
public:
    explicit AnimationHandler(Cuboid *cuboid);

    static void UpC();//
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

signals:
    void animationEnded();
private:
    Qt3DCore::QTransform *transform;

    int count = 0;
    QTimer *timer;

    Cuboid* m_cube;
    QMatrix4x4 rotationMatrix;

    //map corner
    //map edge
    void rotate();

};

#endif // ANIMATIONHANDLER_H
