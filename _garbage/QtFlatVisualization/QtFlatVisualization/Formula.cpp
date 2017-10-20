#include "Formula.h"
#include <string.h>

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
           cStep[2] = cFormula[charindex++] = '\0';
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
}
