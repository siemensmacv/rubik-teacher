#ifndef ICUBIE_H
#define ICUBIE_H

#include "./View3DHeaders/plane.h"


class ICubie{
public:
    virtual void startXAxisClockAnim() = 0;
    virtual void startXAxisCClockAnim() = 0;
    virtual void startYAxisClockAnim() = 0;
    virtual void startYAxisCClockAnim() = 0;
    virtual void startZAxisClockAnim() = 0;
    virtual void startZAxisCClockAnim() = 0;
    virtual Plane* upDownPlane()=0;
};
#endif // ICUBIE_H
