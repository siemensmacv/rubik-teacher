#ifndef CUBE3D_H
#define CUBE3D_H

#include "./View3DHeaders/icubie.h"
#include "./View3DHeaders/cubiefactory.h"

#include "modelrubik_cornersedges.h"
#include "./View3DHeaders/matrixswap.h"

#include <Qt3DCore>

class Cube3D {
public:
    Cube3D(ModelRubik_CornersEdges *model3D, Qt3DCore::QEntity *rootEntity);
    void UpC();
    void RC();
    //Rotations
private:
    void initCorners(ModelRubik_CornersEdges* model3D);
    void initEdges(ModelRubik_CornersEdges* model3D);
    void initCentres(ModelRubik_CornersEdges* model3D);

    ICubie*** m_frontFace;
    ICubie*** m_backFace;
    ICubie*** m_upFace;
    ICubie*** m_downFace;
    ICubie*** m_rightFace;
    ICubie*** m_leftFace;

    MatrixSwap *m_swaper;
    CubieFactory *m_cubieFactory;

};
#endif // CUBE3D_H
