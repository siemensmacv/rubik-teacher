#include "./View3DHeaders/corner3d.h"

Corner3D::Corner3D(Qt3DCore::QEntity *rootEntity):
    Cubie(rootEntity,isCorner)
{
    m_cuboid->m_isCorner=isCorner;

}

Plane *Corner3D::upDownPlane()
{
    return m_upDownPlane;
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

        //setColors(corner,orient);
       // m_leftRightPlane->setColor(255,130,0); // orange
    }
    else{
        //left
        m_leftRightPlane->shapeTransform()->setRotationZ(90);
        m_leftRightPlane->shapeTransform()->setTranslation(QVector3D(-0.51f,0.0f,0.0f));

        //m_leftRightPlane->setColor(255,0,0); // red
    }

    if(m_cuboid->shapeTransform()->translation().y()>0){
        //up
        m_upDownPlane->shapeTransform()->setTranslation(QVector3D(0.0f,0.51f,0.0f));

       // m_upDownPlane->setColor(255,255,0); // yellow
    }
    else{
        //down
        m_upDownPlane->shapeTransform()->setRotationZ(180);
        m_upDownPlane->shapeTransform()->setTranslation(QVector3D(0.0f,-0.51f,0.0f));

        //m_upDownPlane->setColor(220,200,220); // white
    }

    if(m_cuboid->shapeTransform()->translation().z()>0){
        //front
        m_frontBackPlane->shapeTransform()->setRotationX(90);
        m_frontBackPlane->shapeTransform()->setTranslation(QVector3D(0.0f,0.0f,0.51f));

        //m_frontBackPlane->setColor(0,255,0); // green
    }
    else{
        //back
        m_frontBackPlane->shapeTransform()->setRotationX(-90);
        m_frontBackPlane->shapeTransform()->setTranslation(QVector3D(0.0f,0.0f,-0.51f));

        //m_frontBackPlane->setColor(0,0,255); // blue
    }



}

void Corner3D::updateColors(Corner corner, CornerOrientation orient)
{
    QVector<QColor> vColors;
    switch(corner){
    case Corner::URF:
        vColors.push_back(QColor(255,255,0));
        vColors.push_back(QColor(0,255,0));
        vColors.push_back(QColor(255,130,0));
        break;

    case Corner::UFL:
        vColors.push_back(QColor(255,255,0));
        vColors.push_back(QColor(0,255,0));
        vColors.push_back(QColor(255,0,0));
        break;

    case Corner::ULB:
        vColors.push_back(QColor(255,255,0));
        vColors.push_back(QColor(0,0,255));
        vColors.push_back(QColor(255,0,0));
        break;

    case Corner::UBR:
        vColors.push_back(QColor(255,255,0));
        vColors.push_back(QColor(0,0,255));
        vColors.push_back(QColor(255,130,0));
        break;

    case Corner::DFR:
        vColors.push_back(QColor(255,255,255));
        vColors.push_back(QColor(0,255,0));
        vColors.push_back(QColor(255,130,0));
        break;

    case Corner::DLF:
        vColors.push_back(QColor(255,255,255));
        vColors.push_back(QColor(0,255,0));
        vColors.push_back(QColor(255,0,0));
        break;

    case Corner::DBL:
        vColors.push_back(QColor(255,255,255));
        vColors.push_back(QColor(0,0,255));
        vColors.push_back(QColor(255,0,0));
        break;

    case Corner::DRB:
        vColors.push_back(QColor(255,255,255));
        vColors.push_back(QColor(0,0,255));
        vColors.push_back(QColor(255,130,0));
        break;
    };


    if(orient == CornerOrientation::Normal){
        m_upDownPlane->setColor(vColors[0]);
        m_frontBackPlane->setColor(vColors[1]);
        m_leftRightPlane->setColor(vColors[2]);
        return;
    }

    if(orient == CornerOrientation::Clockwise)
    {
        m_upDownPlane->setColor(vColors[1]);
        m_frontBackPlane->setColor(vColors[2]);
        m_leftRightPlane->setColor(vColors[0]);
        return;
    }

    if(orient == CornerOrientation::CounterClockwise)
    {
        m_upDownPlane->setColor(vColors[2]);
        m_frontBackPlane->setColor(vColors[0]);
        m_leftRightPlane->setColor(vColors[1]);
        return;
    }
}
