#ifndef ZORBITTRANSFORMCONTROLLER_H
#define ZORBITTRANSFORMCONTROLLER_H

#include "./View3DHeaders/orbittransformcontroller.h"

class ZOrbitTransformController : public OrbitTransformController
{
public:
public:
    ZOrbitTransformController(QObject *parent ,bool isCorner);

    void updateAngle() override;
    //bool isCorner();
protected:
    void updateMatrix() override;
    QMatrix4x4 getCentreMatrix() override;

private:
    float m_zRotationAngle;
};
#endif // ZORBITTRANSFORMCONTROLLER_H
