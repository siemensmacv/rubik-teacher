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
