#ifndef YORBITTRANSFORMCONTROLLER_H
#define YORBITTRANSFORMCONTROLLER_H

#include "./View3DHeaders/orbittransformcontroller.h"

class YOrbitTransformController : public OrbitTransformController
{
public:
    YOrbitTransformController(QObject *parent ,bool isCorner);

    void updateAngle() override;

protected:
    void updateMatrix() override;
    QMatrix4x4 getCentreMatrix() override;

};

#endif // YORBITTRANSFORMCONTROLLER_H
