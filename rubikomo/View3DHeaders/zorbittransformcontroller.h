#ifndef ZORBITTRANSFORMCONTROLLER_H
#define ZORBITTRANSFORMCONTROLLER_H

#include "./View3DHeaders/orbittransformcontroller.h"

class ZOrbitTransformController : public OrbitTransformController
{
public:
public:
    ZOrbitTransformController(QObject *parent = 0);

    void updateAngle() override;

protected:
    void updateMatrix() override;
    QMatrix4x4 getCentreMatrix() override;

};
#endif // ZORBITTRANSFORMCONTROLLER_H
