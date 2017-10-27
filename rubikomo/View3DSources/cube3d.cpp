#include "./View3DHeaders/cube3d.h"
#include <Qt3DExtras>

Cube3D::Cube3D(ModelRubik *model3D, Qt3DCore::QEntity *rootEntity)
{
    auto alocmatr=[](){
        ICubie*** matr=new ICubie**[3];
        for(int i=0;i<3;i++)
            matr[i]=new ICubie*[3];
        return matr;
    };
    root=rootEntity;

    m_upFace=alocmatr();
    m_downFace=alocmatr();
    m_frontFace=alocmatr();
    m_backFace=alocmatr();
    m_leftFace=alocmatr();
    m_rightFace=alocmatr();

    m_cubieFactory = new CubieFactory(rootEntity);

    m_swaper = new MatrixSwap(m_frontFace,m_backFace,m_upFace,m_downFace,m_leftFace,m_rightFace);

    initCorners(model3D);
    initEdges(model3D);
    initCentres(model3D);

    updateColors(model3D);

}

void Cube3D::updateColors(ModelRubik *model3D)
{
    //UPDATE COLORS ( 3 culori ) / 2 edges / 1 centre

    // Up face
    m_upFace[0][0]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Up, 0, 0)),
                                 RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Back, 0, 2)),
                                 RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Left, 0, 0)));
    m_upFace[0][1]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Up, 0, 1)),
                                 RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Back, 0, 1)));
    m_upFace[0][2]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Up, 0, 2)),
                                 RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Back, 0, 0)),
                                 RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Right, 0, 2)));

    m_upFace[1][0]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Up, 1, 0)),
                                 RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Left, 0, 1)));
    m_upFace[1][1]->updateColors(RubikFaceUtils::colorEnumToQColor(model3D->getCenter(RubikFace::Up)));
    m_upFace[1][2]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Up, 1, 2)),
                                 RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Right, 0, 1)));

    m_upFace[2][0]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Up, 2, 0)),
                                 RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Front, 0, 0)),
                                 RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Left, 0, 2)));
    m_upFace[2][1]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Up, 2, 1)),
                                 RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Front, 0, 1)));
    m_upFace[2][2]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Up, 2, 2)),
                                 RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Front, 0, 2)),
                                 RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Right, 0, 0)));

    // Down face
    m_downFace[0][0]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Down, 0, 0)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Front, 2, 0)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Left, 2, 2)));
    m_downFace[0][1]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Down, 0, 1)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Front, 2, 1)));
    m_downFace[0][2]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Down, 0, 2)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Front, 2, 2)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Right, 2, 0)));

    m_downFace[1][0]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Down, 1, 0)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Left, 2, 1)));
    m_downFace[1][1]->updateColors(RubikFaceUtils::colorEnumToQColor(model3D->getCenter(RubikFace::Down)));
    m_downFace[1][2]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Down, 1, 2)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Right, 2, 1)));

    m_downFace[2][0]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Down, 2, 0)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Back, 2, 2)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Left, 2, 0)));
    m_downFace[2][1]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Down, 2, 1)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Back, 2, 1)));
    m_downFace[2][2]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Down, 2, 2)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Back, 2, 0)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Right, 2, 2)));

    // Front face
    m_frontFace[1][0]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Left, 1, 2)),
                                    RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Front, 1, 0)));
    m_frontFace[1][1]->updateColors(RubikFaceUtils::colorEnumToQColor(model3D->getCenter(RubikFace::Front)));
    m_frontFace[1][2]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Right, 1, 0)),
                                    RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Front, 1, 2)));

    // Back face
    m_backFace[1][0]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Right, 1, 2)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Back, 1, 0)));
    m_backFace[1][1]->updateColors(RubikFaceUtils::colorEnumToQColor(model3D->getCenter(RubikFace::Back)));
    m_backFace[1][2]->updateColors(RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Left, 1, 0)),
                                   RubikFaceUtils::colorDigitToQColor(model3D->getMatrixValue(RubikFace::Back, 1, 2)));

    m_leftFace[1][1]->updateColors(RubikFaceUtils::colorEnumToQColor(model3D->getCenter(RubikFace::Left)));
    m_rightFace[1][1]->updateColors(RubikFaceUtils::colorEnumToQColor(model3D->getCenter(RubikFace::Right)));
}

void Cube3D::resetColors()
{
    //UPDATE COLORS ( 3 culori ) / 2 edges / 1 centre
    // 0 = galben, 1= orange, 2= verde, 3=alb, 4=rosu, 5=albastru
    // Up face

    m_upFace[0][0]->updateColors(RubikFaceUtils::colorDigitToQColor(0),
                                 RubikFaceUtils::colorDigitToQColor(5),
                                 RubikFaceUtils::colorDigitToQColor(4));
    m_upFace[0][1]->updateColors(RubikFaceUtils::colorDigitToQColor(0),
                                 RubikFaceUtils::colorDigitToQColor(5));
    m_upFace[0][2]->updateColors(RubikFaceUtils::colorDigitToQColor(0),
                                 RubikFaceUtils::colorDigitToQColor(5),
                                 RubikFaceUtils::colorDigitToQColor(1));

    m_upFace[1][0]->updateColors(RubikFaceUtils::colorDigitToQColor(0),
                                 RubikFaceUtils::colorDigitToQColor(4));
    m_upFace[1][1]->updateColors(RubikFaceUtils::colorEnumToQColor(RubikFace::Up));
    m_upFace[1][2]->updateColors(RubikFaceUtils::colorDigitToQColor(0),
                                 RubikFaceUtils::colorDigitToQColor(1));

    m_upFace[2][0]->updateColors(RubikFaceUtils::colorDigitToQColor(0),
                                 RubikFaceUtils::colorDigitToQColor(2),
                                 RubikFaceUtils::colorDigitToQColor(4));
    m_upFace[2][1]->updateColors(RubikFaceUtils::colorDigitToQColor(0),
                                 RubikFaceUtils::colorDigitToQColor(2));
    m_upFace[2][2]->updateColors(RubikFaceUtils::colorDigitToQColor(0),
                                 RubikFaceUtils::colorDigitToQColor(2),
                                 RubikFaceUtils::colorDigitToQColor(1));

    // Down face
    m_downFace[0][0]->updateColors(RubikFaceUtils::colorDigitToQColor(3),
                                   RubikFaceUtils::colorDigitToQColor(2),
                                   RubikFaceUtils::colorDigitToQColor(4));
    m_downFace[0][1]->updateColors(RubikFaceUtils::colorDigitToQColor(3),
                                   RubikFaceUtils::colorDigitToQColor(2));
    m_downFace[0][2]->updateColors(RubikFaceUtils::colorDigitToQColor(3),
                                   RubikFaceUtils::colorDigitToQColor(2),
                                   RubikFaceUtils::colorDigitToQColor(1));

    m_downFace[1][0]->updateColors(RubikFaceUtils::colorDigitToQColor(3),
                                   RubikFaceUtils::colorDigitToQColor(4));
    m_downFace[1][1]->updateColors(RubikFaceUtils::colorEnumToQColor(RubikFace::Down));
    m_downFace[1][2]->updateColors(RubikFaceUtils::colorDigitToQColor(3),
                                   RubikFaceUtils::colorDigitToQColor(1));

    m_downFace[2][0]->updateColors(RubikFaceUtils::colorDigitToQColor(3),
                                   RubikFaceUtils::colorDigitToQColor(5),
                                   RubikFaceUtils::colorDigitToQColor(4));
    m_downFace[2][1]->updateColors(RubikFaceUtils::colorDigitToQColor(3),
                                   RubikFaceUtils::colorDigitToQColor(5));
    m_downFace[2][2]->updateColors(RubikFaceUtils::colorDigitToQColor(3),
                                   RubikFaceUtils::colorDigitToQColor(5),
                                   RubikFaceUtils::colorDigitToQColor(1));

    // Front face
    m_frontFace[1][0]->updateColors(RubikFaceUtils::colorDigitToQColor(4),
                                    RubikFaceUtils::colorDigitToQColor(2));
    m_frontFace[1][1]->updateColors(RubikFaceUtils::colorEnumToQColor(RubikFace::Front));
    m_frontFace[1][2]->updateColors(RubikFaceUtils::colorDigitToQColor(1),
                                    RubikFaceUtils::colorDigitToQColor(2));

    // Back face
    m_backFace[1][0]->updateColors(RubikFaceUtils::colorDigitToQColor(1),
                                   RubikFaceUtils::colorDigitToQColor(5));
    m_backFace[1][1]->updateColors(RubikFaceUtils::colorEnumToQColor(RubikFace::Back));
    m_backFace[1][2]->updateColors(RubikFaceUtils::colorDigitToQColor(4),
                                   RubikFaceUtils::colorDigitToQColor(5));

    m_leftFace[1][1]->updateColors(RubikFaceUtils::colorEnumToQColor(RubikFace::Left));
    m_rightFace[1][1]->updateColors(RubikFaceUtils::colorEnumToQColor(RubikFace::Right));
}

Cube3D::~Cube3D()
{
//    for(int i=0;i<9;i++)
//        for(int j=0;j<9;j++)
//        {
//            delete m_upFace[i][j];
//            delete m_downFace[i][j];
//        }

//    delete m_frontFace[1][0];
//    delete m_frontFace[1][1];
//    delete m_frontFace[1][2];

//    delete m_backFace[1][0];
//    delete m_backFace[1][1];
//    delete m_backFace[1][2];

//    delete m_leftFace[1][1];
//    delete m_rightFace[1][1];

}

void Cube3D::initCorners(ModelRubik *model3D)
{
    m_upFace[0][2]=m_rightFace[0][2]=m_backFace[0][0]=
            m_cubieFactory->getCornerCubie(0,
                                           model3D->getCorner(Corner::UBR),
                                           model3D->getCornerOrientation(Corner::UBR));

    //m_upFace[0][2]->updateColors(model3D->getCorner(Corner::UBR),model3D->getCornerOrientation(Corner::UBR));
    // corner = cubieF get
    //corner update


    m_upFace[2][2]=m_frontFace[0][2]=m_rightFace[0][0]=
            m_cubieFactory->getCornerCubie(1,
                                           model3D->getCorner(Corner::URF),
                                           model3D->getCornerOrientation(Corner::URF));

    m_upFace[2][0]=m_frontFace[0][0]=m_leftFace[0][2]=
            m_cubieFactory->getCornerCubie(2,
                                           model3D->getCorner(Corner::UFL),
                                           model3D->getCornerOrientation(Corner::UFL));

    m_upFace[0][0]=m_backFace[0][2]=m_leftFace[0][0]=
            m_cubieFactory->getCornerCubie(3,
                                           model3D->getCorner(Corner::ULB),
                                           model3D->getCornerOrientation(Corner::ULB));

    m_downFace[2][2]=m_rightFace[2][2]=m_backFace[2][0]=
            m_cubieFactory->getCornerCubie(4,
                                           model3D->getCorner(Corner::DRB),
                                           model3D->getCornerOrientation(Corner::DRB));

    m_downFace[0][2]=m_rightFace[2][0]=m_frontFace[2][2]=
            m_cubieFactory->getCornerCubie(5,
                                           model3D->getCorner(Corner::DFR),
                                           model3D->getCornerOrientation(Corner::DFR));

    m_downFace[0][0]=m_leftFace[2][2]=m_frontFace[2][0]=
            m_cubieFactory->getCornerCubie(6,
                                           model3D->getCorner(Corner::DLF),
                                           model3D->getCornerOrientation(Corner::DLF));

    m_downFace[2][0]=m_leftFace[2][0]=m_backFace[2][2]=
            m_cubieFactory->getCornerCubie(7,
                                           model3D->getCorner(Corner::DBL),
                                           model3D->getCornerOrientation(Corner::DBL));

}

void Cube3D::initEdges(ModelRubik *model3D)
{
    m_upFace[0][1]=m_backFace[0][1]=
            m_cubieFactory->getEdgeCubie(0,
                                         model3D->getEdge(Edge::UB),
                                         model3D->getEdgeOrientation(Edge::UB));

    m_upFace[1][2]=m_rightFace[0][1]=
            m_cubieFactory->getEdgeCubie(1,
                                         model3D->getEdge(Edge::UR),
                                         model3D->getEdgeOrientation(Edge::UR));

    m_upFace[2][1]=m_frontFace[0][1]=
            m_cubieFactory->getEdgeCubie(2,
                                         model3D->getEdge(Edge::UF),
                                         model3D->getEdgeOrientation(Edge::UF));

    m_upFace[1][0]=m_leftFace[0][1]=
            m_cubieFactory->getEdgeCubie(3,
                                         model3D->getEdge(Edge::UL),
                                         model3D->getEdgeOrientation(Edge::UL));

    m_rightFace[1][2]=m_backFace[1][0]=
            m_cubieFactory->getEdgeCubie(4,
                                         model3D->getEdge(Edge::BR),
                                         model3D->getEdgeOrientation(Edge::BR));

    m_frontFace[1][2]=m_rightFace[1][0]=
            m_cubieFactory->getEdgeCubie(5,
                                         model3D->getEdge(Edge::RF),
                                         model3D->getEdgeOrientation(Edge::RF));

    m_frontFace[1][0]=m_leftFace[1][2]=
            m_cubieFactory->getEdgeCubie(6,
                                         model3D->getEdge(Edge::FL),
                                         model3D->getEdgeOrientation(Edge::FL));

    m_leftFace[1][0]=m_backFace[1][2]=
            m_cubieFactory->getEdgeCubie(7,
                                         model3D->getEdge(Edge::LB),
                                         model3D->getEdgeOrientation(Edge::LB));

    m_downFace[2][1]=m_backFace[2][1]=
            m_cubieFactory->getEdgeCubie(8,
                                         model3D->getEdge(Edge::DB),
                                         model3D->getEdgeOrientation(Edge::DB));


    m_downFace[1][2]=m_rightFace[2][1]=
            m_cubieFactory->getEdgeCubie(9,
                                         model3D->getEdge(Edge::DR),
                                         model3D->getEdgeOrientation(Edge::DR));

    m_downFace[0][1]=m_frontFace[2][1]=
            m_cubieFactory->getEdgeCubie(10,
                                         model3D->getEdge(Edge::DF),
                                         model3D->getEdgeOrientation(Edge::DF));

    m_downFace[1][0]=m_leftFace[2][1]=
            m_cubieFactory->getEdgeCubie(11,
                                         model3D->getEdge(Edge::DL),
                                         model3D->getEdgeOrientation(Edge::DL));
}

void Cube3D::initCentres(ModelRubik *model3D)
{
    m_frontFace[1][1]=m_cubieFactory->getCentreCubie(0,model3D->getCenter(RubikFace::Front));
    m_backFace[1][1]=m_cubieFactory->getCentreCubie(1,model3D->getCenter(RubikFace::Back));
    m_leftFace[1][1]=m_cubieFactory->getCentreCubie(2,model3D->getCenter(RubikFace::Left));
    m_rightFace[1][1]=m_cubieFactory->getCentreCubie(3,model3D->getCenter(RubikFace::Right));
    m_upFace[1][1]=m_cubieFactory->getCentreCubie(4,model3D->getCenter(RubikFace::Up));
    m_downFace[1][1]=m_cubieFactory->getCentreCubie(5,model3D->getCenter(RubikFace::Down));
}

void Cube3D::UpC()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            m_upFace[i][j]->UpC();
        }
    m_swaper->upClock();
}

void Cube3D::UpCC()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            m_upFace[i][j]->UpCC();
        }
    m_swaper->upCounterClock();
}

void Cube3D::DownC()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m_downFace[i][j]->DownC();
    m_swaper->downClock();
}

void Cube3D::DownCC()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m_downFace[i][j]->DownCC();
    m_swaper->downCounterClock();
}

void Cube3D::FrontC()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m_frontFace[i][j]->FrontC();
    m_swaper->frontClock();
}

void Cube3D::FrontCC()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m_frontFace[i][j]->FrontCC();
    m_swaper->frontCounterClock();
}

void Cube3D::BackC()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m_backFace[i][j]->BackC();
    m_swaper->backClock();
}

void Cube3D::BackCC()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m_backFace[i][j]->BackCC();
    m_swaper->backCounterClock();
}

void Cube3D::RightC()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m_rightFace[i][j]->RightC();
    m_swaper->rightClock();
}

void Cube3D::RightCC()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m_rightFace[i][j]->RightCC();
    m_swaper->rightCounterClock();
}

void Cube3D::LeftC()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m_leftFace[i][j]->LeftC();
    m_swaper->leftClock();
}

void Cube3D::LeftCC()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m_leftFace[i][j]->LeftCC();
    m_swaper->leftCounterClock();
}


\
