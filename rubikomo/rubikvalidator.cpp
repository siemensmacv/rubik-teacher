#include "rubikvalidator.h"

RubikValidator::RubikValidator(std::string cubeString):_cubeString(cubeString)
{
	//transforming cubeString to facecube_t
	facecube_t* res = (facecube_t *)calloc(1, sizeof(facecube_t)); 
	for (int i = 0; i < 54; i++) { 
		switch (cubeString[i]) {
		case 'U':
			res->f[i] = U;
			break;
		case 'R':
			res->f[i] = R;
			break;
		case 'F':
			res->f[i] = F;
			break;
		case 'D':
			res->f[i] = D;
			break;
		case 'L':
			res->f[i] = L;
			break;
		case 'B':
			res->f[i] = B;
			break;
		}
	}

	//transforming from facecube_t to cubiecube_t
	signed char ori;
	cubiecube_t* ccRet = (cubiecube_t*)calloc(1, sizeof(cubiecube_t));
	for (int i = 0; i < 8; i++)
		ccRet->cp[i] = URF;// invalidate corners
	for (int i = 0; i < 12; i++)
		ccRet->ep[i] = UR;// and edges
	color_t col1, col2;
	for (int i = 0; i < CORNER_COUNT; i++) {
		// get the colors of the cubie at corner i, starting with U/D
		for (ori = 0; ori < 3; ori++)
			if (res->f[cornerFacelet[i][ori]] == U || res->f[cornerFacelet[i][ori]] == D)
				break;
		col1 = res->f[cornerFacelet[i][(ori + 1) % 3]];
		col2 = res->f[cornerFacelet[i][(ori + 2) % 3]];

		for (int j = 0; j < CORNER_COUNT; j++) {
			if (col1 == cornerColor[j][1] && col2 == cornerColor[j][2]) {
				// in cornerposition i we have cornercubie j
				ccRet->cp[i] = (corner_t)j;
				ccRet->co[i] = ori % 3;
				break;
			}
		}
	}

	for (int i = 0; i < EDGE_COUNT; i++) {
		for (int j = 0; j < EDGE_COUNT; j++) {
			if (res->f[edgeFacelet[i][0]] == edgeColor[j][0]
				&& res->f[edgeFacelet[i][1]] == edgeColor[j][1]) {
				ccRet->ep[i] = (edge_t)j;
				ccRet->eo[i] = 0;
				break;
			}
			if (res->f[edgeFacelet[i][0]] == edgeColor[j][1]
				&& res->f[edgeFacelet[i][1]] == edgeColor[j][0]) {
				ccRet->ep[i] = (edge_t)j;
				ccRet->eo[i] = 1;
				break;
			}
		}
	}


	if (_rubikCubieCube)
		free(_rubikCubieCube);
    _rubikCubieCube = ccRet;
	free(res);
}

RubikValidator::~RubikValidator()
{
	if (_rubikCubieCube)
		free(_rubikCubieCube);
}

short RubikValidator::edgeParity(cubiecube_t* cubiecube)
{
	int s = 0;
	for (int i = BR; i >= UR + 1; i--)
		for (int j = i - 1; j >= UR; j--)
			if (cubiecube->ep[j] > cubiecube->ep[i])
				s++;
	return (short)(s % 2);
}

short RubikValidator::cornerParity(cubiecube_t* cubiecube)
{
	int s = 0;
	for (int i = DRB; i >= URF + 1; i--)
		for (int j = i - 1; j >= URF; j--)
			if (cubiecube->cp[j] > cubiecube->cp[i])
				s++;
	return (short)(s % 2);
}

bool RubikValidator::operator() ()
{
    // check for modified centers
    if(_cubeString[4] != 'U' || _cubeString[13] != 'R' || _cubeString[22] != 'F' || _cubeString[31] != 'D' || _cubeString[40] != 'L' || _cubeString[49] != 'B')
        return false;

	int count[6] = { 0 };

	for (int i = 0; i < 54; i++)
		switch (_cubeString[i]) {
		case 'U':
			count[U]++;
			break;
		case 'R':
			count[R]++;
			break;
		case 'F':
			count[F]++;
			break;
		case 'D':
			count[D]++;
			break;
		case 'L':
			count[L]++;
			break;
		case 'B':
			count[B]++;
			break;
		}

	for (int i = 0; i < 6; i++)
		if (count[i] != 9) {
			return false;
		}



	int sum = 0;
	int edgeCount[12] = { 0 };
	for (int e = 0; e < EDGE_COUNT; e++)
		edgeCount[_rubikCubieCube->ep[e]]++;
	for (int i = 0; i < 12; i++)
		if (edgeCount[i] != 1)
			return false;

	for (int i = 0; i < 12; i++)
		sum += _rubikCubieCube->eo[i];
	if (sum % 2 != 0)
		return false;

	int cornerCount[8] = { 0 };
	for (int c = 0; c < CORNER_COUNT; c++)
		cornerCount[_rubikCubieCube->cp[c]]++;
	for (int i = 0; i < 8; i++)
		if (cornerCount[i] != 1)
			return false;// missing corners

	sum = 0;
	for (int i = 0; i < 8; i++)
		sum += _rubikCubieCube->co[i];
	if (sum % 3 != 0)
		return false;// twisted corner

	if ((edgeParity(_rubikCubieCube) ^ cornerParity(_rubikCubieCube)) != 0)
		return false;// parity error

	return true;// cube ok
}
