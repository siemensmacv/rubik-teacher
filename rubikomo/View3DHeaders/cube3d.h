#ifndef CUBE3D_H
#define CUBE3D_H

#include "./View3DHeaders/icubie.h"
#include "modelrubik_cornersedges.h"

#include <Qt3DCore>

class Cube3D {
public:
    Cube3D();
    Cube3D(ModelRubik_CornersEdges *model3D, Qt3DCore::QEntity *rootEntity);
private:
    QVector<ICubie*> m_frontFace=new QVector(9);
    QVector<ICubie*> m_backFace=new QVector(9);
    QVector<ICubie*> m_upFace=new QVector(9);
    QVector<ICubie*> m_downFace=new QVector(9);
    QVector<ICubie*> m_rightFace=new QVector(9);
    QVector<ICubie*> m_leftFace=new QVector(9);
}

#endif // CUBE3D_H
