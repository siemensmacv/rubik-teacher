#include "formulahandler.h"
#include <QPushButton>
#include <QIcon>
#include <QStyle>
#include "controllerrubik.h"

FormulaHandler::FormulaHandler(QPushButton *backButton, QPushButton *forwardButton, QPushButton *playForwardButton, QPushButton *playBackwardButton, QGridLayout *gridLayout, QWidget *gridLayoutQWidget, ControllerRubik *rubikController)
    : QObject(gridLayoutQWidget),
      mBackButton(backButton),
      mForwardButton(forwardButton),
      mPlayForwardButton(playForwardButton),
      mPlayBackwardButton(playBackwardButton),
      mGridLayout{gridLayout},
      mGridLayoutWidget{gridLayoutQWidget},
      mRubikController{rubikController}
{
    initFormula();
}


FormulaHandler::~FormulaHandler()
{
}

void FormulaHandler::createBitmapButton(QWidget *parent, QPushButton *theButton, QString sPath)
{
    Q_UNUSED(parent);
    QPixmap pixmap(sPath);
    QIcon buttonIcon(pixmap);
    theButton->setIcon(buttonIcon);
    theButton->setIconSize(pixmap.rect().size());
}

void FormulaHandler::initFormula()
{
    mGridLayoutFormulas = new QGridLayout(mGridLayoutWidget);

    createFormula();

    mGridLayout->addLayout(mGridLayoutFormulas, 0, 0);

    QGridLayout *lGridLayoutButtons = new QGridLayout(mGridLayoutWidget);

    createBitmapButton(mGridLayoutWidget, mPlayBackwardButton,":/img/resources/backward.png");
    mPlayBackwardButton->setVisible(true);
    connect(mPlayBackwardButton, &QPushButton::clicked, this, &FormulaHandler::playBackward);
    lGridLayoutButtons->addWidget(mPlayBackwardButton, 0, 1);

    createBitmapButton(mGridLayoutWidget, mBackButton,":/img/resources/playBack.png");
    mBackButton->setVisible(true);
    connect(mBackButton, &QPushButton::clicked, this, &FormulaHandler::backwardStep);
    lGridLayoutButtons->addWidget(mBackButton, 0, 2);

    createBitmapButton(mGridLayoutWidget, mForwardButton,":/img/resources/play.png");
    mForwardButton->setVisible(true);
    connect(mForwardButton, &QPushButton::clicked, this, &FormulaHandler::forwardStep);
    lGridLayoutButtons->addWidget(mForwardButton, 0, 3);

    createBitmapButton(mGridLayoutWidget, mPlayForwardButton,":/img/resources/forward.png");
    mPlayForwardButton->setVisible(true);
    connect(mPlayForwardButton, &QPushButton::clicked, this, &FormulaHandler::playForward);
    lGridLayoutButtons->addWidget(mPlayForwardButton, 0, 4);

    mGridLayout->addLayout(lGridLayoutButtons, 1, 0);
}

void FormulaHandler::cleanFormula()
{
    for (int i = 0; i < mFormula.Count(); i++)
    {
        mGridLayoutFormulas->removeWidget(mFormulaStepsLabels[i]);
        delete mFormulaStepsLabels[i];
        mFormulaStepsLabels[i] = nullptr;
    }
}

void FormulaHandler::createFormula()
{
    for (int i = 0; i < mFormula.Count(); i++)
    {
        FormulaStep fs = mFormula.FormulaStepAt(i);
        char desc[3];
        fs.GetDesc(desc);
        QLabel *lLabel = new QLabel(desc);
        QFont font(lLabel->font());
        font.setPointSize(14);
        lLabel->setFont(font);
        mFormulaStepsLabels[i] = lLabel;
        mGridLayoutFormulas->addWidget(lLabel, 0, i + 1);
    }
}

void FormulaHandler::FormulaChanged(Formula f)
{
    cleanFormula();
    mFormula = f;
    createFormula();
}

void FormulaHandler::backwardStep()
{
    FormulaStep fs;
    if (mFormula.bBackwardStep(fs))
    {
        performMove(fs);
        mFormulaStepsLabels[mFormula.Index()]->setStyleSheet("QLabel { color : white; }");
    }
}

void FormulaHandler::playBackward()
{
    FormulaStep fs;
    if (mFormula.bBackwardStep(fs))
    {
        performMove(fs);
        mFormulaStepsLabels[mFormula.Index()]->setStyleSheet("QLabel { color : white; }");
        int timeToWait = fs.FST() == fs.FST_DOUBLE ? 2020 : 1010;
        QTimer::singleShot(timeToWait,this,&FormulaHandler::playBackward);
    }
}

void FormulaHandler::forwardStep()
{
    FormulaStep fs;
    if (mFormula.bForwardStep(fs))
    {
        performMove(fs);
        mFormulaStepsLabels[mFormula.Index() - 1]->setStyleSheet("QLabel { color : red; }");
    }
}

void FormulaHandler::playForward()
{
    FormulaStep fs;
    if (mFormula.bForwardStep(fs))
    {
        performMove(fs);
        mFormulaStepsLabels[mFormula.Index() - 1]->setStyleSheet("QLabel { color : red; }");
        int timeToWait = fs.FST() == fs.FST_DOUBLE ? 2020 : 1010;
        QTimer::singleShot(timeToWait,this,&FormulaHandler::playForward);
    }
}

void FormulaHandler::performMove(FormulaStep fs)
{
    face = fs.Face();

    switch (fs.FST())
    {
    case FormulaStep::FST_CLOCK:
        mRubikController->rotateFaceClockwise(face);
        break;
    case FormulaStep::FST_COUNTER:
        mRubikController->rotateFaceCounterClockwise(face);
        break;
    case FormulaStep::FST_DOUBLE:
        mRubikController->rotateFaceClockwise(face);
        QTimer::singleShot(1010,this,&FormulaHandler::f);
        break;
    }
}

void FormulaHandler::f(){
    mRubikController->rotateFaceClockwise(face);
}
