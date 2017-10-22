#ifndef RUBIK2DHANDLER_H
#define RUBIK2DHANDLER_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "facecube2d.h"
#include <QString>
#include <string>
#include "Cub_Rubik.h"
#include "../ckociemba/facecube.h"
#include "../ckociemba/cubiecube.h"
#include "rubikface.h"


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

    ~Rubik2DHandler();

    std::string toString() const;
    QString toQString() const;

    void rotateFaceClockwise(const RubikFace &face);
    void rotateFaceCounterClockwise(const RubikFace &face);

signals:

public slots:
    void frontClock();
    void frontCounterClock();
    void backClock();
    void backCounterClock();
    void upClock();
    void upCounterClock();
    void downClock();
    void downCounterClock();
    void leftClock();
    void leftCounterClock();
    void rightClock();
    void rightCounterClock();
    void xAxisClock();
    void xAxisCounterClock();
    void yAxisClock();
    void yAxisCounterClock();
    void zAxisClock();
    void zAxisCounterClock();

    void Solve();

    void setBorderWidth(int borderWidth);
    void setFrameSize(int frameSize);
    void updateCube(const std::string & cubeString);
    void updateCube(const QString & cubeString);

private:
    void initFaceCubes(const std::string & sequence
                  = "UUUUUUUUUFFFFFFFFFRRRRRRRRRDDDDDDDDDLLLLLLLLLBBBBBBBBB");
    void initCube();
    void getFacesFromCube();
    void refreshView();
    void refreshRepresentations();

    QGridLayout *mGridLayout;
    QWidget *mGridLayoutWidget;
    FaceCube2D *mUpFace, *mDownFace,
        *mLeftFace, *mRightFace,
        *mFrontFace, *mBackFace;
    Cub_Rubik<QColor> *mCube;
    QLabel *mLabelCubeRepresentation;
    QLabel *mLabelCubeCubiecubeRepresentation[17];
    QLabel *mLabelSolution;

    facecube_t *mFaceCube;
    cubiecube_t *mCubieCube;
};

#endif // RUBIK2DHANDLER_H
