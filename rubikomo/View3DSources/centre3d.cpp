#include "View3DHeaders/centre3d.h"

Centre3D::Centre3D(Qt3DCore::QEntity *rootEntity):
    Cubie(rootEntity)
{

}

void Centre3D::setUpPlanes()
{
    m_plane = new Plane(m_cuboid->entity());
    float x= round(m_cuboid->shapeTransform()->translation().x());
    float y= round(m_cuboid->shapeTransform()->translation().y());
    float z= round(m_cuboid->shapeTransform()->translation().z());

    if(x==1.0f)
    {
        m_plane->shapeTransform()->setRotationZ(-90);
        m_plane->shapeTransform()->setTranslation(QVector3D(0.51f,0.0f,0.0f));
        return;
    }
    if(x==-1.0f)
    {
        m_plane->shapeTransform()->setRotationZ(90);
        m_plane->shapeTransform()->setTranslation(QVector3D(-0.51f,0.0f,0.0f));
        return;
    }
    if(y==1.0f)
    {
        m_plane->shapeTransform()->setTranslation(QVector3D(0.0f,0.51f,0.0f));
        return;
    }
    if(y==-1.0f)
    {
        m_plane->shapeTransform()->setRotationZ(180);
        m_plane->shapeTransform()->setTranslation(QVector3D(0.0f,-0.51f,0.0f));
        return;
    }
    if(z==1.0f)
    {
        m_plane->shapeTransform()->setRotationX(90);
        m_plane->shapeTransform()->setTranslation(QVector3D(0.0f,0.0f,0.51f));
        return;
    }
    if(z==-1.0f)
    {
        m_plane->shapeTransform()->setRotationX(-90);
        m_plane->shapeTransform()->setTranslation(QVector3D(0.0f,0.0f,-0.51f));
        return;
    }
}

void Centre3D::updateColors(RubikFace centre)
{
    switch(centre){
    case RubikFace::Up:
        m_plane->setColor(QColor(255,255,0));
        break;
    case RubikFace::Down:
        m_plane->setColor(QColor(255,255,255));
        break;
    case RubikFace::Left:
        m_plane->setColor(QColor(255,0,0));
        break;
    case RubikFace::Right:
        m_plane->setColor(QColor(255,130,0));
        break;
    case RubikFace::Front:
        m_plane->setColor(QColor(0,255,0));
        break;
    case RubikFace::Back:
        m_plane->setColor(QColor(0,0,255));
        break;
    }
}
