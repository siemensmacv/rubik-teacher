#pragma once
#include <iomanip>
#include <random>
#include <ctime>
#include <string>

template <class T>
class Cub_Rubik
{
	T** Front, Back, Up, Down, Left, Right;

public:
	Cub_Rubik(T **front, T **back, T **up, T **down, T **left, T **right)
		: Front{front}, Back{back}, Up{up}, Down{down}, Left{left}, Right{right}
	{}

private:
	inline void swap(T& a, T& b);
	inline T**& matr_clock(T**& m);
	inline T**& matr_counterclock(T**& m);
	inline void clock(T**& centru, T**& sus, T**& jos, T**& stanga, T**& dreapta);
	inline void counterclock(T**& centru, T**& sus, T**& jos, T**& stanga, T**& dreapta);
public:
	void frontClock();
	void frontCounterClock();
	void backClock();
	void backCounterClock();
	void upClock();
	void upCounterClock();
	void downClock();
	void downCounterClock();
	void leftClock();
	void leftCounterClock();
	void rightClock();
	void rightCounterClock();

	void xAxisClock();
	void xAxisCounterClock();
	void yAxisClock();
	void yAxisCounterClock();
	void zAxisClock();
	void zAxisCounterClock();

	void repozitionare_cub();//necesar??

};
