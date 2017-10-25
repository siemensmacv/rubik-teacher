#ifndef EDGE_H
#define EDGE_H

#include "./View3DHeaders/cubie.h"
#include "./View3DHeaders/plane.h"

class Edge3D : public Cubie
{
public:
    Edge3D(Qt3DCore::QEntity *rootEntity);

    void setUpPlanes();
    void updateColors(QColor, QColor, QColor){}
    void updateColors(QColor plane1Color, QColor plane2Color);
    void updateColors(QColor){}

private:
    Plane *m_plane,*m_plane2;
};
#endif // EDGE_H
