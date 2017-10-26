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
    explicit FormulaHandler(Ui::MainWindow *ui,
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
    Ui::MainWindow *m_ui;

    Formula mFormula = "";

    void backwardStep();
    void forwardStep();

    void performMove(FormulaStep fs);

    RubikFace face;
    void f();

};

#endif // FORMULAHANDLER_H
