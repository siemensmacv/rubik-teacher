#ifndef CORNER_H
#define CORNER_H

#include "./View3DHeaders/cubie.h"
#include "./View3DHeaders/plane.h"

class Corner3D : public Cubie
{
public:
    explicit Corner3D(Qt3DCore::QEntity *rootEntity);

    void setUpPlanes();

    void updateColors(QColor upDownColor, QColor frontBackColor, QColor leftRightColor);
    void updateColors(QColor, QColor){}
    void updateColors(QColor){}

private:
    Plane *m_upDownPlane;
    Plane *m_frontBackPlane;
    Plane *m_leftRightPlane;
};
#endif // CORNER_H
