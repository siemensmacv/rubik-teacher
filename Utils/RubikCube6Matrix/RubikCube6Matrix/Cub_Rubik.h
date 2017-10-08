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
	inline void swap(T& a, T& b)
	{
		T aux = a;
		a = b;
		b = aux;
	}

	inline T**& matr_clock(T**& matrix)
	{
		swap(matrix[0][0], matrix[0][2]);
		swap(matrix[0][0], matrix[2][2]);
		swap(matrix[0][0], matrix[2][0]);

		swap(matrix[0][1], matrix[1][2]);
		swap(matrix[0][1], matrix[2][1]);
		swap(matrix[0][1], matrix[1][0]);
		return matrix;
	}

	inline T**& matr_counterclock(T**& matrix)
	{
		swap(matrix[0][0], matrix[2][0]);
		swap(matrix[0][0], matrix[2][2]);
		swap(matrix[0][0], matrix[0][2]);

		swap(matrix[0][1], matrix[1][0]);
		swap(matrix[0][1], matrix[2][1]);
		swap(matrix[0][1], matrix[1][2]);
		return matrix;
	}

	inline void clock(T**& centre, T**& up, T**& down, T**& left, T**& right)
	{
		swap(up[2][0], right[0][0]);
		swap(up[2][0], down[0][2]);
		swap(up[2][0], left[2][2]);

		swap(up[2][1], right[1][0]);
		swap(up[2][1], down[0][1]);
		swap(up[2][1], left[1][2]);

		swap(up[2][2], right[2][0]);
		swap(up[2][2], down[0][0]);
		swap(up[2][2], left[0][2]);

		matr_clock(centre);
	}

	inline void counterclock(T**& centre, T**& up, T**& down, T**& left, T**& right)
	{
		swap(up[2][0], left[2][2]);
		swap(up[2][0], down[0][2]);
		swap(up[2][0], right[0][0]);

		swap(up[2][1], left[1][2]);
		swap(up[2][1], down[0][1]);
		swap(up[2][1], right[1][0]);

		swap(up[2][2], left[0][2]);
		swap(up[2][2], down[0][0]);
		swap(up[2][2], right[2][0]);

		matr_counterclock(centre);
	}

public:
	Cub_Rubik& frontClock()
	{
		clock(Front, Up, Down, Left, Right);
		return *this;
	}
	Cub_Rubik& frontCounterClock()
	{
		counterclock(Front, Up, Down, Left, Right);
		return *this;
	}
	Cub_Rubik& backClock()
	{
		matr_clock(matr_clock(Up));
		matr_clock(matr_clock(Down));
		clock(Back, Up, Down, Right, Left);
		matr_clock(matr_clock(Up));
		matr_clock(matr_clock(Down));
		return *this;
	}
	Cub_Rubik& backCounterClock()
	{
		matr_clock(matr_clock(Up));
		matr_clock(matr_clock(Down));
		counterclock(Back, Up, Down, Right, Left);
		matr_clock(matr_clock(Up));
		matr_clock(matr_clock(Down));
		return *this;
	}
	Cub_Rubik& upClock();
	Cub_Rubik& upCounterClock();
	Cub_Rubik& downClock();
	Cub_Rubik& downCounterClock();
	Cub_Rubik& leftClock();
	Cub_Rubik& leftCounterClock();
	Cub_Rubik& rightClock();
	Cub_Rubik& rightCounterClock();

	void xAxisClock();
	void xAxisCounterClock();
	void yAxisClock();
	void yAxisCounterClock();
	void zAxisClock();
	void zAxisCounterClock();

	void repozitionare_cub();//necesar??

};
