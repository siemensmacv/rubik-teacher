#include "facecube2d.h"

FaceCube2D::FaceCube2D(QWidget *parent) : QFrame(parent)
{
    updateFrameSize();
    initColorMatrix();
    initRectMatrix();
    updateRectMatrix();
}

FaceCube2D::FaceCube2D(QWidget *parent, const std::string &faceString)
    : QFrame(parent)
{
    updateFrameSize();
    initColorMatrix();
    initRectMatrix();
    updateRectMatrix();
    updateColorMatrix(faceString);
}

FaceCube2D::FaceCube2D(QWidget *parent, const QString &faceString)
    : FaceCube2D(parent, faceString.toStdString())
{
}

// to do
//FaceCube2D::~FaceCube2D()
//{
//}

void FaceCube2D::paintEvent(QPaintEvent *pe)
{

    QPainter painter(this);
    painter.fillRect(rect(), Qt::black);

    for (unsigned i = 0; i < 3; ++i)
    {
        for (unsigned j = 0; j < 3; ++j)
        {
            painter.setPen(mColorMatrix[i][j]);
            painter.setBrush(mColorMatrix[i][j]);

            painter.drawRect(mRectMatrix[i][j]);
        }
    }

}

QColor *&FaceCube2D::operator[](int pos)
{
    return mColorMatrix[pos];
}

QString FaceCube2D::toQString() const
{
    return QString(toString().c_str());
}

std::string FaceCube2D::toString() const
{
    std::string sequence = "";
    for (unsigned i = 0; i < 3; ++i)
    {
        for (unsigned j = 0; j < 3; ++j)
        {
            sequence += getCharFromColor(mColorMatrix[i][j]);
        }
    }
    sequence += '\0';
    return sequence;
}

QColor **FaceCube2D::getColorMatrix() const
{
    return mColorMatrix;
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

void FaceCube2D::setColorMatrix(QColor **matrix)
{
    if (matrix != mColorMatrix)
    {
        mColorMatrix = matrix;
    }
}

void FaceCube2D::updateColorMatrix(const QString &faceString)
{
    updateColorMatrix(faceString.toStdString());
}

void FaceCube2D::updateColorMatrix(const std::string &faceString)
{
    for (unsigned i = 0; i < 3; ++i)
    {
        for (unsigned j = 0; j < 3; ++j)
        {
            int poz = i * 3 + j;
            mColorMatrix[i][j] = getColorFromChar(faceString[poz]);
        }
    }
}

void FaceCube2D::updateFrameSize()
{
    setMinimumSize(mFrameSize, mFrameSize);
    setMaximumSize(mFrameSize, mFrameSize);
}

void FaceCube2D::initColorMatrix()
{
    mColorMatrix = new QColor*[3];
    for (unsigned i = 0; i < 3; ++i)
    {
        mColorMatrix[i] = new QColor[3];
        for (unsigned j = 0; j < 3; ++j)
            mColorMatrix[i][j].setRgb(0, 0, 0);
    }
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

QColor FaceCube2D::getColorFromChar(char letter) const
{
    switch (letter) {
    case 'U':
    case 'u':
        return Qt::yellow;
    case 'F':
    case 'f':
        return Qt::green;
    case 'L':
    case 'l':
        return Qt::red;
    case 'R':
    case 'r':
        return QColor(255, 165, 0);
    case 'B':
    case 'b':
        return Qt::blue;
    case 'D':
    case 'd':
        return Qt::white;
    default:
        return Qt::black;
    }
}

char FaceCube2D::getCharFromColor(QColor color) const
{
    if (color == Qt::yellow)
        return 'U';
    if (color == Qt::green)
        return 'F';
    if (color == Qt::red)
        return 'L';
    if (color == QColor(255, 165, 0))
        return 'R';
    if (color == Qt::blue)
        return 'B';
    if (color == Qt::white)
        return 'D';
    return 'x';
}
