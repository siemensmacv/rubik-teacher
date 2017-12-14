#ifndef RUBIKEDGE_H
#define RUBIKEDGE_H

#include <array>
#include <string>

enum class EdgeOrientation
{
	Normal,
	Flipped
};

enum class Edge
{
	UB,
	UR,
	UF,
	UL,
	BR,
	RF,
	FL,
	LB,
	DB,
	DR,
	DF,
	DL
};

static const std::array<std::string, 12> proper_edges = {"UB", "UR", "UF", "UL", "BR", "RF", "FL", "LB", "DB", "DR", "DF", "DL"};

#endif // RUBIKEDGE_H
