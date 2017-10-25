#include "./View3DHeaders/animationhandler.h"

AnimationHandler::AnimationHandler(Cuboid *cuboid)
{
    m_cube=cuboid;
    initializeCornerMap();
    initializeEdgeMap();
}

void AnimationHandler::rotate()
{
    QMatrix4x4 m = transform->matrix();
    m = m * rotationMatrix;
    transform->setMatrix(m);
}

void AnimationHandler::updateRotationMatrix(RubikFace face,bool way){
    float x = round(transform->translation().x());
    float y = round(transform->translation().y());
    float z = round(transform->translation().z());

    QVector3D centrePoint;
    auto mapKey=std::make_tuple(face,x,y,z);
    if(abs(x)+abs(y)+abs(z) == 3){
        //pair(index,index2) = corner map
        auto indexPair=m_cornerMap[mapKey];
        centrePoint=m_cube->m_axisHandler->axis[indexPair.first] + m_cube->m_axisHandler->axis[indexPair.second];
    }
    if(abs(x)+abs(y)+abs(z) == 2){
        //index = edge map
        int index=m_edgeMap[mapKey];
        centrePoint=m_cube->m_axisHandler->axis[index];
    }
    if(abs(x)+abs(y)+abs(z) == 1){
        //index = centre map
        centrePoint=QVector3D(0.0f,0.0f,0.0f);
    }

    float angle=0.09f;
    int axis;

    if(way)
        angle=-0.09f;

    switch(face){
    case RubikFace::Up:
        axis=2;
        break;
    case RubikFace::Down:
        axis=3;
        break;
    case RubikFace::Right:
        axis=0;
        break;
    case RubikFace::Left:
        axis=1;
        break;
    case RubikFace::Front:
        axis=4;
        break;
    case RubikFace::Back:
        axis=5;
        break;
    };

    rotationMatrix = Qt3DCore::QTransform::rotateAround(
            centrePoint,
            angle,
            m_cube->m_axisHandler->axis[axis]
            );

    swapAxis(axis,way);

    for (int i = 0; i < 100; ++i)
    {
        QTimer::singleShot(i*10, this, &AnimationHandler::rotate);
    }
}

void AnimationHandler::swapAxis(int axis,bool way){
    if(way)
    {
        if(axis == 0 )
            m_cube->m_axisHandler->xClock();
        if(axis == 1 )
            m_cube->m_axisHandler->xCounterClock();
        if(axis == 2)
            m_cube->m_axisHandler->yClock();
        if(axis == 3 )
            m_cube->m_axisHandler->yCounterClock();
        if(axis == 4 )
            m_cube->m_axisHandler->zClock();
        if(axis == 5 )
            m_cube->m_axisHandler->zCounterClock();
    }
    else
    {
        if(axis == 0 )
            m_cube->m_axisHandler->xCounterClock();
        if(axis == 1 )
            m_cube->m_axisHandler->xClock();
        if(axis == 2)
            m_cube->m_axisHandler->yCounterClock();
        if(axis == 3 )
            m_cube->m_axisHandler->yClock();
        if(axis == 4 )
            m_cube->m_axisHandler->zCounterClock();
        if(axis == 5 )
            m_cube->m_axisHandler->zClock();
    }
}
void AnimationHandler::UpC()// 1 functie
{
    updateRotationMatrix(RubikFace::Up,true);
}

void AnimationHandler::insertInMap(RubikFace face, int x, int y, int z, int index)
{
    std::tuple<RubikFace, int, int, int> keyTuple = std::make_tuple(face, x, y, z);
    m_edgeMap.emplace(std::make_pair(keyTuple, index));
}

void AnimationHandler::initializeEdgeMap()
{
    insertInMap(RubikFace::Up, 1, 1, 0, 1);
    insertInMap(RubikFace::Up, 0, 1, 1, 5);
    insertInMap(RubikFace::Up, -1, 1, 0, 0);
    insertInMap(RubikFace::Up, 0, 1, -1, 4);

    insertInMap(RubikFace::Front, 1, 0, 1, 1);
    insertInMap(RubikFace::Front, 0, -1, 1, 2);
    insertInMap(RubikFace::Front, -1, 0, 1, 0);
    insertInMap(RubikFace::Front, 0, 1, 1, 3);

    insertInMap(RubikFace::Right, 1, 0, -1, 4);
    insertInMap(RubikFace::Right, 1, -1, 0, 2);
    insertInMap(RubikFace::Right, 1, 0, 1, 5);
    insertInMap(RubikFace::Right, 1, 1, 0, 3);

    insertInMap(RubikFace::Left, -1, 0, 1, 5);
    insertInMap(RubikFace::Left, -1, -1, 0, 2);
    insertInMap(RubikFace::Left, -1, 0, -1, 4);
    insertInMap(RubikFace::Left, -1, 1, 0, 3);

    insertInMap(RubikFace::Down, 1, -1, 0, 1);
    insertInMap(RubikFace::Down, 0, -1, -1, 4);
    insertInMap(RubikFace::Down, -1, -1, 0, 0);
    insertInMap(RubikFace::Down, 0, -1, 1, 5);

    insertInMap(RubikFace::Back, -1, 0, -1, 0);
    insertInMap(RubikFace::Back, 0, -1, -1, 2);
    insertInMap(RubikFace::Back, 1, 0, -1, 1);
    insertInMap(RubikFace::Back, 0, 1, -1, 3);
}

void AnimationHandler::insertInMap(RubikFace face, int x, int y, int z, int index1, int index2)
{
    std::tuple<RubikFace, int, int, int> keyTuple = std::make_tuple(face, x, y, z);
    std::pair<int, int> valuePair = std::make_pair(index1, index2);
    m_cornerMap.emplace(std::make_pair(keyTuple, valuePair));
}

void AnimationHandler::initializeCornerMap()
{

     insertInMap(RubikFace::Up, 1, 1, -1, 1, 4);
     insertInMap(RubikFace::Up, 1, 1, 1, 1, 5);
     insertInMap(RubikFace::Up, -1, 1, 1, 0, 5);
     insertInMap(RubikFace::Up, -1, 1, -1, 0, 4);

     insertInMap(RubikFace::Front, 1, 1, 1, 1, 3);
     insertInMap(RubikFace::Front, 1, -1, 1, 1, 2);
     insertInMap(RubikFace::Front, -1, -1, 1, 0, 2);
     insertInMap(RubikFace::Front, -1, 1, 1, 0, 3);

     insertInMap(RubikFace::Right, 1, 1, -1, 3, 4);
     insertInMap(RubikFace::Right, 1, -1, -1, 2, 4);
     insertInMap(RubikFace::Right, 1, -1, 1, 2, 5);
     insertInMap(RubikFace::Right, 1, 1, 1, 3, 5);

     insertInMap(RubikFace::Left, -1, 1, 1, 3, 5);
     insertInMap(RubikFace::Left, -1, -1, 1, 2, 5);
     insertInMap(RubikFace::Left, -1, -1, -1, 2, 4);
     insertInMap(RubikFace::Left, -1, 1, -1, 3, 4);

     insertInMap(RubikFace::Down, 1, -1, 1, 1, 5);
     insertInMap(RubikFace::Down, 1, -1, -1, 1, 4);
     insertInMap(RubikFace::Down, -1, -1, -1, 0, 4);
     insertInMap(RubikFace::Down, -1, -1, 1, 0, 5);

     insertInMap(RubikFace::Back, -1, 1, -1, 0, 3);
     insertInMap(RubikFace::Back, -1, -1, -1, 0, 2);
     insertInMap(RubikFace::Back, 1, -1, -1, 1, 2);
     insertInMap(RubikFace::Back, 1, 1, -1, 1, 3);

}


