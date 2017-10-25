#include "formulahandler.h"
#include <QPushButton>
#include <QIcon>
#include <QStyle>
#include "controllerrubik.h"

FormulaHandler::FormulaHandler(QGridLayout *gridLayout, QWidget *gridLayoutQWidget, ControllerRubik *rubikController)
    : QObject(gridLayoutQWidget),
      mGridLayout{gridLayout},
      mGridLayoutWidget{gridLayoutQWidget},
      mRubikController{rubikController}
{
    initFormula();
}


FormulaHandler::~FormulaHandler()
{
}

QPushButton* createBitmapButton(QString sPath, QWidget *parent)
{
    QPixmap pixmap(sPath);
    QIcon buttonIcon(pixmap);
    QPushButton *button = new QPushButton(parent);
    button->setIcon(buttonIcon);
    button->setIconSize(pixmap.rect().size());

    return button;
}

void FormulaHandler::initFormula()
{
    mGridLayoutFormulas = new QGridLayout(mGridLayoutWidget);

    createFormula();

    mGridLayout->addLayout(mGridLayoutFormulas, 0, 0);

    QGridLayout *lGridLayoutButtons = new QGridLayout(mGridLayoutWidget);

    QPushButton *buttonBackward = createBitmapButton(":/img/resources/playBack.png", mGridLayoutWidget);
    buttonBackward->setVisible(true);
    connect(buttonBackward, &QPushButton::clicked, this, &FormulaHandler::backwardStep);
    lGridLayoutButtons->addWidget(buttonBackward, 0, 1);

    QPushButton *buttonForward = createBitmapButton(":/img/resources/play.png", mGridLayoutWidget);
    buttonForward->setVisible(true);
    connect(buttonForward, &QPushButton::clicked, this, &FormulaHandler::forwardStep);
    lGridLayoutButtons->addWidget(buttonForward, 0, 2);

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

void FormulaHandler::forwardStep()
{
    FormulaStep fs;
    if (mFormula.bForwardStep(fs))
    {
        performMove(fs);
        mFormulaStepsLabels[mFormula.Index() - 1]->setStyleSheet("QLabel { color : red; }");
    }
}

void FormulaHandler::performMove(FormulaStep fs)
{
    RubikFace face = fs.Face();

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
        mRubikController->rotateFaceClockwise(face);
        break;
    }
}
