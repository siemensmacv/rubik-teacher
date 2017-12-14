#ifndef FORMULAHANDLER_H
#define FORMULAHANDLER_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "formula.h"
#include "controllerrubik.h"

class FormulaHandler : public QObject
{
    Q_OBJECT
public:
    explicit FormulaHandler(QPushButton* backButton,
                            QPushButton* forwardButton,
                            QPushButton* playForwardButton,
                            QPushButton* playBackwardButton,
                            QGridLayout *gridLayout,
                            QWidget *gridLayoutQWidget,
                            ControllerRubik *rubikController);

    ~FormulaHandler();

public slots:
    void FormulaChanged(Formula f);

private:
    void initFormula();
    void cleanFormula();
    void createFormula();

    QGridLayout *mGridLayout;
    QGridLayout *mGridLayoutFormulas;
    QWidget *mGridLayoutWidget;
    ControllerRubik *mRubikController;
    QLabel *mFormulaStepsLabels[30];

    QPushButton* mBackButton;
    QPushButton* mForwardButton;
    QPushButton* mPlayForwardButton;
    QPushButton* mPlayBackwardButton;

    Formula mFormula = "";

    void backwardStep();
    void forwardStep();
    void playForward();
    void playBackward();

    void performMove(FormulaStep fs);

    void createBitmapButton(QWidget *parent = nullptr, QPushButton *theButton = nullptr, QString sPath = nullptr);

    RubikFace face;
    void f();

};

#endif // FORMULAHANDLER_H
