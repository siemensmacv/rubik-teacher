#ifndef CUBE3D_H
#define CUBE3D_H

#include "./View3DHeaders/icubie.h"
#include "./View3DHeaders/cubiefactory.h"
#include "modelrubik.h"
#include "./View3DHeaders/matrixswap.h"
#include <Qt3DCore>
#include "rubikfaceutils.h"
#include <Qt3DExtras>

class Cube3D {
public:
    Cube3D(ModelRubik *model3D, Qt3DCore::QEntity *rootEntity);
    void UpC();
    void UpCC();
    void DownC();
    void DownCC();
    void FrontC();
    void FrontCC();
    void BackC();
    void BackCC();
    void RightC();
    void RightCC();
    void LeftC();
    void LeftCC();

    void updateColors(ModelRubik* model3D);
    void resetColors();
    ~Cube3D();

private:
    void initCorners(ModelRubik *model3D);
    void initEdges(ModelRubik* model3D);
    void initCentres(ModelRubik *model3D);

    ICubie*** m_frontFace;
    ICubie*** m_backFace;
    ICubie*** m_upFace;
    ICubie*** m_downFace;
    ICubie*** m_rightFace;
    ICubie*** m_leftFace;

    Qt3DCore::QEntity *root;
    MatrixSwap *m_swaper;
    CubieFactory *m_cubieFactory;

};
#endif // CUBE3D_H
