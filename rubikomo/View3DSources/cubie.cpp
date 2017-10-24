#include "./View3DHeaders/cubie.h"


Cubie::Cubie(Qt3DCore::QEntity *rootEntity,bool isCorner)
{
    m_cuboid=new Cuboid(rootEntity,isCorner);
    h=new AnimationHandler(m_cuboid);
}

void Cubie::UpC()
{
    h->UpC();
}


Qt3DCore::QEntity *Cubie::entity()
{
    return m_cuboid->entity();
}

Qt3DCore::QTransform *Cubie::transf()
{
    return m_cuboid->shapeTransform();
}

Cuboid *Cubie::cuboid() const
{
    return m_cuboid;
}
