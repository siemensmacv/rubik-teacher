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
    explicit FormulaHandler(QGridLayout *gridLayout,
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

    Formula mFormula = "";

    void backwardStep();
    void forwardStep();

    void performMove(FormulaStep fs);
};

#endif // FORMULAHANDLER_H
