#include "FormulaHandler.h"
#include <QPushButton>
#include "rubik2dhandler.h"

FormulaHandler::FormulaHandler(QGridLayout *gridLayout, QWidget *gridLayoutQWidget, QObject *rubikController)
    : QObject(gridLayoutQWidget),
      mGridLayout{gridLayout},
      mGridLayoutWidget{gridLayoutQWidget},
      mRubikController{rubikController},
      mFormula{Formula("U R B")}
{
    initFormula();
}


FormulaHandler::~FormulaHandler()
{

}

void FormulaHandler::initFormula()
{
    mGridLayoutFormulas = new QGridLayout(mGridLayoutWidget);

    for (int i = 0; i < mFormula.Count(); i++)
    {
        FormulaStep fs = mFormula.FormulaStepAt(i);
        char desc[3];
        fs.GetDesc(desc);
        QLabel *lLabel = new QLabel(desc);
        mFormulaStepsLabels[i] = lLabel;
        mGridLayoutFormulas->addWidget(lLabel, 0, i + 1);
    }

    mGridLayout->addLayout(mGridLayoutFormulas, 0, 0);

    QGridLayout *lGridLayoutButtons = new QGridLayout(mGridLayoutWidget);

    QPushButton *buttonBackward = new QPushButton("<|", mGridLayoutWidget);
    buttonBackward->setVisible(true);
    connect(buttonBackward, &QPushButton::clicked, this, &FormulaHandler::backwardStep);
    lGridLayoutButtons->addWidget(buttonBackward, 0, 1);

    QPushButton *buttonForward = new QPushButton("|>", mGridLayoutWidget);
    buttonForward->setVisible(true);
    connect(buttonForward, &QPushButton::clicked, this, &FormulaHandler::forwardStep);
    lGridLayoutButtons->addWidget(buttonForward, 0, 2);

    mGridLayout->addLayout(lGridLayoutButtons, 1, 0);
}

void FormulaHandler::backwardStep()
{
    FormulaStep fs;
    if (mFormula.bBackwardStep(fs))
    {
        performMove(fs);
    }
}

void FormulaHandler::forwardStep()
{
    FormulaStep fs;
    if (mFormula.bForwardStep(fs))
    {
        performMove(fs);
    }
}

void FormulaHandler::performMove(FormulaStep fs)
{
    RubikFace face = fs.Face();

    // TODO replace this hardcoded cast with a proper member of type IControllerRubik
    Rubik2DHandler *rubik2DHandler = (Rubik2DHandler*) mRubikController;

    switch (fs.FST())
    {
    case FormulaStep::FST_CLOCK:
        rubik2DHandler->rotateFaceClockwise(face);
        break;
    case FormulaStep::FST_COUNTER:
        rubik2DHandler->rotateFaceCounterClockwise(face);
        break;
    case FormulaStep::FST_DOUBLE:
        rubik2DHandler->rotateFaceClockwise(face);
        rubik2DHandler->rotateFaceClockwise(face);
        break;
    }
}

//void FormulaHandler::frontClock()
//{
//    if (mCube)
//    {
//        mCube->frontClock();
//        refreshView();
//    }

//}

//void FormulaHandler::frontCounterClock()
//{
//   if (mCube)
//   {
//       mCube->frontCounterClock();
//       refreshView();
//   }
//}

//void FormulaHandler::backClock()
//{
//    if (mCube)
//    {
//        mCube->backClock();
//        refreshView();
//    }

//}

//void FormulaHandler::backCounterClock()
//{
//    if (mCube)
//    {
//        mCube->backCounterClock();
//        refreshView();
//    }
//}

//void FormulaHandler::upClock()
//{
//    if (mCube)
//    {
//        mCube->upClock();
//        refreshView();
//    }

//}

//void FormulaHandler::upCounterClock()
//{
//    if (mCube)
//    {
//        mCube->upCounterClock();
//        refreshView();
//    }
//}

//void FormulaHandler::downClock()
//{
//    if (mCube)
//    {
//        mCube->downClock();
//        refreshView();
//    }
//}

//void FormulaHandler::downCounterClock()
//{
//    if (mCube)
//    {
//        mCube->downCounterClock();
//        refreshView();
//    }
//}

//void FormulaHandler::leftClock()
//{
//    if (mCube)
//    {
//        mCube->leftClock();
//        refreshView();
//    }
//}

//void FormulaHandler::leftCounterClock()
//{
//    if (mCube)
//    {
//        mCube->leftCounterClock();
//        refreshView();
//    }
//}

//void FormulaHandler::rightClock()
//{
//    if (mCube)
//    {
//        mCube->rightClock();
//        refreshView();
//    }
//}

//void FormulaHandler::rightCounterClock()
//{
//    if (mCube)
//    {
//        mCube->rightCounterClock();
//        refreshView();
//    }
//}

//void FormulaHandler::xAxisClock()
//{
//    if (mCube)
//    {
//        mCube->xAxisClock();
//        getFacesFromCube();
//        refreshView();
//    }
//}

//void FormulaHandler::xAxisCounterClock()
//{
//    if (mCube)
//    {
//        mCube->xAxisCounterClock();
//        getFacesFromCube();
//        refreshView();
//    }
//}

//void FormulaHandler::yAxisClock()
//{
//    if (mCube)
//    {
//        mCube->yAxisClock();
//        getFacesFromCube();
//        refreshView();
//    }
//}

//void FormulaHandler::yAxisCounterClock()
//{
//    if (mCube)
//    {
//        mCube->yAxisCounterClock();
//        getFacesFromCube();
//        refreshView();
//    }
//}

//void FormulaHandler::zAxisClock()
//{
//    if (mCube)
//    {
//        mCube->zAxisClock();
//        getFacesFromCube();
//        refreshView();
//    }
//}

//void FormulaHandler::zAxisCounterClock()
//{
//    if (mCube)
//    {
//        mCube->zAxisCounterClock();
//        getFacesFromCube();
//        refreshView();
//    }
//}
