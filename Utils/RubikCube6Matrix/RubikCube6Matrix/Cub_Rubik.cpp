#include "Cub_Rubik.h"


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
