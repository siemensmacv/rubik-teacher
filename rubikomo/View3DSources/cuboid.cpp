#include "./View3DHeaders/cuboid.h"

Cuboid::Cuboid()
{

}

void Cuboid::setCuboidMesh(Qt3DExtras::QCuboidMesh *cuboidMesh)
{
    m_cuboidMesh = cuboidMesh;
}
