#include "facecube2d.h"

FaceCube2D::FaceCube2D(QWidget *parent) : QFrame(parent)
{
    mFace = "UUUUUUUUU";

    setMinimumSize(100, 100);
    initRectMatrix();
    recalculateDrawingPoint();
    updateRectMatrix();
}

FaceCube2D::FaceCube2D(QWidget *parent, const QString &faceString)
    : QFrame(parent), mFace{faceString}
{
    setMinimumSize(100, 100);
    initRectMatrix();
    recalculateDrawingPoint();
    updateRectMatrix();
}

//FaceCube2D::~FaceCube2D()
//{
//    delete mRect[0];
//    delete mRect[1];
//    delete mRect[2];
//    delete mRect;
//}

void FaceCube2D::paintEvent(QPaintEvent *pe)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::black);

    for (unsigned i = 0; i < 3; ++i)
    {
        for (unsigned j = 0; j < 3; ++j)
        {
            QColor color = determineColorFromStringPosition(i * 3 + j);
            painter.setPen(color);
            painter.setBrush(color);

            painter.drawRect(mRect[i][j]);
        }
    }

}

void FaceCube2D::resizeEvent(QResizeEvent *re)
{
    recalculateDrawingPoint();
    updateRectMatrix();
}

void FaceCube2D::setFaceString(const QString &faceString)
{
    mFace = faceString;
    //??
    update();
}

void FaceCube2D::setBorderWidth(int borderWidth)
{
    mBorderWidth = borderWidth;
    updateRectMatrix();
    update();
}

void FaceCube2D::initRectMatrix()
{
    mRect = new QRect*[3];
    mRect[0] = new QRect[3];
    mRect[1] = new QRect[3];
    mRect[2] = new QRect[3];
}

void FaceCube2D::recalculateDrawingPoint()
{
    mMatrixDrawingPoint.setX(0);
    mMatrixDrawingPoint.setY(0);
    int widgetWidth = width();
    int widgetHeight = height();
    if (widgetWidth > widgetHeight)
    {
        mMatrixDrawingPoint.setX((widgetWidth - widgetHeight) / 2);
    }
    else
    {
        mMatrixDrawingPoint.setY((widgetHeight - widgetWidth) / 2);
    }
}

void FaceCube2D::updateRectMatrix()
{
    int squareLength = mMatrixDrawingPoint.x();
    if (!squareLength)
    {
        squareLength = mMatrixDrawingPoint.y();
    }


    squareLength = (squareLength - 4 * mBorderWidth) / 3;

    for (unsigned i = 0; i < 3; ++i)
    {
        for (unsigned j = 0; j < 3; ++j)
        {
            mRect[i][j].setRect(
                        mMatrixDrawingPoint.x() + mBorderWidth + j * (squareLength + mBorderWidth),
                        mMatrixDrawingPoint.y() + mBorderWidth + i * (squareLength + mBorderWidth),
                        squareLength,
                        squareLength);
        }
    }
}

QColor FaceCube2D::determineColorFromStringPosition(int pos)
{
    switch (mFace.toStdString()[pos]) {
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
