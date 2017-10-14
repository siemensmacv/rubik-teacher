#ifndef CUBOID_H
#define CUBOID_H

#include <Qt3DExtras>
#include <Qt3DCore>
#include <QPropertyAnimation>

class Cuboid
{
public:
    Cuboid(Qt3DCore::QEntity *);

    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_cuboidEntity;
    Qt3DExtras::QCuboidMesh *m_cuboidMesh;
    Qt3DCore::QTransform *m_cuboidTransform;
    Qt3DExtras::QPhongMaterial *m_cuboidMaterial;
    QPropertyAnimation *m_cubeAnim;


};

#endif // CUBOID_H
