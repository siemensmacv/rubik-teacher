#ifndef XORBITTRANSFORMCONTROLLER_H
#define XORBITTRANSFORMCONTROLLER_H

#include "./View3DHeaders/orbittransformcontroller.h"

class XOrbitTransformController : public OrbitTransformController
{
public:
    XOrbitTransformController(QObject *parent = 0);

    void updateAngle() override;

protected:
    void updateMatrix() override;
    QMatrix4x4 getCentreMatrix() override;


};

#endif // XORBITTRANSFORMCONTROLLER_H
