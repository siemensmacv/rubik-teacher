#include "./View3DHeaders/corner3d.h"

Corner3D::Corner3D(Qt3DCore::QEntity *rootEntity):
    Cubie(rootEntity)
{

}

void Corner3D::setUpPlanes()
{
    m_upDownPlane  = new Plane(m_cuboid->entity());
    m_frontBackPlane = new Plane(m_cuboid->entity());
    m_leftRightPlane = new Plane(m_cuboid->entity());

    if(m_cuboid->shapeTransform()->translation().x()>0){
        //right
        m_leftRightPlane->shapeTransform()->setRotationZ(-90);
        m_leftRightPlane->shapeTransform()->setTranslation(QVector3D(0.51f,0.0f,0.0f));

    }
    else{
        //left
        m_leftRightPlane->shapeTransform()->setRotationZ(90);
        m_leftRightPlane->shapeTransform()->setTranslation(QVector3D(-0.51f,0.0f,0.0f));

    }

    if(m_cuboid->shapeTransform()->translation().y()>0){
        //up
        m_upDownPlane->shapeTransform()->setTranslation(QVector3D(0.0f,0.51f,0.0f));

    }
    else{
        //down
        m_upDownPlane->shapeTransform()->setRotationZ(180);
        m_upDownPlane->shapeTransform()->setTranslation(QVector3D(0.0f,-0.51f,0.0f));

    }

    if(m_cuboid->shapeTransform()->translation().z()>0){
        //front
        m_frontBackPlane->shapeTransform()->setRotationX(90);
        m_frontBackPlane->shapeTransform()->setTranslation(QVector3D(0.0f,0.0f,0.51f));

    }
    else{
        //back
        m_frontBackPlane->shapeTransform()->setRotationX(-90);
        m_frontBackPlane->shapeTransform()->setTranslation(QVector3D(0.0f,0.0f,-0.51f));

    }

}

void Corner3D::updateColors(QColor upDownColor, QColor frontBackColor, QColor leftRightColor)
{
    //ud plane
    //fb plane
    //lr plane

    m_upDownPlane->setColor(upDownColor);
    m_frontBackPlane->setColor(frontBackColor);
    m_leftRightPlane->setColor(leftRightColor);

}
