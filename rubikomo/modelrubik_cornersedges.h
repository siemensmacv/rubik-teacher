#pragma once
#include "rubikcorner.h"
#include "rubikedge.h"
#include "rubikface.h"

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
    void rotateXAxisClockwise();
    void rotateXAxisCounterClockwise();
    void rotateYAxisClockwise();
    void rotateYAxisCounterClockwise();
    void rotateZAxisClockwise();
    void rotateZAxisCounterClockwise();

    Corner getCorner(const Corner &position);
    CornerOrientation getCornerOrientation(const Corner &position);

    Edge getEdge(const Edge &position);
    EdgeOrientation getEdgeOrientation(const Edge &position);

    RubikFace getCenter(const RubikFace &position);
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

    Corner corner_position[8];
    Edge edge_position[12];
    RubikFace center[6];
    CornerOrientation corner_orientation[8];
    EdgeOrientation edge_orientation[12];
};
