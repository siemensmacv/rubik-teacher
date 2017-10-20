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
    OrbitTransformController *m_orbitTransform;

    QPropertyAnimation *XAnim;
    QPropertyAnimation *YAnim;
    QPropertyAnimation *ZAnim;
};

#endif // ANIMATIONHANDLER_H
