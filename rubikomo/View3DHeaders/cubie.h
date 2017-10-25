#ifndef CUBIE_H
#define CUBIE_H

#include "./View3DHeaders/cuboid.h"
#include "./View3DHeaders/icubie.h"
#include "./View3DHeaders/animationhandler.h"
#include "modelrubik.h"

class Cubie : public ICubie{
public:
    explicit Cubie(Qt3DCore::QEntity *rootEntity, bool isCorner);
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

    void updateColors(Corner corner,CornerOrientation orient)=0;
    void updateColors(Edge edge,EdgeOrientation orient)=0;
    void updateColors(RubikFace centre)=0;

    Qt3DCore::QEntity* entity();
    Qt3DCore::QTransform* transf();

    void setTranslation(QVector3D trans);

protected:
    Cuboid *m_cuboid;
    AnimationHandler *animHandler;
};
#endif // CUBIE_H
