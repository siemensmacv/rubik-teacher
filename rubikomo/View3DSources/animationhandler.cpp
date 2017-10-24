#include "./View3DHeaders/animationhandler.h"

AnimationHandler::AnimationHandler(Cuboid *cuboid)
{
    m_cube=cuboid;
}

void AnimationHandler::rotate()
{
    QMatrix4x4 m = transform->matrix();
    m = m * rotationMatrix;
    transform->setMatrix(m);
}

void AnimationHandler::UpC()// 1 functie
{
    float x = round(transform->translation().x());
    float y = round(transform->translation().y());
    float z = round(transform->translation().z());

    int index=0;

//    if(x<=0.1 && z>=0.9)
//        index=5;
//    if(x<=0.1 && z<=-0.9)
//        index=4;
//    if(x<=-0.9 && z<=0.1)
//        index =0;
//    if(x>=0.9 && z<=0.1)
//        index=1;

    if(abs(x)+abs(y)+abs(z) == 3)
        //pair(index,index2) = corner map
    if(abs(x)+abs(y)+abs(z) == 2)
        //index = edge map
    if(abs(x)+abs(y)+abs(z) == 1)
        //index = centre map

    rotationMatrix = Qt3DCore::QTransform::rotateAround(
                m_cube->relativeAxis->axis[index],
                -0.09,
                m_cube->m_axisHandler->axis[2]
                );

    m_cube->m_axisHandler->yClock();

    for (int i = 0; i < 1000; ++i)
    {
        QTimer::singleShot(i, this, &RotatingEventHandler::rotate);
    }
}


