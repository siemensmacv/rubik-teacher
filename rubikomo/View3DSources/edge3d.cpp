#include "View3DHeaders/edge3d.h"

Edge3D::Edge3D(Qt3DCore::QEntity *rootEntity):
    Cubie(rootEntity)
{

    //set plane radius
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

void Edge3D::updateColors(Edge edge, EdgeOrientation orient)
{
    QVector<QColor> vColors;
    switch(edge){
    case Edge::UB:
        vColors.push_back(QColor(255,255,0));
        vColors.push_back(QColor(0,0,255));
        break;
    case Edge::UR:
        vColors.push_back(QColor(255,255,0));
        vColors.push_back(QColor(255,130,0));
        break;
    case Edge::UF:
        vColors.push_back(QColor(255,255,0));
        vColors.push_back(QColor(0,255,0));
        break;
    case Edge::UL:
        vColors.push_back(QColor(255,255,0));
        vColors.push_back(QColor(255,0,0));
        break;
    case Edge::FL:
        vColors.push_back(QColor(255,0,0));
        vColors.push_back(QColor(0,255,0));
        break;
    case Edge::RF:
        vColors.push_back(QColor(255,130,0));
        vColors.push_back(QColor(0,255,0));
        break;
    case Edge::BR:
        vColors.push_back(QColor(255,130,0));
        vColors.push_back(QColor(0,0,255));
        break;
    case Edge::LB:
        vColors.push_back(QColor(255,0,0));
        vColors.push_back(QColor(0,0,255));
        break;
    case Edge::DB:
        vColors.push_back(QColor(255,255,255));
        vColors.push_back(QColor(0,0,255));
        break;
    case Edge::DR:
        vColors.push_back(QColor(255,255,255));
        vColors.push_back(QColor(255,130,0));
        break;
    case Edge::DF:
        vColors.push_back(QColor(255,255,255));
        vColors.push_back(QColor(0,255,0));
        break;
    case Edge::DL:
        vColors.push_back(QColor(255,255,255));
        vColors.push_back(QColor(255,0,0));
        break;
    };
    if(orient == EdgeOrientation::Normal)
    {
        m_plane->setColor(vColors[0]);
        m_plane2->setColor(vColors[1]);
    }
    else
    {
        m_plane->setColor(vColors[1]);
        m_plane2->setColor(vColors[0]);
    }

}
