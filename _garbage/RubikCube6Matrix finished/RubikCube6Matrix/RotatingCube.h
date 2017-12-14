#pragma once
#include "IDeepMoves.h"
class RotatingCube :
	public IDeepMoves
{
protected:
	int m_size;

public:
	RotatingCube(int);
	~RotatingCube();

	void xAxisClock();
	void xAxisCounterClock();
	void yAxisClock();
	void yAxisCounterClock();
	void zAxisClock();
	void zAxisCounterClock();
};

