#ifndef ICUBIE_H
#define ICUBIE_H

#include "./View3DHeaders/plane.h"


class ICubie{
public:
   virtual void UpC()=0;//
   virtual void UpCC()=0;
   virtual void DownC()=0;
   virtual void DownCC()=0;
   virtual void FrontC()=0;
   virtual void FrontCC()=0;
   virtual void BackC()=0;
   virtual void BackCC()=0;
   virtual void RightC()=0;//
   virtual void RightCC()=0;
   virtual void LeftC()=0;
   virtual void LeftCC()=0;

    virtual Plane* upDownPlane()=0;
    virtual Qt3DCore::QEntity* entity()=0;
    virtual Qt3DCore::QTransform* transf()=0;
    virtual Cuboid* cuboid()=0;
};
#endif // ICUBIE_H
