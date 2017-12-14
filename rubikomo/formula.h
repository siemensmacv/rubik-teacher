#ifndef FORMULA_H
#define FORMULA_H

#include "formulastep.h"
#include <string>
#include <QException>

// define a formula with several steps;
class Formula
{
public:
    Formula(std::string formula);

    int Count();
    int Index();
    FormulaStep FormulaStepAt(int index);

    // advance a step if possible and return it (return false if at the end of formula)
    bool bForwardStep(FormulaStep& fs);

    // advance a step if possible and return it (return false if at the end of formula)
    bool bBackwardStep(FormulaStep& fs);

private:
    FormulaStep m_Steps[30];
    int  m_nCount;
    int  m_nIndex;
};

#endif // FORMULA_H
