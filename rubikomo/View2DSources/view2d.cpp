#include <View2DHeaders/view2d.h>

View2D::View2D(QWidget *parent, ModelRubik_Matrix *model2D) : QWidget(parent)
{
    m_model2D = model2D;
    gridLayout = new QGridLayout();
    initFaceCubes(parent);
}

QLayout* View2D::getLayout() const
{
    return gridLayout;
}

void View2D::initFaceCubes(QWidget *parent)
{
    mUpFace    = new FaceCube2D(parent, m_model2D, RubikFace::Up);
    mFrontFace = new FaceCube2D(parent, m_model2D, RubikFace::Front);
    mRightFace = new FaceCube2D(parent, m_model2D, RubikFace::Right);
    mDownFace  = new FaceCube2D(parent, m_model2D, RubikFace::Down);
    mLeftFace  = new FaceCube2D(parent, m_model2D, RubikFace::Left);
    mBackFace  = new FaceCube2D(parent, m_model2D, RubikFace::Back);

    gridLayout->addWidget(mUpFace,    0, 1);
    gridLayout->addWidget(mLeftFace,  1, 0);
    gridLayout->addWidget(mFrontFace, 1, 1);
    gridLayout->addWidget(mRightFace, 1, 2);
    gridLayout->addWidget(mBackFace,  1, 3);
    gridLayout->addWidget(mDownFace,  2, 1);
}
