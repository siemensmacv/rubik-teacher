#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include "orbittransformcontroller.h"

#include <Qt3DCore>

class AnimationHandler
{
public:
    AnimationHandler();
    explicit AnimationHandler(Qt3DCore::QTransform *cuboidTranform);

    void startXAxisClockAnim();
    void startXAxisCClockAnim();
    void startYAxisClockAnim();
    void startYAxisCClockAnim();
    void startZAxisClockAnim();
    void startZAxisCClockAnim();

private:
    Qt3DCore::QTransform *m_cuboidTransform;
    OrbitTransformController *m_orbitTransform;
};

#endif // ANIMATIONHANDLER_H
