#include "formulastep.h"

FormulaStep::FormulaStep( RubikFace face, FormulaStepTypeEnum FST )
    : mFace(face), mFST(FST)
{
    switch (mFace)
    {
    case RubikFace::Up   : mDesc[0] = 'U'; break;
    case RubikFace::Down : mDesc[0] = 'D'; break;
    case RubikFace::Right: mDesc[0] = 'R'; break;
    case RubikFace::Front: mDesc[0] = 'F'; break;
    case RubikFace::Left : mDesc[0] = 'L'; break;
    case RubikFace::Back : mDesc[0] = 'B'; break;
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
    case 'U': mFace = RubikFace::Up   ; break;
    case 'D': mFace = RubikFace::Down ; break;
    case 'R': mFace = RubikFace::Right; break;
    case 'F': mFace = RubikFace::Front; break;
    case 'L': mFace = RubikFace::Left ; break;
    case 'B': mFace = RubikFace::Back ; break;
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
 : mFace(RubikFace::Up), mFST(FST_CLOCK), mDesc("U")
{
}

void FormulaStep::GetDesc(char* cDesc)
{
    strcpy_s(cDesc, 3, mDesc);
}

