#include <View2DHeaders/facecube2d.h>

FaceCube2D::FaceCube2D(QWidget *parent, ModelRubik *model, RubikFace representing) : QFrame(parent)
{
    m_model = model;
    m_representing = representing;
    updateFrameSize();
    initRectMatrix();
    updateRectMatrix();
}

FaceCube2D::~FaceCube2D()
{
    for (unsigned i = 0; i < 3; ++i)
    {
       delete mRectMatrix[i];
    }

    delete mRectMatrix;
}

void FaceCube2D::paintEvent(QPaintEvent *pe)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::black);

    for (unsigned i = 0; i < 3; ++i)
    {
        for (unsigned j = 0; j < 3; ++j)
        {
            QColor color = getColorFromValue(m_model->getMatrixValue(m_representing, i, j));
            painter.setPen(color);
            painter.setBrush(color);

            painter.drawRect(mRectMatrix[i][j]);
        }
    }
}

QColor FaceCube2D::getColorFromValue(int value) const
{
    RubikFace face = static_cast<RubikFace>(value/10 - 1);
    switch(face)
    {
	case RubikFace::Up:
        return QColor(255, 255, 0);
	case RubikFace::Left:
        return QColor(255, 0, 0);
	case RubikFace::Front:
        return QColor(0, 255, 0);
	case RubikFace::Right:
        return QColor(255, 165, 0);
	case RubikFace::Back:
        return QColor(0, 0, 255);
	case RubikFace::Down:
        return QColor(255, 255, 255);
    }
}

void FaceCube2D::setBorderWidth(int borderWidth)
{
    if (borderWidth == mBorderWidth)
        return;
    mBorderWidth = borderWidth;
    updateRectMatrix();
    update();
}

void FaceCube2D::setFrameSize(int frameSize)
{
    if (frameSize == mFrameSize)
        return;
    mFrameSize = frameSize;
    updateFrameSize();
    updateRectMatrix();
    update();
}

void FaceCube2D::updateFrameSize()
{
    setMinimumSize(mFrameSize, mFrameSize);
    setMaximumSize(mFrameSize, mFrameSize);
}

void FaceCube2D::initRectMatrix()
{
    mRectMatrix = new QRect*[3];
    for (unsigned i = 0; i < 3; ++i)
    {
        mRectMatrix[i] = new QRect[3];
    }
}

void FaceCube2D::updateRectMatrix()
{
    int smallSquareLength = (mFrameSize - 6 * mBorderWidth) / 3;
    for (unsigned i = 0; i < 3; ++i)
    {
        for (unsigned j = 0; j < 3; ++j)
        {
            mRectMatrix[i][j].setRect(
            2 * mBorderWidth + j * (mBorderWidth + smallSquareLength),
            2 * mBorderWidth + i * (mBorderWidth + smallSquareLength),
            smallSquareLength,
            smallSquareLength);
        }
    }
}
