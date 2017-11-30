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

void ModelRubik_CornersEdges::rotateFaceClockwise(const RubikFace &face)
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

void ModelRubik_CornersEdges::rotateFaceCounterClockwise(const RubikFace &face)
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

Corner ModelRubik_CornersEdges::getCorner(const Corner &position) const
{
    return corner_position[static_cast<int>(position)];
}

CornerOrientation ModelRubik_CornersEdges::getCornerOrientation(const Corner &position) const
{
    return corner_orientation[static_cast<int>(position)];
}

Edge ModelRubik_CornersEdges::getEdge(const Edge &position) const
{
    return edge_position[static_cast<int>(position)];
}

EdgeOrientation ModelRubik_CornersEdges::getEdgeOrientation(const Edge &position) const
{
    return edge_orientation[static_cast<int>(position)];
}

RubikFace ModelRubik_CornersEdges::getCenter(const RubikFace &position) const
{
    return center[static_cast<int>(position)];
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
        corner_orientation[UL]++;
        corner_orientation[UR]--;
        corner_orientation[DR]++;
        corner_orientation[DL]--;
    }

    // permutate corners positions
    Corner aux = corner_position[UL];
    corner_position[UL] = corner_position[DL];
    corner_position[DL] = corner_position[DR];
    corner_position[DR] = corner_position[UR];
    corner_position[UR] = aux;

    // permutate corners orientation
    CornerOrientation aux2 = corner_orientation[UL];
    corner_orientation[UL] = corner_orientation[DL];
    corner_orientation[DL] = corner_orientation[DR];
    corner_orientation[DR] = corner_orientation[UR];
    corner_orientation[UR] = aux2;

}

void ModelRubik_CornersEdges::rotateCornersCounterClockwise(int UR, int UL, int DL, int DR, const RubikFace &face)
{
    // change corner orientation
    if (face != RubikFace::Up && face != RubikFace::Down)
    {
        corner_orientation[UL]++;
        corner_orientation[UR]--;
        corner_orientation[DR]++;
        corner_orientation[DL]--;
    }

    // permutate corners positions
    Corner aux = corner_position[UR];
    corner_position[UR] = corner_position[DR];
    corner_position[DR] = corner_position[DL];
    corner_position[DL] = corner_position[UL];
    corner_position[UL] = aux;

    // permutate corners orientation
    CornerOrientation aux2 = corner_orientation[UR];
    corner_orientation[UR] = corner_orientation[DR];
    corner_orientation[DR] = corner_orientation[DL];
    corner_orientation[DL] = corner_orientation[UL];
    corner_orientation[UL] = aux2;
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
    EdgeOrientation aux2 = edge_orientation[up];
    edge_orientation[up] = edge_orientation[left];
    edge_orientation[left] = edge_orientation[down];
    edge_orientation[down] = edge_orientation[right];
    edge_orientation[right] = aux2;
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
    EdgeOrientation aux2 = edge_orientation[up];
    edge_orientation[up] = edge_orientation[right];
    edge_orientation[right] = edge_orientation[down];
    edge_orientation[down] = edge_orientation[left];
    edge_orientation[left] = aux2;

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
    return edge_position[index] == Edge::FL
        || edge_position[index] == Edge::RF
        || edge_position[index] == Edge::BR
        || edge_position[index] == Edge::LB;
}

bool ModelRubik_CornersEdges::edgeValueInStandingSlice(int index)
{
    return edge_position[index] == Edge::UR
        || edge_position[index] == Edge::UL
        || edge_position[index] == Edge::DL
        || edge_position[index] == Edge::DR;
}

std::string ModelRubik_CornersEdges::permutateStringForward(std::string input)
{
    return std::string() + input[input.length() - 1] + input.substr(0, input.length() - 1);
}

void ModelRubik_CornersEdges::setCornersEdges(std::string input)
{
    std::string corners[8] = {
        std::string() + input[2] + input[45] + input[11],
        std::string() + input[8] + input[9] + input[20],
        std::string() + input[6] + input[18] + input[38],
        std::string() + input[0] + input[36] + input[47],
        std::string() + input[35] + input[17] + input[51],
        std::string() + input[29] + input[26] + input[15],
        std::string() + input[27] + input[44] + input[24],
        std::string() + input[33] + input[53] + input[42]
    };

    std::string edges[12] = {
        std::string() + input[1] + input[46],
        std::string() + input[5] + input[10],
        std::string() + input[7] + input[19],
        std::string() + input[3] + input[37],
        std::string() + input[48] + input[14],
        std::string() + input[12] + input[23],
        std::string() + input[21] + input[41],
        std::string() + input[39] + input[50],
        std::string() + input[34] + input[52],
        std::string() + input[32] + input[16],
        std::string() + input[28] + input[25],
        std::string() + input[30] + input[43]
    };

    CornerOrientation corners_orientation[8] = {
        CornerOrientation::Normal,
        CornerOrientation::Normal,
        CornerOrientation::Normal,
        CornerOrientation::Normal,
        CornerOrientation::Normal,
        CornerOrientation::Normal,
        CornerOrientation::Normal,
        CornerOrientation::Normal
    };
    EdgeOrientation edges_orientation[12] = {
        EdgeOrientation::Normal,
        EdgeOrientation::Normal,
        EdgeOrientation::Normal,
        EdgeOrientation::Normal,
        EdgeOrientation::Normal,
        EdgeOrientation::Normal,
        EdgeOrientation::Normal,
        EdgeOrientation::Normal,
        EdgeOrientation::Normal,
        EdgeOrientation::Normal,
        EdgeOrientation::Normal,
        EdgeOrientation::Normal
    };

    for(int pos=0; pos<8; ++pos)
    {
        auto it = std::find_if(proper_corners.begin(),
                               proper_corners.end(),
                               [&corners, &pos](std::string str){return str == corners[pos];}
        );

        while(it == proper_corners.end())
        {
            corners[pos] = permutateStringForward(corners[pos]);
            corners_orientation[pos]++;
            it = std::find_if(proper_corners.begin(),
                                           proper_corners.end(),
                                           [&corners, &pos](std::string str){return str == corners[pos];}
            );
        }

        corner_position[pos] = static_cast<Corner>(std::distance(proper_corners.begin(), it));
        corner_orientation[pos] = corner_orientation[pos];
    }

    for(int pos=0; pos<12; ++pos)
    {
        auto it = std::find_if(proper_edges.begin(),
                               proper_edges.end(),
                               [&edges, &pos](std::string str){return str == edges[pos];}
        );

        while(it == proper_edges.end())
        {
            edges[pos] = permutateStringForward(edges[pos]);
            edges_orientation[pos] = !edges_orientation[pos];
            it = std::find_if(proper_edges.begin(),
                              proper_edges.end(),
                              [&edges, &pos](std::string str){return str == edges[pos];}
            );
        }

        edge_position[pos] = static_cast<Edge>(std::distance(proper_edges.begin(), it));
        edge_orientation[pos] = edges_orientation[pos];
    }
}


void ModelRubik_CornersEdges::cornerToString(int index, char* result)
{
    Corner corner = corner_position[index];
    switch (corner)
    {
    case Corner::URF: result[0] = 'U'; result[1] = 'R'; result[2] = 'F'; break;
    case Corner::UFL: result[0] = 'U'; result[1] = 'F'; result[2] = 'L'; break;
    case Corner::ULB: result[0] = 'U'; result[1] = 'L'; result[2] = 'B'; break;
    case Corner::UBR: result[0] = 'U'; result[1] = 'B'; result[2] = 'R'; break;
    case Corner::DFR: result[0] = 'D'; result[1] = 'F'; result[2] = 'R'; break;
    case Corner::DLF: result[0] = 'D'; result[1] = 'L'; result[2] = 'F'; break;
    case Corner::DBL: result[0] = 'D'; result[1] = 'B'; result[2] = 'L'; break;
    case Corner::DRB: result[0] = 'D'; result[1] = 'R'; result[2] = 'B'; break;
    }
    result[3] = '(';
    result[4] = (char)(static_cast<int>(corner_orientation[index]) + 48);
    result[5] = ')';
}

void ModelRubik_CornersEdges::edgeToString(int index, char* result)
{
    Edge edge = edge_position[index];
    switch (edge)
    {
    case Edge::UR: result[0] = 'U'; result[1] = 'R'; break;
    case Edge::UF: result[0] = 'U'; result[1] = 'F'; break;
    case Edge::UL: result[0] = 'U'; result[1] = 'L'; break;
    case Edge::UB: result[0] = 'U'; result[1] = 'B'; break;
    case Edge::DR: result[0] = 'D'; result[1] = 'R'; break;
    case Edge::DF: result[0] = 'D'; result[1] = 'F'; break;
    case Edge::DL: result[0] = 'D'; result[1] = 'L'; break;
    case Edge::DB: result[0] = 'D'; result[1] = 'B'; break;
    case Edge::RF: result[0] = 'R'; result[1] = 'F'; break;
    case Edge::FL: result[0] = 'F'; result[1] = 'L'; break;
    case Edge::LB: result[0] = 'L'; result[1] = 'B'; break;
    case Edge::BR: result[0] = 'B'; result[1] = 'R'; break;
    }
    result[2] = '(';
    result[3] = (char)(static_cast<int>(edge_orientation[index]) + 48);
    result[4] = ')';
}

#define SIZE_CORNER_DESC 6
#define SIZE_EDGE_DESC 5
#define CORNER_COUNT 8
#define EDGE_COUNT 12

void ModelRubik_CornersEdges::toString(char* result)
{
    int index = 0;
    result[index++] = 'C';
    result[index++] = ':';
    result[index++] = ' ';
    char cornerDesc[SIZE_CORNER_DESC];
    for (int i = 0; i < CORNER_COUNT; i++)
    {
        cornerToString( i, cornerDesc);
        for (int j = 0; j < SIZE_CORNER_DESC; j++)
            result[index + j] = cornerDesc[j];
        index += SIZE_CORNER_DESC;
        result[index++] = ',';
    }
    // filling edges
    result[index++] = 'E';
    result[index++] = ':';
    result[index++] = ' ';
    char edgeDesc[SIZE_EDGE_DESC];
    for (int i = 0; i < EDGE_COUNT; i++)
    {
        edgeToString(i, edgeDesc);
        for (int j = 0; j < SIZE_CORNER_DESC; j++)
            result[index + j] = edgeDesc[j];
        index += SIZE_EDGE_DESC;
        result[index++] = ',';
    }
}

void insertChar(char* buffer, char c, int *index, int count)
{
    for (int i = 0; i < count; i++)
        buffer[*index + i] = c;
    *index += count;
}

void insertSpaceDashSpace(char* buffer, int *index)
{
    buffer[(*index)++] = ' ';
    buffer[(*index)++] = '-';
    buffer[(*index)++] = ' ';
}

void ModelRubik_CornersEdges::to3DString2(char** resultArray)
{
    int index;
    char* result;

    //line 0
    index = 0;
    result = resultArray[0] = (char*)malloc(50);
    insertChar(result, ' ', &index, 4);
    cornerToString( 3, result + index);
    index += SIZE_CORNER_DESC;
    insertSpaceDashSpace(result, &index);
    edgeToString(0, result + index);
    index += SIZE_EDGE_DESC;
    insertSpaceDashSpace(result, &index);
    cornerToString( 0, result + index);
    index += SIZE_CORNER_DESC;
    result[index] = '\0';

    //line 1
    index = 0;
    result = resultArray[1] = (char*)malloc(50);
    insertChar(result, ' ', &index, 5);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';

    //line 2
    index = 0;
    result = resultArray[2] = (char*)malloc(50);
    insertChar(result, ' ', &index, 2);
    edgeToString(3, result + index);
    index += SIZE_EDGE_DESC;
    insertChar(result, ' ', &index, 23);
    edgeToString(1, result + index);
    index += SIZE_EDGE_DESC;
    result[index] = '\0';


    //line 3
    index = 0;
    result = resultArray[3] = (char*)malloc(50);
    insertChar(result, ' ', &index, 2);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';

    //line 4
    index = 0;
    result = resultArray[4] = (char*)malloc(50);
    cornerToString( 2, result + index);
    index += SIZE_CORNER_DESC;
    insertSpaceDashSpace(result, &index);
    edgeToString(2, result + index);
    index += SIZE_EDGE_DESC;
    insertSpaceDashSpace(result, &index);
    cornerToString( 1, result + index);
    index += SIZE_CORNER_DESC;
    result[index] = '\0';

    //line 5
    index = 0;
    result = resultArray[5] = (char*)malloc(50);
    insertChar(result, ' ', &index, 1);
    result[index] = '\0';

    //line 6
    index = 0;
    result = resultArray[6] = (char*)malloc(50);
    insertChar(result, ' ', &index, 4);
    edgeToString(7, result + index);
    index += SIZE_EDGE_DESC;
    insertChar(result, '-', &index, 18);
    edgeToString(4, result + index);
    index += SIZE_EDGE_DESC;
    result[index] = '\0';

    //line 7
    index = 0;
    result = resultArray[7] = (char*)malloc(50);
    insertChar(result, ' ', &index, 4);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';

    //line 8
    index = 0;
    result = resultArray[8] = (char*)malloc(50);
    insertChar(result, ' ', &index, 3);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';


    //line 9
    index = 0;
    result = resultArray[9] = (char*)malloc(50);
    insertChar(result, ' ', &index, 2);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';

    //line 10
    index = 0;
    result = resultArray[10] = (char*)malloc(50);
    insertChar(result, ' ', &index, 1);
    edgeToString(6, result + index);
    index += SIZE_EDGE_DESC;
    insertChar(result, '-', &index, 18);
    edgeToString(5, result + index);
    index += SIZE_EDGE_DESC;
    result[index] = '\0';

    //line 11
    index = 0;
    result = resultArray[11] = (char*)malloc(50);
    insertChar(result, ' ', &index, 1);
    result[index] = '\0';


    //line 12
    index = 0;
    result = resultArray[12] = (char*)malloc(50);
    insertChar(result, ' ', &index, 4);
    cornerToString( 7, result + index);
    index += SIZE_CORNER_DESC;
    insertSpaceDashSpace(result, &index);
    edgeToString(8, result + index);
    index += SIZE_EDGE_DESC;
    insertSpaceDashSpace(result, &index);
    cornerToString( 4, result + index);
    index += SIZE_CORNER_DESC;
    result[index] = '\0';

    //line 13
    index = 0;
    result = resultArray[13] = (char*)malloc(50);
    insertChar(result, ' ', &index, 5);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';

    //line 14
    index = 0;
    result = resultArray[14] = (char*)malloc(50);
    insertChar(result, ' ', &index, 2);
    edgeToString(11, result + index);
    index += SIZE_EDGE_DESC;
    insertChar(result, ' ', &index, 23);
    edgeToString(9, result + index);
    index += SIZE_EDGE_DESC;
    result[index] = '\0';


    //line 15
    index = 0;
    result = resultArray[15] = (char*)malloc(50);
    insertChar(result, ' ', &index, 2);
    result[index++] = '/';
    insertChar(result, ' ', &index, 30);
    result[index++] = '/';
    result[index] = '\0';

    //line 16
    index = 0;
    result = resultArray[16] = (char*)malloc(50);
    cornerToString( 6, result + index);
    index += SIZE_CORNER_DESC;
    insertSpaceDashSpace(result, &index);
    edgeToString(10, result + index);
    index += SIZE_EDGE_DESC;
    insertSpaceDashSpace(result, &index);
    cornerToString( 5, result + index);
    index += SIZE_CORNER_DESC;
    result[index] = '\0';
}
