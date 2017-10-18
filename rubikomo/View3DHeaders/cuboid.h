#ifndef CUBOID_H
#define CUBOID_H

#include "./View3DHeaders/shape3d.h"

class Cuboid : public Shape3D
{
public:
    Cuboid();
    void setCuboidMesh(Qt3DExtras::QCuboidMesh *cuboidMesh);
private:
    Qt3DExtras::QCuboidMesh *m_cuboidMesh;
};
#endif // CUBOID_H
