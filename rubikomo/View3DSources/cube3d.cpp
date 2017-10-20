#include "./View3DHeaders/cube3d.h"

Cube3D::Cube3D(ModelRubik_CornersEdges *model3D, Qt3DCore::QEntity *rootEntity)
{
    m_frontFace.resize(9);
    m_backFace.resize(9);
    m_upFace.resize(9);
    m_downFace.resize(9);
    m_rightFace.resize(9);
    m_leftFace.resize(9);

    m_cubieFactory = new CubieFactory(rootEntity);

    m_upFace[2]=m_rightFace[2]=m_backFace[0]=
            m_cubieFactory->getCornerCubie(0,
                                           model3D->getCorner(Corner::UBR),
                                           model3D->getCornerOrientation(Corner::UBR));

    m_upFace[8]=m_frontFace[2]=m_rightFace[0]=
            m_cubieFactory->getCornerCubie(1,
                                           model3D->getCorner(Corner::URF),
                                           model3D->getCornerOrientation(Corner::URF));


}
