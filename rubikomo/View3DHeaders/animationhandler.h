#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include "orbittransformcontroller.h"
#include "./View3DHeaders/xorbittransformcontroller.h"
#include "./View3DHeaders/yorbittransformcontroller.h"
#include "./View3DHeaders/zorbittransformcontroller.h"

#include <Qt3DCore>

class AnimationHandler
{
public:
    explicit AnimationHandler(Qt3DCore::QTransform *cuboidTranform);

    void startXAxisClockAnim();
    void startXAxisCClockAnim();
    void startYAxisClockAnim();
    void startYAxisCClockAnim();
    void startZAxisClockAnim();
    void startZAxisCClockAnim();

    XOrbitTransformController *XOrbitTransform() const;

    YOrbitTransformController *YOrbitTransform() const;

    ZOrbitTransformController *ZOrbitTransform() const;

private:
    QPropertyAnimation *XAnim;
    XOrbitTransformController *m_XOrbitTransform;

    QPropertyAnimation *YAnim;
    YOrbitTransformController *m_YOrbitTransform;

    QPropertyAnimation *ZAnim;
    ZOrbitTransformController *m_ZOrbitTransform;
};

#endif // ANIMATIONHANDLER_H
