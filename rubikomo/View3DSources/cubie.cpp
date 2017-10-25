#include "./View3DHeaders/cubie.h"


Cubie::Cubie(Qt3DCore::QEntity *rootEntity)
{
    m_cuboid=new Cuboid(rootEntity);
    animHandler=new AnimationHandler(m_cuboid);
}

void Cubie::UpC()
{
    animHandler->UpC();
}

void Cubie::UpCC()
{
    animHandler->UpCC();
}

void Cubie::DownC()
{
    animHandler->DownC();
}

void Cubie::DownCC()
{
    animHandler->DownCC();
}

void Cubie::FrontC()
{
    animHandler->FrontC();
}

void Cubie::FrontCC()
{
    animHandler->FrontCC();
}

void Cubie::BackC()
{
    animHandler->BackC();
}

void Cubie::BackCC()
{
    animHandler->BackCC();
}

void Cubie::RightC()
{
    animHandler->RightC();
}

void Cubie::RightCC()
{
    animHandler->RightCC();
}

void Cubie::LeftC()
{
    animHandler->LeftC();
}

void Cubie::LeftCC()
{
    animHandler->LeftCC();
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

