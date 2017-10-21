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

    initCorners(model3D);
    initEdges(model3D);
    initCentres(model3D);

}

void Cube3D::test()
{
    m_frontFace[8]->startZAxisClockAnim();
}

void Cube3D::initCorners(ModelRubik_CornersEdges *model3D)
{
    m_upFace[2]=m_rightFace[2]=m_backFace[0]=
            m_cubieFactory->getCornerCubie(0,
                                           model3D->getCorner(Corner::UBR),
                                           model3D->getCornerOrientation(Corner::UBR));

    m_upFace[8]=m_frontFace[2]=m_rightFace[0]=
            m_cubieFactory->getCornerCubie(1,
                                           model3D->getCorner(Corner::URF),
                                           model3D->getCornerOrientation(Corner::URF));

    m_upFace[6]=m_frontFace[0]=m_leftFace[2]=
            m_cubieFactory->getCornerCubie(2,
                                           model3D->getCorner(Corner::UFL),
                                           model3D->getCornerOrientation(Corner::UFL));

    m_upFace[0]=m_backFace[2]=m_leftFace[0]=
            m_cubieFactory->getCornerCubie(3,
                                           model3D->getCorner(Corner::ULB),
                                           model3D->getCornerOrientation(Corner::ULB));

    m_downFace[8]=m_rightFace[8]=m_backFace[6]=
            m_cubieFactory->getCornerCubie(4,
                                           model3D->getCorner(Corner::DRB),
                                           model3D->getCornerOrientation(Corner::DRB));

    m_downFace[2]=m_rightFace[6]=m_frontFace[8]=
            m_cubieFactory->getCornerCubie(5,
                                           model3D->getCorner(Corner::DFR),
                                           model3D->getCornerOrientation(Corner::DFR));

    m_downFace[0]=m_leftFace[8]=m_frontFace[6]=
            m_cubieFactory->getCornerCubie(6,
                                           model3D->getCorner(Corner::DLF),
                                           model3D->getCornerOrientation(Corner::DLF));

    m_downFace[6]=m_leftFace[6]=m_backFace[8]=
            m_cubieFactory->getCornerCubie(7,
                                           model3D->getCorner(Corner::DBL),
                                           model3D->getCornerOrientation(Corner::DBL));
}

void Cube3D::initEdges(ModelRubik_CornersEdges *model3D)
{
    m_upFace[1]=m_backFace[1]=
            m_cubieFactory->getEdgeCubie(0,
                                         model3D->getEdge(Edge::UB),
                                         model3D->getEdgeOrientation(Edge::UB));

    m_upFace[5]=m_rightFace[1]=
            m_cubieFactory->getEdgeCubie(1,
                                         model3D->getEdge(Edge::UR),
                                         model3D->getEdgeOrientation(Edge::UR));

    m_upFace[7]=m_frontFace[1]=
            m_cubieFactory->getEdgeCubie(2,
                                         model3D->getEdge(Edge::UF),
                                         model3D->getEdgeOrientation(Edge::UF));

    m_upFace[3]=m_leftFace[1]=
            m_cubieFactory->getEdgeCubie(3,
                                         model3D->getEdge(Edge::UL),
                                         model3D->getEdgeOrientation(Edge::UL));


    m_rightFace[5]=m_backFace[3]=
            m_cubieFactory->getEdgeCubie(4,
                                         model3D->getEdge(Edge::BR),
                                         model3D->getEdgeOrientation(Edge::BR));

    m_frontFace[5]=m_rightFace[3]=
            m_cubieFactory->getEdgeCubie(5,
                                         model3D->getEdge(Edge::RF),
                                         model3D->getEdgeOrientation(Edge::RF));

    m_frontFace[3]=m_leftFace[5]=
            m_cubieFactory->getEdgeCubie(6,
                                         model3D->getEdge(Edge::FL),
                                         model3D->getEdgeOrientation(Edge::FL));

    m_leftFace[3]=m_backFace[5]=
            m_cubieFactory->getEdgeCubie(7,
                                         model3D->getEdge(Edge::LB),
                                         model3D->getEdgeOrientation(Edge::LB));

    m_downFace[7]=m_backFace[7]=
            m_cubieFactory->getEdgeCubie(8,
                                         model3D->getEdge(Edge::DB),
                                         model3D->getEdgeOrientation(Edge::DB));


    m_downFace[5]=m_rightFace[7]=
            m_cubieFactory->getEdgeCubie(9,
                                         model3D->getEdge(Edge::DR),
                                         model3D->getEdgeOrientation(Edge::DR));

    m_downFace[1]=m_frontFace[7]=
            m_cubieFactory->getEdgeCubie(10,
                                         model3D->getEdge(Edge::DF),
                                         model3D->getEdgeOrientation(Edge::DF));

    m_downFace[3]=m_leftFace[7]=
            m_cubieFactory->getEdgeCubie(11,
                                         model3D->getEdge(Edge::DL),
                                         model3D->getEdgeOrientation(Edge::DL));
}

void Cube3D::initCentres(ModelRubik_CornersEdges *model3D)
{
    m_frontFace[4]=m_cubieFactory->getCentreCubie(0,model3D->getCenter(RubikFace::Front));
    m_backFace[4]=m_cubieFactory->getCentreCubie(1,model3D->getCenter(RubikFace::Back));
    m_leftFace[4]=m_cubieFactory->getCentreCubie(2,model3D->getCenter(RubikFace::Left));
    m_rightFace[4]=m_cubieFactory->getCentreCubie(3,model3D->getCenter(RubikFace::Right));
    m_upFace[4]=m_cubieFactory->getCentreCubie(4,model3D->getCenter(RubikFace::Up));
    m_downFace[4]=m_cubieFactory->getCentreCubie(5,model3D->getCenter(RubikFace::Down));
}
