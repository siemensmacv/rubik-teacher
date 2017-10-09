#include "rubik2dhandler.h"

Rubik2DHandler::Rubik2DHandler(QGridLayout *gridLayout, QWidget *gridLayoutQWidget)
    : QObject(gridLayoutQWidget),
      mGridLayout{gridLayout},
      mGridLayoutWidget{gridLayoutQWidget}
{
    initFaceCubes();
    initCube();
}

Rubik2DHandler::Rubik2DHandler(QGridLayout *gridLayout, QWidget *gridLayoutQWidget, const std::string &sequence)
    : QObject(gridLayoutQWidget),
      mGridLayout{gridLayout},
      mGridLayoutWidget{gridLayoutQWidget}
{
    initFaceCubes(sequence);
    initCube();
}

Rubik2DHandler::Rubik2DHandler(QGridLayout *gridLayout, QWidget *gridLayoutQWidget, const QString &sequence)
    : Rubik2DHandler(gridLayout, gridLayoutQWidget, sequence.toStdString())
{
}

std::string Rubik2DHandler::toString() const
{
    return mUpFace->toString() +
           mFrontFace->toString() +
           mRightFace->toString() +
           mDownFace->toString() +
           mLeftFace->toString() +
           mBackFace->toString();
}

QString Rubik2DHandler::toQString() const
{
    return QString(toString().c_str());
}

void Rubik2DHandler::frontClock()
{
    if (mCube)
    {
        mCube->frontClock();
        refreshView();
    }

}

void Rubik2DHandler::frontCounterClock()
{
   if (mCube)
   {
       mCube->frontCounterClock();
       refreshView();
   }
}

void Rubik2DHandler::backClock()
{
    if (mCube)
    {
        mCube->backClock();
        refreshView();
    }

}

void Rubik2DHandler::backCounterClock()
{
    if (mCube)
    {
        mCube->backCounterClock();
        refreshView();
    }
}

void Rubik2DHandler::upClock()
{
    if (mCube)
    {
        mCube->upClock();
        refreshView();
    }

}

void Rubik2DHandler::upCounterClock()
{
    if (mCube)
    {
        mCube->upCounterClock();
        refreshView();
    }
}

void Rubik2DHandler::downClock()
{
    if (mCube)
    {
        mCube->downClock();
        refreshView();
    }
}

void Rubik2DHandler::downCounterClock()
{
    if (mCube)
    {
        mCube->downCounterClock();
        refreshView();
    }
}

void Rubik2DHandler::leftClock()
{
    if (mCube)
    {
        mCube->leftClock();
        refreshView();
    }
}

void Rubik2DHandler::leftCounterClock()
{
    if (mCube)
    {
        mCube->leftCounterClock();
        refreshView();
    }
}

void Rubik2DHandler::rightClock()
{
    if (mCube)
    {
        mCube->rightClock();
        refreshView();
    }
}

void Rubik2DHandler::rightCounterClock()
{
    if (mCube)
    {
        mCube->rightCounterClock();
        refreshView();
    }
}

void Rubik2DHandler::xAxisClock()
{
    if (mCube)
    {
        mCube->xAxisClock();
        getFacesFromCube();
        refreshView();
    }
}

void Rubik2DHandler::xAxisCounterClock()
{
    if (mCube)
    {
        mCube->xAxisCounterClock();
        getFacesFromCube();
        refreshView();
    }
}

void Rubik2DHandler::yAxisClock()
{
    if (mCube)
    {
        mCube->yAxisClock();
        getFacesFromCube();
        refreshView();
    }
}

void Rubik2DHandler::yAxisCounterClock()
{
    if (mCube)
    {
        mCube->yAxisCounterClock();
        getFacesFromCube();
        refreshView();
    }
}

void Rubik2DHandler::zAxisClock()
{
    if (mCube)
    {
        mCube->zAxisClock();
        getFacesFromCube();
        refreshView();
    }
}

void Rubik2DHandler::zAxisCounterClock()
{
    if (mCube)
    {
        mCube->zAxisCounterClock();
        getFacesFromCube();
        refreshView();
    }
}

void Rubik2DHandler::setBorderWidth(int borderWidth)
{
    mUpFace   ->setBorderWidth(borderWidth);
    mFrontFace->setBorderWidth(borderWidth);
    mRightFace->setBorderWidth(borderWidth);
    mDownFace ->setBorderWidth(borderWidth);
    mLeftFace ->setBorderWidth(borderWidth);
    mBackFace ->setBorderWidth(borderWidth);
}

void Rubik2DHandler::setFrameSize(int frameSize)
{
    mUpFace   ->setFrameSize(frameSize);
    mFrontFace->setFrameSize(frameSize);
    mRightFace->setFrameSize(frameSize);
    mDownFace ->setFrameSize(frameSize);
    mLeftFace ->setFrameSize(frameSize);
    mBackFace ->setFrameSize(frameSize);
}

void Rubik2DHandler::updateCube(const std::string &cubeString)
{
    mUpFace   ->updateColorMatrix(cubeString.substr( 0, 9));
    mFrontFace->updateColorMatrix(cubeString.substr( 9, 9));
    mRightFace->updateColorMatrix(cubeString.substr(18, 9));
    mDownFace ->updateColorMatrix(cubeString.substr(27, 9));
    mLeftFace ->updateColorMatrix(cubeString.substr(36, 9));
    mBackFace ->updateColorMatrix(cubeString.substr(45, 9));
}

void Rubik2DHandler::updateCube(const QString &cubeString)
{
    updateCube(cubeString.toStdString());
}

void Rubik2DHandler::initFaceCubes(const std::string &sequence)
{
    mUpFace    = new FaceCube2D(mGridLayoutWidget, sequence.substr( 0, 9));
    mFrontFace = new FaceCube2D(mGridLayoutWidget, sequence.substr( 9, 9));
    mRightFace = new FaceCube2D(mGridLayoutWidget, sequence.substr(18, 9));
    mDownFace  = new FaceCube2D(mGridLayoutWidget, sequence.substr(27, 9));
    mLeftFace  = new FaceCube2D(mGridLayoutWidget, sequence.substr(36, 9));
    mBackFace  = new FaceCube2D(mGridLayoutWidget, sequence.substr(45, 9));

    mGridLayout->addWidget(mUpFace,    0, 1);
    mGridLayout->addWidget(mLeftFace,  1, 0);
    mGridLayout->addWidget(mFrontFace, 1, 1);
    mGridLayout->addWidget(mRightFace, 1, 2);
    mGridLayout->addWidget(mBackFace,  1, 3);
    mGridLayout->addWidget(mDownFace,  2, 1);
}

void Rubik2DHandler::initCube()
{
    mCube = new Cub_Rubik<QColor>(mFrontFace->getColorMatrix(),
                                  mBackFace->getColorMatrix(),
                                  mUpFace->getColorMatrix(),
                                  mDownFace->getColorMatrix(),
                                  mLeftFace->getColorMatrix(),
                                  mRightFace->getColorMatrix());
}

void Rubik2DHandler::getFacesFromCube()
{
    mUpFace->setColorMatrix(mCube->getUp());
    mDownFace->setColorMatrix(mCube->getDown());
    mFrontFace->setColorMatrix(mCube->getFront());
    mBackFace->setColorMatrix(mCube->getBack());
    mLeftFace->setColorMatrix(mCube->getLeft());
    mRightFace->setColorMatrix(mCube->getRight());
}

void Rubik2DHandler::refreshView()
{
    mUpFace->update();
    mDownFace->update();
    mLeftFace->update();
    mRightFace->update();
    mFrontFace->update();
    mBackFace->update();
}
