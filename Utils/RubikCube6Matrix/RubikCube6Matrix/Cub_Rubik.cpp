#include "Cub_Rubik.h"



inline void Cub_Rubik::swap(int & a, int & b)
{
	a += b, b = a - b, a -= b;
}

inline fata_cub& Cub_Rubik::matr_clock(fata_cub & m)
{
	swap(m[0][0], m[0][2]);
	swap(m[0][0], m[2][2]);
	swap(m[0][0], m[2][0]);

	swap(m[0][1], m[1][2]);
	swap(m[0][1], m[2][1]);
	swap(m[0][1], m[1][0]);
	return m;
}

inline fata_cub& Cub_Rubik::matr_counterclock(fata_cub & m)
{
	swap(m[0][0], m[2][0]);
	swap(m[0][0], m[2][2]);
	swap(m[0][0], m[0][2]);

	swap(m[0][1], m[1][0]);
	swap(m[0][1], m[2][1]);
	swap(m[0][1], m[1][2]);
	return m;
}

inline void Cub_Rubik::clock(fata_cub& centru, fata_cub& sus, fata_cub& jos, fata_cub& stanga, fata_cub& dreapta)
{
	swap(sus[2][0], dreapta[0][0]);
	swap(sus[2][0], jos[0][2]);
	swap(sus[2][0], stanga[2][2]);

	swap(sus[2][1], dreapta[1][0]);
	swap(sus[2][1], jos[0][1]);
	swap(sus[2][1], stanga[1][2]);

	swap(sus[2][2], dreapta[2][0]);
	swap(sus[2][2], jos[0][0]);
	swap(sus[2][2], stanga[0][2]);

	matr_clock(centru);
}

inline void Cub_Rubik::counterclock(fata_cub & centru, fata_cub & sus, fata_cub & jos, fata_cub & stanga, fata_cub & dreapta)
{
	swap(sus[2][0], stanga[2][2]);
	swap(sus[2][0], jos[0][2]);
	swap(sus[2][0], dreapta[0][0]);

	swap(sus[2][1], stanga[1][2]);
	swap(sus[2][1], jos[0][1]);
	swap(sus[2][1], dreapta[1][0]);

	swap(sus[2][2], stanga[0][2]);
	swap(sus[2][2], jos[0][0]);
	swap(sus[2][2], dreapta[2][0]);

	matr_counterclock(centru);
}

void Cub_Rubik::frontClock()
{
	//counterclock(F, D, matr_clock(matr_clock(U)), matr_counterclock(L), matr_clock(R)); matr_clock(matr_clock(U)); matr_clock(L); matr_counterclock(R); printf(" F ");
	matr_clock(matr_clock(Up));
	matr_counterclock(Left);
	matr_clock(Right);
	counterclock(Front, Down, Up, Left, Right);
	matr_clock(matr_clock(Up));
	matr_clock(Left);
	matr_counterclock(Right);
	solution += " F ";
}

void Cub_Rubik::frontCounterClock()
{
	//clock(F, D, matr_clock(matr_clock(U)), matr_counterclock(L), matr_clock(R)); matr_clock(matr_clock(U)); matr_clock(L); matr_counterclock(R); printf(" F' ");
	matr_clock(matr_clock(Up));
	matr_counterclock(Left);
	matr_clock(Right);
	clock(Front, Down, Up, Left, Right);
	matr_clock(matr_clock(Up));
	matr_clock(Left);
	matr_counterclock(Right);
	solution += " F' ";
}

void Cub_Rubik::backClock()
{
	//counterclock(B, matr_clock(matr_clock(U)), D, matr_clock(L), matr_counterclock(R)); matr_clock(matr_clock(U)); matr_counterclock(L); matr_clock(R); printf(" B ");
	matr_clock(matr_clock(Up));
	matr_clock(Left);
	matr_counterclock(Right);
	counterclock(Back, Up, Down, Left, Right);
	matr_clock(matr_clock(Up));
	matr_counterclock(Left);
	matr_clock(Right);
	solution += " B ";
}

void Cub_Rubik::backCounterClock()
{
	//clock(B, matr_clock(matr_clock(U)), D, matr_clock(L), matr_counterclock(R)); matr_clock(matr_clock(U)); matr_counterclock(L); matr_clock(R); printf(" B' ");
	matr_clock(matr_clock(Up));
	matr_clock(Left);
	matr_counterclock(Right);
	clock(Back, Up, Down, Left, Right);
	matr_clock(matr_clock(Up));
	matr_counterclock(Left);
	matr_clock(Right);
	solution += " B' ";
}

void Cub_Rubik::upClock()
{
	//counterclock(U, matr_clock(matr_clock(B)), matr_clock(matr_clock(F)), R, L); matr_clock(matr_clock(B)); matr_clock(matr_clock(F)); printf(" U ");
	matr_clock(matr_clock(Back));
	matr_clock(matr_clock(Front));
	counterclock(Up, Back, Front, Right, Left);
	matr_clock(matr_clock(Back));
	matr_clock(matr_clock(Front));
	solution += " U ";
}

void Cub_Rubik::upCounterClock()
{
	//clock(U, matr_clock(matr_clock(B)), matr_clock(matr_clock(F)), R, L); matr_clock(matr_clock(B)); matr_clock(matr_clock(F)); printf(" U' ");
	matr_clock(matr_clock(Back));
	matr_clock(matr_clock(Front));
	clock(Up, Back, Front, Right, Left);
	matr_clock(matr_clock(Back));
	matr_clock(matr_clock(Front));
	solution += " U' ";
}

void Cub_Rubik::downClock()
{
	//counterclock(D, B, F, L, R); printf(" D ");
	counterclock(Down, Back, Front, Left, Right);
	solution += " D ";
}

void Cub_Rubik::downCounterClock()
{
	//clock(D, B, F, L, R); printf(" D' ");
	clock(Down, Back, Front, Left, Right);
	solution += " D' ";
}

void Cub_Rubik::leftClock()
{
	//counterclock(L, matr_counterclock(B), matr_clock(F), U, D); matr_clock(B); matr_counterclock(F); printf(" L ");
	matr_counterclock(Back);
	matr_clock(Front);
	counterclock(Left, Back, Front, Up, Down);
	matr_clock(Back);
	matr_counterclock(Front);
	solution += " L ";
}

void Cub_Rubik::leftCounterClock()
{
	//clock(L, matr_counterclock(B), matr_clock(F), U, D); matr_clock(B); matr_counterclock(F); printf(" L' ");
	matr_counterclock(Back);
	matr_clock(Front);
	clock(Left, Back, Front, Up, Down);
	matr_clock(Back);
	matr_counterclock(Front);
	solution += " L' ";
}

void Cub_Rubik::rightClock()
{
	//counterclock(R, matr_clock(B), matr_counterclock(F), D, U); matr_counterclock(B); matr_clock(F); printf(" R ");
	matr_clock(Back);
	matr_counterclock(Front);
	counterclock(Right, Back, Front, Down, Up);
	matr_counterclock(Back);
	matr_clock(Front);
	solution += " R ";
}

void Cub_Rubik::rightCounterClock()
{
	//clock(R, matr_clock(B), matr_counterclock(F), D, U); matr_counterclock(B); matr_clock(F); printf(" R' ");
	matr_clock(Back);
	matr_counterclock(Front);
	clock(Right, Back, Front, Down, Up);
	matr_counterclock(Back);
	matr_clock(Front);
	solution += " R' ";
}

void Cub_Rubik::zAxisCounterClock()
{
	void *aux;
	matr_counterclock(Back); matr_clock(Front);
	aux = (void*)Down;
	Down = Left;
	Left = Up;
	Up = Right;
	Right = (int **)aux;
	solution += " zAxisCounterClock ";
}

void Cub_Rubik::zAxisClock()
{
	void *aux;
	matr_clock(Back); matr_counterclock(Front);
	aux = (void*)Down;
	Down = Right;
	Right = Up;
	Up = Left;
	Left = (int **)aux;
	solution += " zAxisClock ";
}

void Cub_Rubik::yAxisClock()
{
	void *aux;
	matr_clock(Down); matr_counterclock(Up);
	matr_clock(Front); matr_clock(Back);
	matr_clock(Left); matr_clock(Right);
	aux = (void*)Back;
	Back = Left;
	Left = Front;
	Front = Right;
	Right = (int **)aux;
	solution += " yAxisClock ";
}

void Cub_Rubik::yAxisCounterClock()
{
	void *aux;
	matr_counterclock(Down); matr_clock(Up);
	matr_counterclock(Front); matr_counterclock(Back);
	matr_counterclock(Left); matr_counterclock(Right);
	aux = (void*)Back;
	Back = Right;
	Right = Front;
	Front = Left;
	Left = (int **)aux;
	solution += " yAxisCounterClock ";
}

void Cub_Rubik::xAxisClock()
{
	void *aux;
	matr_clock(matr_clock(Front));  matr_clock(matr_clock(Up));
	matr_clock(Left); matr_counterclock(Right);
	aux = (void*)Down;
	Down = Back;
	Back = Up;
	Up = Front;
	Front = (int **)aux;
	solution += " xAxisClock ";
}

void Cub_Rubik::xAxisCounterClock()
{
	void *aux;
	matr_clock(matr_clock(Back));  matr_clock(matr_clock(Up));
	matr_counterclock(Left); matr_clock(Right);
	aux = (void*)Down;
	Down = Front;
	Front = Up;
	Up = Back;
	Back = (int **)aux;
	solution += " xAxisCounterClock ";
}

void Cub_Rubik::repozitionare_cub()
{
	if (Up[1][1] != 45)
	{
		if (Front[1][1] == 45) xAxisClock();
		if (Left[1][1] == 45) zAxisClock();
		if (Back[1][1] == 45) xAxisCounterClock();
		if (Right[1][1] == 45) zAxisCounterClock();
		if (Down[1][1] == 45)
		{
			zAxisClock();
			zAxisClock();
		}
	}
	if (Front[1][1] != 55)
	{
		if (Left[1][1] == 55) yAxisCounterClock();
		if (Right[1][1] == 55) yAxisClock();
		if (Back[1][1] == 55)
		{
			yAxisClock();
			yAxisClock();
		}
	}
}
