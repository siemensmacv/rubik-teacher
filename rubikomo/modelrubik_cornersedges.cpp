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

ModelRubik_CornersEdges::ModelRubik_CornersEdges()
{
    init_corners();
    init_edges();
    init_centers();
}

ModelRubik_CornersEdges::~ModelRubik_CornersEdges()
{
}

void ModelRubik_CornersEdges::rotateClockwise(const RubikFace &face)
{
    switch(face)
    {
    case RubikFace::Back:
        rotateBackClockwise();
        break;
    case RubikFace::Down:
        rotateDownClockwise();
        break;
    case RubikFace::Front:
        rotateFrontClockwise();
        break;
    case RubikFace::Left:
        rotateLeftClockwise();
        break;
    case RubikFace::Right:
        rotateRightClockwise();
        break;
    case RubikFace::Up:
        rotateUpClockwise();
        break;
    }
}

void ModelRubik_CornersEdges::rotateCounterClockwise(const RubikFace &face)
{
    switch(face)
    {
    case RubikFace::Back:
        rotateBackCounterClockwise();
        break;
    case RubikFace::Down:
        rotateDownCounterClockwise();
        break;
    case RubikFace::Front:
        rotateFrontCounterClockwise();
        break;
    case RubikFace::Left:
        rotateLeftCounterClockwise();
        break;
    case RubikFace::Right:
        rotateRightCounterClockwise();
        break;
    case RubikFace::Up:
        rotateUpCounterClockwise();
        break;
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

void ModelRubik_CornersEdges::rotateFaceClockwise(int UL, int UR, int DR, int DL, const RubikFace &face)
{
    // change corner orientation if
    // permutate corners positions
    // permutate corners orientation

    //change edge orientation if
    //permutate edges positions
    //permutate edges orientation
}



