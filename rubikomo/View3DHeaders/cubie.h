#ifndef CUBIE_H
#define CUBIE_H

#include "./View3DHeaders/cuboid.h"
#include "./View3DHeaders/icubie.h"
#include "./View3DHeaders/animationhandler.h"

class Cubie : public ICubie{
public:
    Cubie();
    void startXAxisClockAnim();
    void startXAxisCClockAnim();
    void startYAxisClockAnim();
    void startYAxisCClockAnim();
    void startZAxisClockAnim();
    void startZAxisCClockAnim();
private:
    Cuboid *m_cuboid;
};
#endif // CUBIE_H
