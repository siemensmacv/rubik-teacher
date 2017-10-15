#include "modelrubik_cornersedges.h"

CornerOrientation& operator++(CornerOrientation& variable, int)
{
	switch (variable)
	{
	case CornerOrientation::Normal:
		return variable = CornerOrientation::Clockwise;
	case CornerOrientation::Clockwise:
		return variable = CornerOrientation::CounterClockwise;
	case CornerOrientation::CounterClockwise:
		return variable = CornerOrientation::Normal;
    default:
        return variable = CornerOrientation::Normal;
	}
}

CornerOrientation& operator--(CornerOrientation& variable, int)
{
	switch (variable)
	{
	case CornerOrientation::Normal:
		return variable = CornerOrientation::CounterClockwise;
	case CornerOrientation::Clockwise:
		return variable = CornerOrientation::Normal;
	case CornerOrientation::CounterClockwise:
		return variable = CornerOrientation::Clockwise;
    default:
        return variable = CornerOrientation::Normal;
	}
}

EdgeOrientation& operator!(EdgeOrientation& variable)
{
	switch (variable)
	{
	case EdgeOrientation::Normal:
		return variable = EdgeOrientation::Flipped;
	case EdgeOrientation::Flipped:
		return variable = EdgeOrientation::Normal;
    default:
        return variable = EdgeOrientation::Normal;
	}
}

void ModelRubik_CornersEdges::init_corners()
{
	for (int i = 0; i < 8; ++i)
	{
		corner_orientation[i] = CornerOrientation::Normal;
        corner_position[i] = static_cast<Corner>(i);
	}
}

void ModelRubik_CornersEdges::init_edges()
{
	for (int i = 0; i < 12; ++i)
	{
		edge_orientation[i] = EdgeOrientation::Normal;
        edge_position[i] = static_cast<Edge>(i);
	}
}

void ModelRubik_CornersEdges::init_centers()
{
	for (int i = 0; i < 6; ++i)
	{
        center[i] = static_cast<RubikFace>(i);
	}
}


ModelRubik_CornersEdges::ModelRubik_CornersEdges()
{
	init_corners();
	init_edges();
}


ModelRubik_CornersEdges::~ModelRubik_CornersEdges()
{
}
