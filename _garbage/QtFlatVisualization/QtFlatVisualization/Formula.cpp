#include "Formula.h"
#include <string.h>
#include <QException>

const int MAX_STEPS = 30;

Formula::Formula(char* cFormula)
{
   char cStep[3];

   int stepindex = 0;
   int charindex = 0;
   int length = strlen(cFormula);
   while (stepindex < MAX_STEPS && charindex < length)
   {
       cStep[0] = cFormula[charindex++];
       if (charindex < length && cFormula[charindex] != ' ')
       {
           cStep[1] = cFormula[charindex++];
           cStep[2] = '\0';
       }
       else
           cStep[1] = '\0';

        FormulaStep fs(cStep);
        m_Steps[stepindex++] = fs;

        // interate more not spacing characters
        while (cFormula[charindex] != ' ' && charindex < length)
            charindex++;
        // interate then the spacing characters
        while (cFormula[charindex] == ' ' && charindex < length)
            charindex++;

   }
   m_nCount = stepindex;
   m_nIndex = 0;
}

int Formula::Count()
{
    return m_nCount;
}

int Formula::Index()
{
    return m_nIndex;
}

FormulaStep Formula::FormulaStepAt(int index)
{
    if (index < 0 || index > m_nCount)
        throw new QException();
    return m_Steps[index];
}

// advance a step if possible and return it (return false if at the end of formula)
bool Formula::bForwardStep(FormulaStep& fs)
{
    bool bResult = (m_nIndex < m_nCount);
    if (bResult)
    {
        fs = m_Steps[m_nIndex++];
    } else
    {
        fs = FormulaStep();
    }
    return bResult;
}

// advance a step if possible and return it (return false if at the end of formula)
bool Formula::bBackwardStep(FormulaStep& fs)
{
    bool bResult = (m_nIndex > 0);
    if (bResult)
    {
        m_nIndex--;
        RubikFace face = m_Steps[m_nIndex].Face();
        FormulaStep::FormulaStepTypeEnum type = m_Steps[m_nIndex].FST();
        if (type == FormulaStep::FST_CLOCK)
            type = FormulaStep::FST_COUNTER;
        else if (type == FormulaStep::FST_COUNTER)
            type = FormulaStep::FST_CLOCK;
        fs = FormulaStep(face, type);
        ;
    } else
    {
        fs = FormulaStep();
    }
    return bResult;
}
