#ifndef RUBIK2DHANDLER_H
#define RUBIK2DHANDLER_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include "facecube2d.h"
#include <QString>
#include <string>
#include "Cub_Rubik.h"

class Rubik2DHandler : public QObject
{
    Q_OBJECT
public:
    explicit Rubik2DHandler(QGridLayout *gridLayout,
                            QWidget *gridLayoutQWidget);
    explicit Rubik2DHandler(QGridLayout *gridLayout,
                            QWidget *gridLayoutQWidget,
                            const std::string & sequence);
    explicit Rubik2DHandler(QGridLayout *gridLayout,
                            QWidget *gridLayoutQWidget,
                            const QString & sequence);

    std::string toString() const;
    QString toQString() const;

signals:

public slots:
    void setBorderWidth(int borderWidth);
    void setFrameSize(int frameSize);
    void updateCube(const std::string & cubeString);
    void updateCube(const QString & cubeString);

private:
    void initFaceCubes(const std::string & sequence
                  = "UUUUUUUUUFFFFFFFFFRRRRRRRRR"
                  + "DDDDDDDDDLLLLLLLLLBBBBBBBBB");
    //to do
    void initCube();
    void update();

    QGridLayout *mGridLayout;
    QWidget *mGridLayoutWidget;
    FaceCube2D *mUpFace, *mDownFace,
        *mLeftFace, *mRightFace,
        *mFrontFace, *mBackFace;
    // to do
    Cub_Rubik *mCube;
};

#endif // RUBIK2DHANDLER_H
