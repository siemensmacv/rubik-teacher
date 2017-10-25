#ifndef ICUBIE_H
#define ICUBIE_H

#include "./View3DHeaders/plane.h"
#include "./View3DHeaders/cuboid.h"
#include "modelrubik.h"

class ICubie{
public:
    virtual void UpC()=0;
    virtual void UpCC()=0;
    virtual void DownC()=0;
    virtual void DownCC()=0;
    virtual void FrontC()=0;
    virtual void FrontCC()=0;
    virtual void BackC()=0;
    virtual void BackCC()=0;
    virtual void RightC()=0;
    virtual void RightCC()=0;
    virtual void LeftC()=0;
    virtual void LeftCC()=0;

    virtual void updateColors(Corner corner,CornerOrientation orient)=0;
    virtual void updateColors(Edge edge,EdgeOrientation orient)=0;
    virtual void updateColors(RubikFace centre)=0;

    virtual Qt3DCore::QEntity* entity()=0;
    virtual Qt3DCore::QTransform* transf()=0;
    virtual void setTranslation(QVector3D vec)=0;

};
#endif // ICUBIE_H
