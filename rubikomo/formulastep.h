#pragma once

#include "rubikface.h"

// define a formula step
// each step is defined by one of the face movements and the type
class FormulaStep
{
public:
//    typedef enum _FormulaStepMoveEnum {FSM_U, FSM_R, FSM_F, FSM_D, FSM_L, FSM_B} FormulaStepMoveEnum;
    typedef enum _FormulaStepTypeEnum {FST_CLOCK, FST_COUNTER, FST_DOUBLE} FormulaStepTypeEnum;

    FormulaStep( RubikFace face, FormulaStepTypeEnum FST );
    FormulaStep( char desc[3] );
    FormulaStep( );

    RubikFace Face() {return mFace;}
    FormulaStepTypeEnum FST() {return mFST;}
    void GetDesc( char* cDesc);

private:
    RubikFace mFace;
    FormulaStepTypeEnum mFST;
    char mDesc[3];
};
