#include "FormulaStep.h"
#include <string.h>

FormulaStep::FormulaStep( FormulaStepMoveEnum FSE, FormulaStepTypeEnum FST )
    : mFSE(FSE), mFST(FST)
{
    switch (mFSE)
    {
    case FSM_U: mDesc[0] = 'U'; break;
    case FSM_D: mDesc[0] = 'D'; break;
    case FSM_R: mDesc[0] = 'R'; break;
    case FSM_F: mDesc[0] = 'F'; break;
    case FSM_L: mDesc[0] = 'L'; break;
    case FSM_B: mDesc[0] = 'B'; break;
    }

    switch (mFST)
    {
    case FST_CLOCK: mDesc[1] = '\0'; break;
    case FST_COUNTER: mDesc[1] = '\''; mDesc[2] = '\0'; break;
    case FST_DOUBLE: mDesc[1] = '2'; mDesc[2] = '\0'; break;
    }
}

FormulaStep::FormulaStep( char desc[3] )
{
    switch (desc[0])
    {
    case 'U': mFSE = FSM_U; break;
    case 'D': mFSE = FSM_D; break;
    case 'R': mFSE = FSM_R; break;
    case 'F': mFSE = FSM_F; break;
    case 'L': mFSE = FSM_L; break;
    case 'B': mFSE = FSM_B; break;
    }

    if (strlen(desc) == 1)
        mFST = FST_CLOCK;
    else if (desc[1] == '\'')
        mFST = FST_COUNTER;
    else if (desc[1] == '2')
        mFST = FST_DOUBLE;
    strcpy_s(mDesc, 3, desc);
}

FormulaStep::FormulaStep( )
 : mFSE(FSM_U), mFST(FST_CLOCK), mDesc("U")
{
}

void FormulaStep::GetDesc(char* cDesc)
{
    strcpy_s(cDesc, 3, mDesc);
}

