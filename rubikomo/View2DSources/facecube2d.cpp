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
    Q_UNUSED(pe);
    QPainter painter(this);
    painter.fillRect(rect(), Qt::black);

    for (unsigned i = 0; i < 3; ++i)
    {
        for (unsigned j = 0; j < 3; ++j)
        {
            QColor color = RubikFaceUtils::colorDigitToQColor(m_model->getMatrixValue(m_representing, i, j));
            painter.setPen(color);
            painter.setBrush(color);
            painter.drawRect(mRectMatrix[i][j]);
        }
    }

    QString letter = RubikFaceUtils::colorEnumToLetter(m_representing);
    QFont font = painter.font();
    painter.setPen(Qt::black);
    font.setPointSize(24);
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(mRectMatrix[1][1], Qt::AlignCenter, letter);
}

void FaceCube2D::mousePressEvent(QMouseEvent *event)
{
    for(int row = 0; row < 3; ++row)
    {
        for(int col = 0; col < 3; ++col)
        {
            if(mRectMatrix[row][col].contains(event->x(), event->y(), true))
            {
                if(row != 1 || col != 1)
                    emit frameClicked(m_representing, row, col);
                break;
            }
        }
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
