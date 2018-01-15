#ifndef ALGORITHMSTEP_H
#define ALGORITHMSTEP_H

#include "../rubikcorner.h"
#include "../rubikedge.h"

#include <vector>
#include <string>

class CornerSwitch
{
public:
    Corner m_Corner;
    Corner m_ActualCorner;
    int m_nOrientation;
};

class EdgeSwitch
{
public:
    Edge m_Edge;
    Edge m_ActualEdge;
    int m_nOrientation;
};

class AlgorithmStep
{
public:
    // AlgorithmStep
    // - a_sDescription is of form "C:<corner_switch_1>;...;<corner_switch_n>;#E:<edge_switch_1>;...;<edge_switch_m>;
    // where <corner_switch_i> is of form <corner>,<actualcorner>,<orientation> where <corner> is one of the 8 corners
    // and <edge_swithc_i> is of form <edge>#<actualedge>#<orientation> where <edge> is one of the 12 edges
    // <orientation> is 0 to 2 for corners and 0 to 1 for edges
    // m or n can be 0 but not both
    // - a_sFormula describes the formula to be applied
    // - a_sTag describes a standard formula, if empty it will be generated
    AlgorithmStep(std::string a_sDescription, std::string a_sFormula, std::string a_sTag);
private:
    int m_nSwitchedCorners;
    std::vector<CornerSwitch> m_vecSwitchedCorners;
    int m_nSwitchedEdges;
    std::vector<EdgeSwitch> m_vecSwitchedEdges;
    std::string m_sFormula;
};

#endif // ALGORITHMSTEP_H
