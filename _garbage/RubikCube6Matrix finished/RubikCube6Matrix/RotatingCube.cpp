#include "RotatingCube.h"

RotatingCube::RotatingCube(int cubeSize) 
	: m_size{ cubeSize }
{
}

RotatingCube::~RotatingCube()
{
}

void RotatingCube::xAxisClock()
{
	rightClock_Deep(m_size);
}

void RotatingCube::xAxisCounterClock()
{
	rightCounterClock_Deep(m_size);
}

void RotatingCube::yAxisClock()
{
	upClock_Deep(m_size);
}

void RotatingCube::yAxisCounterClock()
{
	upCounterClock_Deep(m_size);
}

void RotatingCube::zAxisClock()
{
	frontClock_Deep(m_size);
}

void RotatingCube::zAxisCounterClock()
{
	frontCounterClock_Deep(m_size);
}