#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include "./View3DHeaders/cuboid.h"
#include <iostream>

#include <utility>
#include <map>
#include "rubikface.h"

#include <Qt3DCore>

class AnimationHandler : public QObject
{
    Q_OBJECT
public:
    AnimationHandler(Cuboid *cuboid);

    void UpC();//
    void UpCC();
    void DownC();
    void DownCC();
    void FrontC();
    void FrontCC();
    void BackC();
    void BackCC();
    void RightC();//
    void RightCC();
    void LeftC();
    void LeftCC();

private:
    Qt3DCore::QTransform *transform;

    int count = 0;
    QTimer *timer;

    Cuboid* m_cube;
    QMatrix4x4 rotationMatrix;

    std::map <std::tuple<RubikFace, int, int, int>, int> m_edgeMap;
    std::map <std::tuple<RubikFace, int, int, int>, std::pair<int, int>> m_cornerMap;

    void insertInMap(RubikFace face, int x, int y, int z, int index);
    void initializeEdgeMap();

    void insertInMap(RubikFace face, int x, int y, int z, int index1, int index2);
    void initializeCornerMap();

    void updateRotationMatrix(RubikFace face,bool way);
    void swapAxis(int axis,bool way);
    void rotate();

};

#endif // ANIMATIONHANDLER_H
