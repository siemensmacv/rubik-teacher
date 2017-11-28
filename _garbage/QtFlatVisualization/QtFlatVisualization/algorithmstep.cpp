#include "algorithmstep.h"
#include <string>
#include <vector>
#include <QString>

use namespace std;

vector<string> split(string str, string sep)
{
    char* cstr = const_cast<char*>(str.c_str());
    char* csep = const_cast<char*>(sep.c_str());
    char* current;
    vector<string> arr;
    current = strtok(cstr, csep);
    while (current != nullptr)
    {
        arr.push_back(current);
        current = strtok(nullptr, csep);
    }
    return arr;
}

AlgorithmStep::AlgorithmStep(std::string a_sDescription, std::string a_sFormula, std::string a_sTag)
{
    m_sFormula(a_sFormula);

    vector<string> arrBigSwitches = split(a_sDescription, "#");
    //assert(arrBigSwitches.size() == 2)
    vector<string> arrCornerSwitches = split(arrBigSwitches[0], ";");

    for (size_t i = 0; i < arrCornerSwitches.size(); i++)
    {
        vector<string> arrCornerSwitch = split(arrCornerSwitches[i], ",");
        //CornerSwitch cs;
        //cs.m_Corner = stringToCorner(arrCornerSwitch[0]);
        //cs.m_ActualCorner = stringToCorner(arrCornerSwitch[1]);
        //cs.m_Orientation = stringToInt(arrCornerSwitch[2]);
    }

    vector<string> arrEdgeSwitches = split(arrBigSwitches[1], ";");

    for (size_t i = 0; i < arrEdgeSwitches.size(); i++)
    {
        vector<string> arrEdgeSwitch = split(arrEdgeSwitches[i], ",");
        //EdgeSwitch es;
        //es.m_Edge = stringToCorner(arrEdgeSwitch[0]);
        //es.m_ActualEdge = stringToCorner(arrEdgeSwitch[1]);
        //es.m_Orientation = stringToInt(arrEdgeSwitch[2]);
    }

    if (a_sTag == "")
    {

    }
}
