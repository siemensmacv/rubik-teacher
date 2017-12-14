#ifndef MODELRUBIK_CORNERSEDGES_H
#define MODELRUBIK_CORNERSEDGES_H
#include "rubikcorner.h"
#include "rubikedge.h"
#include "rubikface.h"
#include <string>
#include <algorithm>
#include <iterator>

CornerOrientation& operator++(CornerOrientation& variable, int);
CornerOrientation& operator--(CornerOrientation& variable, int);
EdgeOrientation& operator!(EdgeOrientation& variable);

class ModelRubik_CornersEdges
{
public:
	ModelRubik_CornersEdges();
	~ModelRubik_CornersEdges();

    void rotateFaceClockwise(const RubikFace &face);
    void rotateFaceCounterClockwise(const RubikFace &face);

    void setCornersEdges(std::string input);

    Corner getCorner(const Corner &position) const;
    CornerOrientation getCornerOrientation(const Corner &position) const;

    Edge getEdge(const Edge &position) const;
    EdgeOrientation getEdgeOrientation(const Edge &position) const;

    RubikFace getCenter(const RubikFace &position) const;

    void to3DString2(char** resultArray);

private:
	void init_corners();
	void init_edges();
	void init_centers();

    void rotateCornersClockwise(int UL, int UR, int DR, int DL, const RubikFace &face);
    void rotateCornersCounterClockwise(int UR, int UL, int DL, int DR, const RubikFace &face);

    void rotateEdgesClockwise(int up, int right, int down, int left, const RubikFace &face);
    void rotateEdgesCounterClockwise(int up, int left, int down, int right, const RubikFace &face);

    bool edgeValueInMiddleSlice(int index);
    bool edgeValueInEquatorSlice(int index);
    bool edgeValueInStandingSlice(int index);

    std::string permutateStringForward(std::string input);

    void cornerToString(int index, char* result);
    void edgeToString(int index, char* result);
    void toString(char* result);

    Corner corner_position[8];
    Edge edge_position[12];
    RubikFace center[6];
    CornerOrientation corner_orientation[8];
    EdgeOrientation edge_orientation[12];
};

#endif // MODELRUBIK_CORNERSEDGES_H
