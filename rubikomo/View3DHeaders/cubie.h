#ifndef CUBIE_H
#define CUBIE_H

#include "./View3DHeaders/cuboid.h"
#include "./View3DHeaders/icubie.h"
#include "./View3DHeaders/animationhandler.h"
#include "modelrubik.h"

class Cubie : public ICubie{
public:
    explicit Cubie(Qt3DCore::QEntity *rootEntity);
    void UpC();
    void UpCC();
    void DownC();
    void DownCC();
    void FrontC();
    void FrontCC();
    void BackC();
    void BackCC();
    void RightC();
    void RightCC();
    void LeftC();
    void LeftCC();

    void updateColors(QColor upDownColor, QColor frontBackColor, QColor leftRightColor)=0;
    void updateColors(QColor plane1Color, QColor plane2Color)=0;
    void updateColors(QColor color)=0;

    Qt3DCore::QEntity* entity();
    Qt3DCore::QTransform* transf();

    void setTranslation(QVector3D trans);

protected:
    Cuboid *m_cuboid;
    AnimationHandler *animHandler;
};
#endif // CUBIE_H
