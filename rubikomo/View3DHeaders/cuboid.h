#ifndef CUBOID_H
#define CUBOID_H

#include "./View3DHeaders/shape3d.h"
#include "./View3DHeaders/animationhandler.h"

class Cuboid : public Shape3D
{
public:
    Cuboid(Qt3DCore::QEntity *rootEntity);

    AnimationHandler *animHandler() const;
private:
    Qt3DExtras::QCuboidMesh *m_cuboidMesh;
    AnimationHandler *m_animHandler;
};
#endif // CUBOID_H
