#pragma once

#include "FormulaStep.h"

// define a formula with several steps;
class Formula
{
public:
    Formula(char* cFormula);

private:
    FormulaStep m_Steps[30];
    int  m_nCount;
    int  m_nIndex;
};
