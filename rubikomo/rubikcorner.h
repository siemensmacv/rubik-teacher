#pragma once
#include <string>
#include <array>

enum class Corner
{
	UBR,
	URF,
	UFL,
	ULB,
	DRB,
	DFR,
	DLF,
	DBL
};

enum class CornerOrientation
{
	Normal,
	Clockwise,
	CounterClockwise
};

static const std::array<std::string, 8> proper_corners = {"UBR", "URF", "UFL", "ULB", "DRB", "DFR", "DLF", "DBL"};
