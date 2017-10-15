#pragma once
#include <string>
#include <cstdlib>

#define FACELET_COUNT 54
#define CORNER_COUNT 8
#define EDGE_COUNT 12

class RubikValidator
{
private:

	/************************************************************************************************************************************************/

	//defining a facelet
	typedef enum {
		U1, U2, U3, U4, U5, U6, U7, U8, U9, R1, R2, R3, R4, R5, R6, R7, R8, R9, F1, F2, F3, F4, F5, F6, F7, F8, F9, D1, D2, D3, D4, D5, D6, D7, D8, D9, L1, L2, L3, L4, L5, L6, L7, L8, L9, B1, B2, B3, B4, B5, B6, B7, B8, B9
	} facelet_t;

	facelet_t cornerFacelet[8][3] = { { U9, R1, F3 },{ U7, F1, L3 },{ U1, L1, B3 },{ U3, B1, R3 },
	{ D3, F9, R7 },{ D1, L9, F7 },{ D7, B9, L7 },{ D9, R9, B7 } };

	facelet_t edgeFacelet[12][2] = { { U6, R2 },{ U8, F2 },{ U4, L2 },{ U2, B2 },{ D6, R8 },{ D2, F8 },
	{ D4, L8 },{ D8, B8 },{ F6, R4 },{ F4, L6 },{ B6, L4 },{ B4, R6 } };

	/**************************************************************************************************************************************************/

	//defining colors
	typedef enum { U, R, F, D, L, B } color_t;

	color_t cornerColor[8][3] = { { U, R, F },{ U, F, L },{ U, L, B },{ U, B, R },{ D, F, R },{ D, L, F },
	{ D, B, L },{ D, R, B } };

	color_t edgeColor[12][2] = { { U, R },{ U, F },{ U, L },{ U, B },{ D, R },{ D, F },{ D, L },{ D, B },
	{ F, R },{ F, L },{ B, L },{ B, R } };

	struct facecube {
		color_t f[54];
	};
	typedef struct facecube facecube_t;

	/***********************************************************************************************************************************************************/
	
	//defining cubiecube
	typedef enum {
		URF, UFL, ULB, UBR, DFR, DLF, DBL, DRB
	} corner_t;

	typedef enum {
		UR, UF, UL, UB, DR, DF, DL, DB, FR, FL, BL, BR
	} edge_t;

	struct cubiecube {
		// initialize to Id-Cube
		// corner permutation
		corner_t cp[8];
		// corner orientation
		signed char co[8];
		// edge permutation
		edge_t ep[12];
		// edge orientation
		signed char eo[12];
	};

	typedef struct cubiecube cubiecube_t;

	/************************************************************************************************************************************************/

	//private functions
	short edgeParity(cubiecube_t* cubiecube);
	short cornerParity(cubiecube_t* cubiecube);

	//private members
	std::string _cubeString;
	struct cubiecube* _rubikCubieCube = nullptr;


public:
	RubikValidator(std::string cubeString);
	~RubikValidator();

	bool operator ()();

};