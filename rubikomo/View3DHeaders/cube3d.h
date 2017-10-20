#ifndef CUBE3D_H
#define CUBE3D_H

#include "./View3DHeaders/icubie.h"
#include "./View3DHeaders/cubiefactory.h"

#include "modelrubik_cornersedges.h"

#include <Qt3DCore>

class Cube3D {
public:
    Cube3D();
    Cube3D(ModelRubik_CornersEdges *model3D, Qt3DCore::QEntity *rootEntity);
private:
    QVector<ICubie*> m_frontFace;
    QVector<ICubie*> m_backFace;
    QVector<ICubie*> m_upFace;
    QVector<ICubie*> m_downFace;
    QVector<ICubie*> m_rightFace;
    QVector<ICubie*> m_leftFace;
    CubieFactory *m_cf;

//{
//    for()
//        switch()

//    get urf
//    set 0 0 0

//    get urb

//}

};
#endif // CUBE3D_H
