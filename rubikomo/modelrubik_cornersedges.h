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
	void init_corners();
	void init_edges();
	void init_centers();
private:
    Corner corner_position[8];
    Edge edge_position[12];
    RubikFace center[6];
    CornerOrientation corner_orientation[8];
    EdgeOrientation edge_orientation[12];
};
