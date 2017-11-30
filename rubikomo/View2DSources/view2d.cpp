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

    QGridLayout *lGridLayoutFaces = new QGridLayout(parent);
    lGridLayoutFaces->addItem(new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding), 0, 0);
    lGridLayoutFaces->addWidget(mUpFace,    1, 1);
    lGridLayoutFaces->addWidget(mLeftFace,  2, 0);
    lGridLayoutFaces->addWidget(mFrontFace, 2, 1);
    lGridLayoutFaces->addWidget(mRightFace, 2, 2);
    lGridLayoutFaces->addWidget(mBackFace,  2, 3);
    lGridLayoutFaces->addWidget(mDownFace,  3, 1);
    lGridLayoutFaces->addItem(new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding), 4, 0);

    gridLayout->addLayout(lGridLayoutFaces,  0, 0);

    QGridLayout *lGridLayoutRepresentations = new QGridLayout(parent);
    QGridLayout *lGridLayoutCubieRepresentationCKociemba = new QGridLayout(parent);
    for (int i = 0; i < 17; i++)
    {
        mLabelCubeCubiecubeRepresentation[i] = new QLabel();
        lGridLayoutCubieRepresentationCKociemba->addWidget(mLabelCubeCubiecubeRepresentation[i], i, 0);
    }
    lGridLayoutRepresentations->addLayout(lGridLayoutCubieRepresentationCKociemba, 0, 0);

    QGridLayout *lGridLayoutCubieRepresentationCornerEdges = new QGridLayout(parent);
    for (int i = 0; i < 17; i++)
    {
        mLabelCubeCornerEdgesRepresentation[i] = new QLabel();
        lGridLayoutCubieRepresentationCornerEdges->addWidget(mLabelCubeCornerEdgesRepresentation[i], i, 0);
    }
    lGridLayoutRepresentations->addLayout(lGridLayoutCubieRepresentationCornerEdges, 1, 0);

    gridLayout->addLayout(lGridLayoutRepresentations, 0, 1);
}

void View2D::refresh()
{
    mUpFace->update();
    mFrontFace->update();
    mRightFace->update();
    mDownFace->update();
    mLeftFace->update();
    mBackFace->update();
    refreshRepresentations();
}

extern "C" void cubiecubeToString3(char* cubeString, char** result);

void View2D::refreshRepresentations()
{
    char stringCube[60];
    std::string model = m_model->getModel();
    strcpy_s(stringCube, 60, model.c_str());

    char *cCubieCubeRepresentation[17];
    cubiecubeToString3(stringCube, cCubieCubeRepresentation);
    QString sCubieCubeRepresentation;
    for (int i = 0; i < 17; i++)
    {
        sCubieCubeRepresentation = cCubieCubeRepresentation[i];
        mLabelCubeCubiecubeRepresentation[i]->setText(sCubieCubeRepresentation);
        free(cCubieCubeRepresentation[i]);
    }
    m_model->to3DString2(cCubieCubeRepresentation);
    for (int i = 0; i < 17; i++)
    {
        sCubieCubeRepresentation = cCubieCubeRepresentation[i];
        mLabelCubeCornerEdgesRepresentation[i]->setText(sCubieCubeRepresentation);
        free(cCubieCubeRepresentation[i]);
    }
}


void View2D::onFaceCubeClicked(RubikFace face, int row, int column)
{
	if(m_inputColor != -1)
        if(m_model->getMatrixValue(face, row, column) != m_inputColor)
            m_model->setMatrixValue(face, row, column, m_inputColor);
}
