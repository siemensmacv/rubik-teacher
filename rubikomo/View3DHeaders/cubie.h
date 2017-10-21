#ifndef CUBIE_H
#define CUBIE_H

#include "./View3DHeaders/cuboid.h"
#include "./View3DHeaders/icubie.h"
#include "./View3DHeaders/animationhandler.h"

class Cubie : public ICubie{
public:
    explicit Cubie(Qt3DCore::QEntity *rootEntity, bool isCorner);
    void startXAxisClockAnim();
    void startXAxisCClockAnim();
    void startYAxisClockAnim();
    void startYAxisCClockAnim();
    void startZAxisClockAnim();
    void startZAxisCClockAnim();

    Cuboid *cuboid() const;

private:
    Cuboid *m_cuboid;
};
#endif // CUBIE_H
