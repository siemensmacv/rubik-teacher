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

    void rotateClockwise(const RubikFace &face);
    void rotateCounterClockwise(const RubikFace &face);

    Corner getCorner(const Corner &position);
    CornerOrientation getCornerOrientation(const Corner &position);

    Edge getEdge(const Edge &position);
    EdgeOrientation getEdgeOrientation(const Edge &position);

    RubikFace getCenter(const RubikFace &position);
private:
	void init_corners();
	void init_edges();
	void init_centers();

    void rotateFaceClockwise(int UL, int UR, int DR, int DL, const RubikFace &face);
    void rotateFaceCounterClockwise(int UR, int UL, int DL, int DR, const RubikFace &face);

    Corner corner_position[8];
    Edge edge_position[12];
    RubikFace center[6];
    CornerOrientation corner_orientation[8];
    EdgeOrientation edge_orientation[12];
};
