#ifndef XORBITTRANSFORMCONTROLLER_H
#define XORBITTRANSFORMCONTROLLER_H

#include "./View3DHeaders/orbittransformcontroller.h"

class XOrbitTransformController : public OrbitTransformController
{
public:
    XOrbitTransformController(QObject *parent ,bool isCorner);

    void updateAngle() override;

protected:
    void updateMatrix() override;
    QMatrix4x4 getCentreMatrix() override;

private:
    float m_xRotationAngle;

};

#endif // XORBITTRANSFORMCONTROLLER_H
