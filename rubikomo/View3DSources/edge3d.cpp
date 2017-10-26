#include "View3DHeaders/edge3d.h"

Edge3D::Edge3D(Qt3DCore::QEntity *rootEntity):
    Cubie(rootEntity)
{

}

void Edge3D::setUpPlanes()
{
    m_plane  = new Plane(m_cuboid->entity());
    m_plane2 = new Plane(m_cuboid->entity());

    float x= round(m_cuboid->shapeTransform()->translation().x());
    float y= round(m_cuboid->shapeTransform()->translation().y());
    float z= round(m_cuboid->shapeTransform()->translation().z());

    if(x == 1.0f){ //right
        if(z==0.0f)
        {
            m_plane2->shapeTransform()->setRotationZ(-90);
            m_plane2->shapeTransform()->setTranslation(QVector3D(0.51f,0.0f,0.0f));
        }
        if(y==0.0f)
        {
            m_plane->shapeTransform()->setRotationZ(-90);
            m_plane->shapeTransform()->setTranslation(QVector3D(0.51f,0.0f,0.0f));
        }
    }
    if(x == -1.0f){//left
        if(z==0.0f)
        {
            m_plane2->shapeTransform()->setRotationZ(90);
            m_plane2->shapeTransform()->setTranslation(QVector3D(-0.51f,0.0f,0.0f));
        }
        if(y==0.0f)
        {
            m_plane->shapeTransform()->setRotationZ(90);
            m_plane->shapeTransform()->setTranslation(QVector3D(-0.51f,0.0f,0.0f));
        }
    }

    if(y==1.0f){ //up
        m_plane->shapeTransform()->setTranslation(QVector3D(0.0f,0.51f,0.0f));
    }
    if(y == -1.0f){
        //down
        m_plane->shapeTransform()->setRotationZ(180);
        m_plane->shapeTransform()->setTranslation(QVector3D(0.0f,-0.51f,0.0f));
    }

    if(z == 1.0f){
        //front
        m_plane2->shapeTransform()->setRotationX(90);
        m_plane2->shapeTransform()->setTranslation(QVector3D(0.0f,0.0f,0.51f));

    }
    if(z == -1.0f){
        m_plane2->shapeTransform()->setRotationX(-90);
        m_plane2->shapeTransform()->setTranslation(QVector3D(0.0f,0.0f,-0.51f));
    }
}

void Edge3D::updateColors(QColor plane1Color, QColor plane2Color)
{
    m_plane->setColor(plane1Color);
    m_plane2->setColor(plane2Color);

}
