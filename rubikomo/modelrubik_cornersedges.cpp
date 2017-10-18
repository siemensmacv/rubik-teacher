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
        rotateCornersClockwise(0, 3, 7, 4, face);
        rotateEdgesClockwise(0, 7, 8, 4, face);
        break;
    case RubikFace::Down:
        rotateCornersClockwise(6, 5, 4, 7, face);
        rotateEdgesClockwise(10, 9, 8, 11, face);
        break;
    case RubikFace::Front:
        rotateCornersClockwise(2, 1, 5, 6, face);
        rotateEdgesClockwise(2, 5, 10, 6, face);
        break;
    case RubikFace::Left:
        rotateCornersClockwise(3, 2, 6, 7, face);
        rotateEdgesClockwise(3, 6, 11, 7, face);
        break;
    case RubikFace::Right:
        rotateCornersClockwise(1, 0, 4, 5, face);
        rotateEdgesClockwise(1, 4, 9, 5, face);
        break;
    case RubikFace::Up:
        rotateCornersClockwise(3, 0, 1, 2, face);
        rotateEdgesClockwise(0, 1, 2, 3, face);
        break;
    }
}

void ModelRubik_CornersEdges::rotateCounterClockwise(const RubikFace &face)
{
    switch(face)
    {
    case RubikFace::Back:
        rotateCornersCounterClockwise(3, 0, 4, 7, face);
        rotateEdgesCounterClockwise(0, 4, 8, 7, face);
        break;
    case RubikFace::Down:
        rotateCornersCounterClockwise(5, 6, 7, 4, face);
        rotateEdgesCounterClockwise(10, 11, 8, 9, face);
        break;
    case RubikFace::Front:
        rotateCornersCounterClockwise(1, 2, 6, 5, face);
        rotateEdgesCounterClockwise(2, 6, 10, 5, face);
        break;
    case RubikFace::Left:
        rotateCornersCounterClockwise(2, 3, 7, 6, face);
        rotateEdgesCounterClockwise(3, 7, 11, 6, face);
        break;
    case RubikFace::Right:
        rotateCornersCounterClockwise(0, 1, 5, 4, face);
        rotateEdgesCounterClockwise(1, 5, 9, 4, face);
        break;
    case RubikFace::Up:
        rotateCornersCounterClockwise(0, 3, 2, 1, face);
        rotateEdgesCounterClockwise(0, 3, 2, 1, face);
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

void ModelRubik_CornersEdges::rotateEdgesCounterClockwise(int up, int left, int down, int right, const RubikFace &face)
{
    //change edge orientation
    switch (face) {
    case RubikFace::Left:
    case RubikFace::Right:
        if (edgeValueInMiddleSlice(up))
            !edge_orientation[up];
        if (edgeValueInMiddleSlice(left))
            !edge_orientation[left];
        if (edgeValueInMiddleSlice(down))
            !edge_orientation[down];
        if (edgeValueInMiddleSlice(right))
            !edge_orientation[right];
        break;

    case RubikFace::Front:
    case RubikFace::Back:
        if (edgeValueInStandingSlice(up))
            !edge_orientation[up];
        if (edgeValueInStandingSlice(left))
            !edge_orientation[left];
        if (edgeValueInStandingSlice(down))
            !edge_orientation[down];
        if (edgeValueInStandingSlice(right))
            !edge_orientation[right];
        break;

    case RubikFace::Up:
    case RubikFace::Down:
        if (edgeValueInEquatorSlice(up))
            !edge_orientation[up];
        if (edgeValueInEquatorSlice(left))
            !edge_orientation[left];
        if (edgeValueInEquatorSlice(down))
            !edge_orientation[down];
        if (edgeValueInEquatorSlice(right))
            !edge_orientation[right];
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

bool ModelRubik_CornersEdges::edgeValueInMiddleSlice(int index)
{
    return edge_position[index] == Edge::UF
        || edge_position[index] == Edge::DF
        || edge_position[index] == Edge::DB
        || edge_position[index] == Edge::UB;
}

bool ModelRubik_CornersEdges::edgeValueInEquatorSlice(int index)
{
    return edge_position[index] == Edge::UR
        || edge_position[index] == Edge::UL
        || edge_position[index] == Edge::DL
        || edge_position[index] == Edge::DR;
}

bool ModelRubik_CornersEdges::edgeValueInStandingSlice(int index)
{
    return edge_position[index] == Edge::FL
        || edge_position[index] == Edge::RF
        || edge_position[index] == Edge::BR
        || edge_position[index] == Edge::LB;
}



