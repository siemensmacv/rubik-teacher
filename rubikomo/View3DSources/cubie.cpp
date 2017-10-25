#include "./View3DHeaders/cubie.h"


Cubie::Cubie(Qt3DCore::QEntity *rootEntity,bool isCorner)
{
    m_cuboid=new Cuboid(rootEntity,isCorner);
    animHandler=new AnimationHandler(m_cuboid);
}

void Cubie::UpC()
{
    animHandler->UpC();
}


Qt3DCore::QEntity *Cubie::entity()
{
    return m_cuboid->entity();
}

Qt3DCore::QTransform *Cubie::transf()
{
    return m_cuboid->shapeTransform();
}

void Cubie::setTranslation(QVector3D trans)
{
    m_cuboid->shapeTransform()->setTranslation(trans);
}

