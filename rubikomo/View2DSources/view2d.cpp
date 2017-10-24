#include <View2DHeaders/view2d.h>

View2D::View2D(QWidget *parent, ModelRubik *model, bool enableInput) : QWidget(parent)
{
    m_model = model;
    gridLayout = new QGridLayout();
    initFaceCubes(parent);

    connect(model, &ModelRubik::cubeChanged, this, &View2D::refresh);
    if(enableInput == true)
    {
        connect(mUpFace, &FaceCube2D::frameClicked, this, &View2D::onFaceCubeClicked);
        connect(mFrontFace, &FaceCube2D::frameClicked, this, &View2D::onFaceCubeClicked);
        connect(mRightFace, &FaceCube2D::frameClicked, this, &View2D::onFaceCubeClicked);
        connect(mDownFace, &FaceCube2D::frameClicked, this, &View2D::onFaceCubeClicked);
        connect(mLeftFace, &FaceCube2D::frameClicked, this, &View2D::onFaceCubeClicked);
        connect(mBackFace, &FaceCube2D::frameClicked, this, &View2D::onFaceCubeClicked);
    }
}

QLayout* View2D::getLayout() const
{
    return gridLayout;
}

void View2D::setInputColor(RubikFace color)
{
	m_inputColor = static_cast<int>(color);
}

void View2D::initFaceCubes(QWidget *parent)
{
    mUpFace    = new FaceCube2D(parent, m_model, RubikFace::Up);
    mFrontFace = new FaceCube2D(parent, m_model, RubikFace::Front);
    mRightFace = new FaceCube2D(parent, m_model, RubikFace::Right);
    mDownFace  = new FaceCube2D(parent, m_model, RubikFace::Down);
    mLeftFace  = new FaceCube2D(parent, m_model, RubikFace::Left);
    mBackFace  = new FaceCube2D(parent, m_model, RubikFace::Back);

    gridLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding), 0, 0);
    gridLayout->addWidget(mUpFace,    1, 1);
    gridLayout->addWidget(mLeftFace,  2, 0);
    gridLayout->addWidget(mFrontFace, 2, 1);
    gridLayout->addWidget(mRightFace, 2, 2);
    gridLayout->addWidget(mBackFace,  2, 3);
    gridLayout->addWidget(mDownFace,  3, 1);
    gridLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding), 4, 0);
}

void View2D::refresh()
{
    mUpFace->update();
    mFrontFace->update();
    mRightFace->update();
    mDownFace->update();
    mLeftFace->update();
    mBackFace->update();
}

void View2D::onFaceCubeClicked(RubikFace face, int row, int column)
{
	if(m_inputColor != -1)
        if(m_model->getMatrixValue(face, row, column) != m_inputColor)
            m_model->setMatrixValue(face, row, column, m_inputColor);
}
