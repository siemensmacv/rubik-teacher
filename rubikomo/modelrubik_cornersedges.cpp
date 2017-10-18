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
        // rotate corners
        // rotate edges
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

void ModelRubik_CornersEdges::rotateCornersClockwise(int UL, int UR, int DR, int DL, const RubikFace &face)
{
    // change corner orientation
    if (face != RubikFace::Up && face != RubikFace::Down)
    {
        ++corner_orientation[UL];
        --corner_orientation[UR];
        ++corner_orientation[DR];
        --corner_orientation[DL];
    }

    // permutate corners positions
    Corner aux = corner_position[UL];
    corner_position[UL] = corner_position[DL];
    corner_position[DL] = corner_position[DR];
    corner_position[DR] = corner_position[UR];
    corner_position[UR] = aux;

    // permutate corners orientation
    CornerOrientation aux = corner_orientation[UL];
    corner_orientation[UL] = corner_orientation[DL];
    corner_orientation[DL] = corner_orientation[DR];
    corner_orientation[DR] = corner_orientation[UR];
    corner_orientation[UR] = aux;

}

void ModelRubik_CornersEdges::rotateCornersCounterClockwise(int UR, int UL, int DL, int DR, const RubikFace &face)
{
    // change corner orientation
    if (face != RubikFace::Up && face != RubikFace::Down)
    {
        ++corner_orientation[UL];
        --corner_orientation[UR];
        ++corner_orientation[DR];
        --corner_orientation[DL];
    }

    // permutate corners positions
    Corner aux = corner_position[UR];
    corner_position[UR] = corner_position[DR];
    corner_position[DR] = corner_position[DL];
    corner_position[DL] = corner_position[UL];
    corner_position[UL] = aux;

    // permutate corners orientation
    CornerOrientation aux = corner_orientation[UR];
    corner_orientation[UR] = corner_orientation[DR];
    corner_orientation[DR] = corner_orientation[DL];
    corner_orientation[DL] = corner_orientation[UL];
    corner_orientation[UL] = aux;
}

void ModelRubik_CornersEdges::rotateEdgesClockwise(int up, int right, int down, int left, const RubikFace &face)
{
    //change edge orientation
    switch (face) {
    case RubikFace::Left:
    case RubikFace::Right:
        if (edgeValueInMiddleSlice(up))
            !edge_orientation[up];
        if (edgeValueInMiddleSlice(right))
            !edge_orientation[right];
        if (edgeValueInMiddleSlice(down))
            !edge_orientation[down];
        if (edgeValueInMiddleSlice(left))
            !edge_orientation[left];
        break;

    case RubikFace::Front:
    case RubikFace::Back:
        if (edgeValueInStandingSlice(up))
            !edge_orientation[up];
        if (edgeValueInStandingSlice(right))
            !edge_orientation[right];
        if (edgeValueInStandingSlice(down))
            !edge_orientation[down];
        if (edgeValueInStandingSlice(left))
            !edge_orientation[left];
        break;

    case RubikFace::Up:
    case RubikFace::Down:
        if (edgeValueInEquatorSlice(up))
            !edge_orientation[up];
        if (edgeValueInEquatorSlice(right))
            !edge_orientation[right];
        if (edgeValueInEquatorSlice(down))
            !edge_orientation[down];
        if (edgeValueInEquatorSlice(left))
            !edge_orientation[left];
        break;

    default:
        break;
    }

    //permutate edges positions
    Edge aux = edge_position[up];
    edge_position[up] = edge_position[left];
    edge_position[left] = edge_position[down];
    edge_position[down] = edge_position[right];
    edge_position[right] = aux;

    //permutate edges orientation
    EdgeOrientation aux = edge_orientation[up];
    edge_orientation[up] = edge_orientation[left];
    edge_orientation[left] = edge_orientation[down];
    edge_orientation[down] = edge_orientation[right];
    edge_orientation[right] = aux;
}

void ModelRubik_CornersEdges::rotateEdgesCounterClockwise(int up, int right, int down, int left, const RubikFace &face)
{
    //change edge orientation
    switch (face) {
    case RubikFace::Left:
    case RubikFace::Right:
        if (edgeValueInMiddleSlice(up))
            !edge_orientation[up];
        if (edgeValueInMiddleSlice(right))
            !edge_orientation[right];
        if (edgeValueInMiddleSlice(down))
            !edge_orientation[down];
        if (edgeValueInMiddleSlice(left))
            !edge_orientation[left];
        break;

    case RubikFace::Front:
    case RubikFace::Back:
        if (edgeValueInStandingSlice(up))
            !edge_orientation[up];
        if (edgeValueInStandingSlice(right))
            !edge_orientation[right];
        if (edgeValueInStandingSlice(down))
            !edge_orientation[down];
        if (edgeValueInStandingSlice(left))
            !edge_orientation[left];
        break;

    case RubikFace::Up:
    case RubikFace::Down:
        if (edgeValueInEquatorSlice(up))
            !edge_orientation[up];
        if (edgeValueInEquatorSlice(right))
            !edge_orientation[right];
        if (edgeValueInEquatorSlice(down))
            !edge_orientation[down];
        if (edgeValueInEquatorSlice(left))
            !edge_orientation[left];
        break;

    default:
        break;
    }

    //permutate edges positions
    Edge aux = edge_position[up];
    edge_position[up] = edge_position[right];
    edge_position[right] = edge_position[down];
    edge_position[down] = edge_position[left];
    edge_position[left] = aux;

    //permutate edges orientation
    EdgeOrientation aux = edge_orientation[up];
    edge_orientation[up] = edge_orientation[right];
    edge_orientation[right] = edge_orientation[down];
    edge_orientation[down] = edge_orientation[left];
    edge_orientation[left] = aux;

}



