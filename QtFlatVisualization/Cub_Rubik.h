#pragma once

template <class T>
class Cub_Rubik
{
    T** Front = nullptr, Back = nullptr,
        Up = nullptr, Down = nullptr,
        Left = nullptr, Right = nullptr;

public:
    Cub_Rubik()	{}

    void setFront(T **front)
    {
        Front = front;
    }
    void setBack(T **back)
    {
        Back = back;
    }
    void setUp(T **up)
    {
        Up = up;
    }
    void setDown(T **down)
    {
        Down = down;
    }
    void setLeft(T **left)
    {
        Left = left;
    }
    void setRight(T **right)
    {
        Right = right;
    }

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
	void frontClock()
	{
		clock(Front, Up, Down, Left, Right);
	}
	void frontCounterClock()
	{
		counterclock(Front, Up, Down, Left, Right);
	}
	void backClock()
	{
		matr_clock(matr_clock(Up));
		matr_clock(matr_clock(Down));
		clock(Back, Up, Down, Right, Left);
		matr_clock(matr_clock(Up));
		matr_clock(matr_clock(Down));
	}
	void backCounterClock()
	{
		matr_clock(matr_clock(Up));
		matr_clock(matr_clock(Down));
		counterclock(Back, Up, Down, Right, Left);
		matr_clock(matr_clock(Up));
		matr_clock(matr_clock(Down));
	}
	void upClock()
	{
		matr_clock(matr_clock(Back));
		matr_clock(Left);
		matr_counterclock(Right);
		clock(Up, Back, Front, Left, Right);
		matr_clock(matr_clock(Back));
		matr_counterclock(Left);
		matr_clock(Right);
	}
	void upCounterClock()
	{
		matr_clock(matr_clock(Back));
		matr_clock(Left);
		matr_counterclock(Right);
		counterclock(Up, Back, Front, Left, Right);
		matr_clock(matr_clock(Back));
		matr_counterclock(Left);
		matr_clock(Right);
	}
	void downClock()
	{
		matr_clock(matr_clock(Back));
		matr_counterclock(Left);
		matr_clock(Right);
		clock(Down, Front, Back, Left, Right);
		matr_clock(matr_clock(Back));
		matr_clock(Left);
		matr_counterclock(Right);
	}
	void downCounterClock()
	{
		matr_clock(matr_clock(Back));
		matr_counterclock(Left);
		matr_clock(Right);
		counterclock(Down, Front, Back, Left, Right);
		matr_clock(matr_clock(Back));
		matr_clock(Left);
		matr_counterclock(Right);
	}
	void leftClock()
	{
		matr_counterclock(Up);
		matr_clock(Down);
		clock(Left, Up, Down, Back, Front);
		matr_clock(Up);
		matr_counterclock(Down);
	}
	void leftCounterClock()
	{
		matr_counterclock(Up);
		matr_clock(Down);
		counterclock(Left, Up, Down, Back, Front);
		matr_clock(Up);
		matr_counterclock(Down);
	}
	void rightClock()
	{
		matr_clock(Up);
		matr_counterclock(Down);
		clock(Right, Up, Down, Front, Back);
		matr_counterclock(Up);
		matr_clock(Down);
	}
	void rightCounterClock()
	{
		matr_clock(Up);
		matr_counterclock(Down);
		counterclock(Right, Up, Down, Front, Back);
		matr_counterclock(Up);
		matr_clock(Down);
	}

	void xAxisClock()
	{
		matr_clock(matr_clock(Up));
		matr_clock(matr_clock(Back));
		matr_counterclock(Left);
		matr_clock(Right);
		T **aux = Front;
		Front = Down;
		Down = Back;
		Back = Up;
		Up = aux;
	}
	void xAxisCounterClock()
	{
		matr_clock(matr_clock(Back));
		matr_clock(matr_clock(Down));
		matr_clock(Left);
		matr_counterclock(Right);
		T **aux = Front;
		Front = Up;
		Up = Back;
		Back = Down;
		Down = aux;
	}
	void yAxisClock()
	{
		matr_clock(Up);
		matr_counterclock(Down);
		T **aux = Front;
		Front = Right;
		Right = Back;
		Back = Left;
		Left = aux;
	}
	void yAxisCounterClock()
	{
		matr_counterclock(Up);
		matr_clock(Down);
		T **aux = Front;
		Front = Left;
		Left = Back;
		Back = Right;
		Right = aux;
	}
	void zAxisClock()
	{
		matr_clock(Front);
		matr_counterclock(Back);
		matr_clock(Left);
		matr_clock(Up);
		matr_clock(Right);
		matr_clock(Down);
		T **aux = Up;
		Up = Left;
		Left = Down;
		Down = Right;
		Right = aux;
	}
	void zAxisCounterClock()
	{
		matr_counterclock(Front);
		matr_clock(Back);
		matr_counterclock(Left);
		matr_counterclock(Up);
		matr_counterclock(Right);
		matr_counterclock(Down);
		T **aux = Up;
		Up = Right;
		Right = Down;
		Down = Left;
		Left = aux;
	}

};
