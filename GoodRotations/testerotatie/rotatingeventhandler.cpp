#include "rotatingeventhandler.h"

/*Vector3D RotatingEventHandler::getCentreU(){

    int x = static_cast<int>(transform->translation().x());
    int y = static_cast<int>(transform->translation().y());
    int z = static_cast<int>(transform->translation().z());

    return QVector3D(-1.0f,0.0f,0.0f);
    qDebug() << x << y << z;
    qDebug() << transform->translation().x() << transform->translation().y() << transform->translation().z();

    // x -x  y -y  z -z
    // 0  1  2  3  4  5
    if ( y == 1 && x == 1 && z==0) //right edge
    {
        qDebug() << relativeAxis->axis[1];
        return relativeAxis->axis[1];
    }

    if ( y == 1 && x == 1 && z==1) //right front corner
    {
        qDebug() << relativeAxis->axis[1];
        qDebug() << relativeAxis->axis[5];
        return relativeAxis->axis[1]+relativeAxis->axis[5];
    }

    if ( y == 1 && z == 1 && x==0)//front edge
    {
        qDebug() << relativeAxis->axis[5];
        return relativeAxis->axis[5];
    }

    if ( y == 1 && x == -1 && z==1)// left front corner
    {
        qDebug() << relativeAxis->axis[0]+relativeAxis->axis[5];
        return relativeAxis->axis[0]+relativeAxis->axis[5];
    }

    if (y == 1 && x == -1 && z==0) // left edge
    {
        qDebug() << relativeAxis->axis[0];
        return relativeAxis->axis[0];
    }

    if ( y == 1 && x == -1 && z==-1) // left back corner
    {
        qDebug() << relativeAxis->axis[0]+relativeAxis->axis[4];
        return relativeAxis->axis[0]+relativeAxis->axis[4];
    }

    if (y == 1 && z == -1) // back edge
    {
        qDebug() << relativeAxis->axis[4];
        return relativeAxis->axis[4];
    }

    if ( y == 1 && x == 1 && z==1) // right back corner
    {
        qDebug() << relativeAxis->axis[1]+relativeAxis->axis[4];
        return relativeAxis->axis[1]+relativeAxis->axis[4];
    }

    return QVector3D(0.0f, 0.0f, 0.0f);
}*/


RotatingEventHandler::RotatingEventHandler(Cuboid *cube)
{


    transform=cube->m_cuboidTransform;
    m_cube=cube;

    timer= new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, &RotatingEventHandler::rotate);
}

void RotatingEventHandler::UC()
{

    float x = transform->translation().x();
    float y = transform->translation().y();
    float z = transform->translation().z();

     int index=0;

     if(x<=0.1 && z>=0.9)
         index=5;
     if(x<=0.1 && z<=-0.9)
         index=4;
     if(x<=-0.9 && z<=0.1)
         index =0;
     if(x>=0.9 && z<=0.1)
         index=1;


     rotationMatrix = Qt3DCore::QTransform::rotateAround(
                 m_cube->relativeAxis->axis[index],
                 -0.09,
                 m_cube->relativeAxis->axis[2]
                 );
     m_cube->relativeAxis->yClock();

     for (int i = 0; i < 1000; ++i)
     {
         QTimer::singleShot(i, this, &RotatingEventHandler::rotate);
     }



}

void RotatingEventHandler::UCC()
{
    float x = transform->translation().x();
    float y = transform->translation().y();
    float z = transform->translation().z();

     int index=0;

     if(x<=0.1 && z>=0.9)
         index=5;
     if(x<=0.1 && z<=-0.9)
         index=4;
     if(x<=-0.9 && z<=0.1)
         index =0;
     if(x>=0.9 && z<=0.1)
         index=1;


     rotationMatrix = Qt3DCore::QTransform::rotateAround(
                 m_cube->relativeAxis->axis[index],
                 0.09,
                 m_cube->relativeAxis->axis[2]
                 );
     m_cube->relativeAxis->yCounterClock();

     for (int i = 0; i < 1000; ++i)
     {
         QTimer::singleShot(i, this, &RotatingEventHandler::rotate);
     }

}


void RotatingEventHandler::RC()
{
//    connect(timer, &QTimer::timeout,
//            this, &RotatingEventHandler::rc);

   float x = transform->translation().x();
   float y = transform->translation().y();
   float z = transform->translation().z();

    int index=0;

    if(y<=0.1 && z>=0.9)
        index=5;
    if(y<=0.1 && z<=-0.9)
        index=4;
    if(y<=-0.9 && z<=0.1)
        index =2;
    if(y>=0.9 && z<=0.1)
        index=3;

   qDebug()<<transform->translation().y();
   qDebug()<<transform->translation().z();
    qDebug() << y<<z;
    rotationMatrix = Qt3DCore::QTransform::rotateAround(
                m_cube->relativeAxis->axis[index],
                -0.09,
                m_cube->relativeAxis->axis[0]
                );
    m_cube->relativeAxis->xClock();

    for (int i = 0; i < 1000; ++i)
    {
        QTimer::singleShot(i, this, &RotatingEventHandler::rotate);
    }
  qDebug() << y<<z;
    //timer->start(1);
}

void RotatingEventHandler::RCC()
{
    float x = transform->translation().x();
float y = transform->translation().y();
float z = transform->translation().z();

 int index=0;

 if(y<=0.1 && z>=0.9)
     index=5;
 if(y<=0.1 && z<=-0.9)
     index=4;
 if(y<=-0.9 && z<=0.1)
     index =2;
 if(y>=0.9 && z<=0.1)
     index=3;

qDebug()<<transform->translation().y();
qDebug()<<transform->translation().z();
 qDebug() << y<<z;
 rotationMatrix = Qt3DCore::QTransform::rotateAround(
             m_cube->relativeAxis->axis[index],
             0.09,
             m_cube->relativeAxis->axis[0]
             );
 m_cube->relativeAxis->xCounterClock();

 for (int i = 0; i < 1000; ++i)
 {
     QTimer::singleShot(i, this, &RotatingEventHandler::rotate);
 }
qDebug() << y<<z;
}

void RotatingEventHandler::FC()
{
    float x = transform->translation().x();
    float y = transform->translation().y();
    float z = transform->translation().z();

     int index=0;

     if(y<=0.1 && x>=0.9)
         index=1;
     if(y<=0.1 && x<=-0.9)
         index=0;
     if(y<=-0.9 && x<=0.1)
         index =2;
     if(y>=0.9 && x<=0.1)
         index=3;


     rotationMatrix = Qt3DCore::QTransform::rotateAround(
                 m_cube->relativeAxis->axis[index],
                 -0.09,
                 m_cube->relativeAxis->axis[4]
                 );
     m_cube->relativeAxis->zClock();

     for (int i = 0; i < 1000; ++i)
     {
         QTimer::singleShot(i, this, &RotatingEventHandler::rotate);
     }

}

void RotatingEventHandler::FCC()
{
    float x = transform->translation().x();
    float y = transform->translation().y();
    float z = transform->translation().z();

     int index=0;

     if(y<=0.1 && x>=0.9)
         index=1;
     if(y<=0.1 && x<=-0.9)
         index=0;
     if(y<=-0.9 && x<=0.1)
         index =2;
     if(y>=0.9 && x<=0.1)
         index=3;


     rotationMatrix = Qt3DCore::QTransform::rotateAround(
                 m_cube->relativeAxis->axis[index],
                 0.09,
                 m_cube->relativeAxis->axis[4]
                 );
     m_cube->relativeAxis->zCounterClock();

     for (int i = 0; i < 1000; ++i)
     {
         QTimer::singleShot(i, this, &RotatingEventHandler::rotate);
     }

}

void RotatingEventHandler::rotate()
{
    QMatrix4x4 m = transform->matrix();
    m = m * rotationMatrix;
    transform->setMatrix(m);
//    if (count > 1000)
//    {
//        count = 0;
//    }
//    else
//    {
//        ++count;
//        timer->start(1);

//    }
}

//void RotatingEventHandler::uc()
//{
//    QMatrix4x4 m = transform->matrix();
//    m = m * UpC;
//    transform->setMatrix(m);
//    if (count < 1000)
//    {
//        ++count;
//        timer->start(1);
//    }
//    else
//    {
//        count = 0;
//        disconnect(timer, &QTimer::timeout,
//                   this, &RotatingEventHandler::uc);
//    }
//}

//void RotatingEventHandler::ucc()
//{
//    QMatrix4x4 m = transform->matrix();
//    m = m * UpCC;
//    transform->setMatrix(m);
//    if (count < 1000)
//    {
//        ++count;
//        timer->start(1);
//    }
//    else
//    {
//        count = 0;
//        disconnect(timer, &QTimer::timeout,
//                   this, &RotatingEventHandler::ucc);
//    }
//}

//void RotatingEventHandler::rc()
//{
//    QMatrix4x4 m = transform->matrix();
//    m = m * RightC;
//    transform->setMatrix(m);
//    if (count < 1000)
//    {
//        ++count;
//        timer->start(1);
//    }
//    else
//    {
//        count = 0;
//        disconnect(timer, &QTimer::timeout,
//                   this, &RotatingEventHandler::rc);
//    }
//}

//void RotatingEventHandler::rcc()
//{
//    QMatrix4x4 m = transform->matrix();
//    m = m * RightCC;
//    transform->setMatrix(m);
//    if (count < 1000)
//    {
//        ++count;
//        timer->start(1);
//    }
//    else
//    {
//        count = 0;
//        disconnect(timer, &QTimer::timeout,
//                   this, &RotatingEventHandler::rcc);
//    }
//}

//void RotatingEventHandler::fc()
//{
//    QMatrix4x4 m = transform->matrix();
//    m = m * FrontC;
//    transform->setMatrix(m);
//    if (count < 1000)
//    {
//        ++count;
//        timer->start(1);
//    }
//    else
//    {
//        count = 0;
//        disconnect(timer, &QTimer::timeout,
//                   this, &RotatingEventHandler::fc);
//    }
//}

//void RotatingEventHandler::fcc()
//{
//    QMatrix4x4 m = transform->matrix();
//    m = m * FrontCC;
//    transform->setMatrix(m);
//    if (count < 1000)
//    {
//        ++count;
//        timer->start(1);
//    }
//    else
//    {
//        count = 0;
//        disconnect(timer, &QTimer::timeout,
//                   this, &RotatingEventHandler::fcc);
//    }
//}

//QVector3D RotatingEventHandler::getCenterPointRight()
//{
//    int x = static_cast<int>(transform->translation().x());
//    int y = static_cast<int>(transform->translation().y());
//    int z = static_cast<int>(transform->translation().z());

//    qDebug() << "before: " << x << y << z;

////    if (y == 1)
////        return QVector3D(0.0f, -1.5f, 0.0f);

////    if (z == 1)
////        return QVector3D(0.0f, 0.0f, -1.5f);


////    if (z == -1)
////        return QVector3D(0.0f, 1.5f, 0.0f);

////    if (y == -1)
////        return QVector3D(0.0f, 1.5f, 0.0f);
//    //return QVector3D(0.0f, -1.5f, 0.0f);
//    return QVector3D(0.0f, 0.0f, -1.0f); //  right front edge
//}

//QVector3D RotatingEventHandler::getCentrePointUp()
//{
////    int x = static_cast<int>(transform->translation().x());
////    int y = static_cast<int>(transform->translation().y());
////    int z = static_cast<int>(transform->translation().z());

////    if (y == 1  && z == -1 )
////        return QVector3D(0.0f, 0.0f, 1.1f);
////    if (y == 1 && x == 1)
////        return QVector3D(-1.1f, 0.0f, 0.0f);
////    if (y == 1  && z == 1 )
////        return QVector3D(0.0f, 0.0f, -1.1f);
////    if (y == 1  && x == -1 )
////        return QVector3D(1.1f, 0.0f, 0.0f);
////    return QVector3D(0.0f, 0.0f, 0.0f);

//   return centreVectorU;
//}

//QVector3D RotatingEventHandler::getCenterPointFront()
//{
//    return QVector3D(-1.0f,0.0f,0.0f);

//    int x = static_cast<int>(transform->translation().x());
//    int y = static_cast<int>(transform->translation().y());
//    int z = static_cast<int>(transform->translation().z());

//    qDebug() << x << y << z;
//    qDebug() << transform->translation().x() << transform->translation().y() << transform->translation().z();

//    if ( z == 1 && y == 1)
//    {
//        qDebug() << relativeAxis->axis[3];
//        return relativeAxis->axis[3];
//    }

//    if ( z == 1 && x == 1)
//    {
//        qDebug() << relativeAxis->axis[1];
//        return relativeAxis->axis[1];
//    }

//    if (z == 1 && y == -1)
//    {
//        qDebug() << relativeAxis->axis[2];
//        return relativeAxis->axis[2];
//    }

//    if (z == 1 && x == -1)
//    {
//        qDebug() << relativeAxis->axis[0];
//        return relativeAxis->axis[0];
//    }

//    return QVector3D(0.0f, 0.0f, 0.0f);
//}
