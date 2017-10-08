#include "Cub_Rubik.h"

Cub_Rubik::Cub_Rubik()
{
	solution = " ";
	Front = new int*[3];
	Back = new int*[3];
	Up = new int*[3];
	Down = new int*[3];
	Left = new int*[3];
	Right = new int*[3];
	for (int i = 0; i < 3; ++i)
	{
		Front[i] = new int[3];
		Back[i] = new int[3];
		Up[i] = new int[3];
		Down[i] = new int[3];
		Left[i] = new int[3];
		Right[i] = new int[3];
	}

	ifstream in("citire.txt");
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			in >> Back[i][j];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			in >> Left[i][j];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			in >> Down[i][j];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			in >> Right[i][j];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			in >> Up[i][j];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			in >> Front[i][j];
	in.close();
}

Cub_Rubik::~Cub_Rubik()
{	
	for (int i = 0; i < 3; ++i)
	{
		delete[] Front[i];
		delete[] Back[i];
		delete[] Up[i];
		delete[] Down[i];
		delete[] Left[i];
		delete[] Right[i];
	}
	delete[] Front;
	delete[] Back;
	delete[] Up;
	delete[] Down;
	delete[] Left;
	delete[] Right;
}

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

int Cub_Rubik::middle_layer(int origine, int poz_anter, int ordin_recurs)
{
	int v2[4], piesa_cautata;
	switch (Front[1][1])
	{
	case 55: 
		v2[0] = Front[1][1] - 1;
		v2[1] = Left[1][1] + 3;
		v2[2] = Back[1][1] + 1;
		v2[3] = Right[1][1] - 3; break;
	case 35: 
		v2[0] = Front[1][1] + 3;
		v2[1] = Left[1][1] + 1;
		v2[2] = Back[1][1] - 3;
		v2[3] = Right[1][1] - 1; break;
	case 5:  
		v2[0] = Front[1][1] + 1;
		v2[1] = Left[1][1] - 3;
		v2[2] = Back[1][1] - 1;
		v2[3] = Right[1][1] + 3; break;
	case 15: 
		v2[0] = Front[1][1] - 3;
		v2[1] = Left[1][1] - 1;
		v2[2] = Back[1][1] + 3;
		v2[3] = Right[1][1] + 1; break;
	}
	piesa_cautata = v2[0];

	if (origine == Front[1][1])
	{
		if (ordin_recurs > 1)
		{
			if (poz_anter == Left[1][1])
			{
				while (Up[1][0] / 10 != Up[1][1] / 10 && Right[1][2] / 10 != Up[1][1] / 10) { upClock(); }
				leftCounterClock(); upClock(); leftClock(); upClock(); frontClock(); upCounterClock(); frontCounterClock();
			}
			if (poz_anter == Back[1][1])
			{
				while (Up[2][1] / 10 != Up[1][1] / 10 && Front[2][1] / 10 != Up[1][1] / 10) { upClock(); }
				backCounterClock(); upClock(); backClock(); upClock(); leftClock(); upCounterClock(); leftCounterClock();
			}
			if (poz_anter == Right[1][1])
			{
				while (Up[1][2] / 10 != Up[1][1] / 10 && Left[1][0] / 10 != Up[1][1] / 10) { upClock(); }
				rightCounterClock(); upClock(); rightClock(); upClock(); backClock(); upCounterClock(); backCounterClock();
			}
		}
	}

	if (piesa_cautata == Left[2][1] || piesa_cautata == Front[1][0])
	{
		yAxisCounterClock();
		middle_layer(origine, Right[1][1], ++ordin_recurs);
		yAxisClock();
	}

	if (piesa_cautata == Back[1][0] || piesa_cautata == Left[0][1])
	{
		yAxisCounterClock();
		yAxisCounterClock();
		middle_layer(origine, Back[1][1], ++ordin_recurs);
		yAxisClock();
		yAxisClock();
	}

	if (piesa_cautata == Right[0][1] || piesa_cautata == Back[1][2])
	{
		yAxisClock();
		middle_layer(origine, Left[1][1], ++ordin_recurs);
		yAxisCounterClock();
	}

	if (piesa_cautata == Up[1][0]) { upCounterClock(); }
	if (piesa_cautata == Up[1][2]) { upClock(); }
	if (piesa_cautata == Up[2][1]) { upClock(); upClock(); }
	if (piesa_cautata == Up[0][1])
	{
		frontCounterClock(); upClock(); frontClock(); upClock(); rightClock(); upCounterClock(); rightCounterClock(); 
		return 0;
	}

	if (piesa_cautata == Back[0][1]) { upCounterClock(); }
	if (piesa_cautata == Right[1][2]) { upClock(); upClock(); }
	if (piesa_cautata == Front[2][1]) { upClock(); }
	if (piesa_cautata == Left[1][0])
	{
		rightClock(); upCounterClock(); rightCounterClock(); upCounterClock(); frontCounterClock(); upClock(); frontClock(); 
		return 0;
	}

	if (piesa_cautata == Right[2][1])
	{
		rightClock(); upCounterClock(); rightCounterClock(); upCounterClock(); frontCounterClock(); upClock(); frontClock();
		upCounterClock();
		rightClock(); upCounterClock(); rightCounterClock(); upCounterClock(); frontCounterClock(); upClock(); frontClock(); 
		return 0;
	}
}

void Cub_Rubik::Scramble()
{
	ofstream out("scrambled.txt");
	minstd_rand generator(time(NULL));
	for (int i = 0; i < 50; ++i)
	{
		int j = generator() % 18;
		switch (j)
		{
		case 0: frontClock(); continue;
		case 1: backClock(); continue;
		case 2: zAxisClock(); continue;
		case 3:	upClock(); continue;
		case 4: downClock(); continue;
		case 5: yAxisClock(); continue;
		case 6:	leftClock(); continue;
		case 7: rightClock(); continue;
		case 8: xAxisClock(); continue;
		case 9: frontCounterClock(); continue;
		case 10: backCounterClock(); continue;
		case 11: zAxisCounterClock(); continue;
		case 12: upCounterClock(); continue;
		case 13: downCounterClock(); continue;
		case 14: yAxisCounterClock(); continue;
		case 15: leftCounterClock(); continue;
		case 16: rightCounterClock(); continue;
		case 17: xAxisCounterClock(); continue;
		}
	}
	out << solution << "\n\n\n";
	out << *this;
	out.close();
	solution.clear();
}

void Cub_Rubik::Solve()
{
	ofstream out("solved.txt");
	int vector1[4];

	//Analiza
	repozitionare_cub();

	//Rezolvare:

	//Layer 1:
	//Faza 1: Crucea
	vector1[0] = Up[1][1] - 3;
	vector1[1] = Up[1][1] - 1;
	vector1[2] = Up[1][1] + 3;
	vector1[3] = Up[1][1] + 1;
	yAxisClock();
	for (int i = 0; i < 4; ++i)
	{
		yAxisCounterClock();
		if (Up[0][1] != vector1[i])
		{
			if (vector1[i] == Down[0][1]) { backClock(); backClock(); continue; }
			if (vector1[i] == Down[1][0]) { downCounterClock(); backClock(); backClock(); continue; }
			if (vector1[i] == Down[1][2]) { downClock(); backClock(); backClock(); continue; }
			if (vector1[i] == Down[2][1]) { downClock(); downClock(); backClock(); backClock(); continue; }

			if (vector1[i] == Right[1][0]) { rightCounterClock(); backClock(); rightClock(); continue; }
			if (vector1[i] == Back[2][1]) { downCounterClock(); rightCounterClock(); backClock(); rightClock(); continue; }
			if (vector1[i] == Front[0][1]) { downClock(); rightCounterClock(); backClock(); rightClock(); continue; }
			if (vector1[i] == Left[1][2]) { leftClock(); backCounterClock(); leftCounterClock(); continue; }

			if (vector1[i] == Left[0][1]) { backCounterClock(); continue; }
			if (vector1[i] == Back[1][0]) { backClock(); downCounterClock(); rightCounterClock(); backClock(); rightClock(); continue; }
			if (vector1[i] == Back[1][2]) { backCounterClock(); downCounterClock(); rightCounterClock(); backClock(); rightClock(); continue; }
			if (vector1[i] == Right[0][1]) { backClock(); continue; }

			if (vector1[i] == Right[2][1]) { rightCounterClock(); rightCounterClock(); backClock(); rightCounterClock(); rightCounterClock(); continue; }
			if (vector1[i] == Front[1][2]) { frontClock(); downClock(); frontCounterClock(); rightCounterClock(); backClock(); rightClock(); continue; }
			if (vector1[i] == Front[1][0]) { frontCounterClock(); downClock(); frontClock(); rightCounterClock(); backClock(); rightClock(); continue; }
			if (vector1[i] == Left[2][1]) { leftClock(); leftClock(); backCounterClock(); leftClock(); leftClock(); continue; }

			if (vector1[i] == Back[0][1]) { backClock(); backClock(); downCounterClock(); rightCounterClock(); backClock(); rightClock(); continue; }
			if (vector1[i] == Up[1][2]) { upClock(); continue; }
			if (vector1[i] == Left[1][0]) { leftCounterClock(); backCounterClock(); continue; }
			if (vector1[i] == Up[2][1]) { frontClock(); rightClock(); rightClock(); backClock(); continue; }
			if (vector1[i] == Front[2][1]) { frontClock(); frontClock(); downClock(); rightCounterClock(); backClock(); rightClock(); continue; }
			if (vector1[i] == Up[1][0]) { rightClock(); rightClock(); downClock(); backClock(); backClock(); continue; }
			if (vector1[i] == Right[1][2]) { rightClock(); backClock(); continue; }
		}
	}

	//Faza 2: Colturile
	vector1[0] = Up[1][1] + 2;
	vector1[1] = Up[1][1] + 4;
	vector1[2] = Up[1][1] - 2;
	vector1[3] = Up[1][1] - 4;
	for (int i = 0; i < 4; ++i)
	{
		yAxisCounterClock();
		if (Up[2][0] != vector1[i])
		{
			if (vector1[i] == Up[2][2] || vector1[i] == Left[2][0] || vector1[i] == Front[2][0])
			{
				leftClock(); downClock(); leftCounterClock();
			}
			if (vector1[i] == Up[0][2] || vector1[i] == Left[0][0] || vector1[i] == Back[0][0])
			{
				leftCounterClock(); downClock(); downClock(); leftClock();
			}
			if (vector1[i] == Up[0][0] || vector1[i] == Right[0][2] || vector1[i] == Back[0][2])
			{
				backCounterClock(); downCounterClock(); backClock();
			}
			if (vector1[i] == Down[2][0] || vector1[i] == Left[2][2] || vector1[i] == Front[0][0])
			{
				downClock();
			}
			if (vector1[i] == Down[0][0] || vector1[i] == Left[0][2] || vector1[i] == Back[2][0])
			{
				downClock(); downClock();
			}
			if (vector1[i] == Down[0][2] || vector1[i] == Back[2][2] || vector1[i] == Right[0][0])
			{
				downCounterClock();
			}
			if (vector1[i] == Right[2][2])
			{
				rightCounterClock(); downCounterClock(); rightClock(); downClock();
			}
			if (vector1[i] == Front[2][2])
			{
				frontClock(); downClock(); frontCounterClock(); downCounterClock();
			}
			if (vector1[i] == Down[2][2])
			{
				rightCounterClock(); downClock(); downClock(); rightClock(); downClock();
			}
			if (vector1[i] == Right[2][0])
			{
				rightCounterClock(); downCounterClock(); rightClock(); continue;
			}
			if (vector1[i] == Front[0][2])
			{
				frontClock(); downClock(); frontCounterClock(); continue;
			}
		}
	}
	yAxisCounterClock();

	//Layer 2							//tine minte Y
	zAxisCounterClock();
	zAxisCounterClock();
	vector1[0] = Front[1][1] - 1;
	vector1[1] = Left[1][1] + 3;
	vector1[2] = Back[1][1] + 1;
	vector1[3] = Right[1][1] - 3;
	yAxisClock();
	for (int i = 0; i < 4; ++i)
	{
		yAxisCounterClock();
		int ok = 0;
		if (Front[1][2] != vector1[i])
			middle_layer(Front[1][1], -1, ok);
	}
	yAxisCounterClock();

	//Layer 3
	//Faza 1: Crucea 
	if (Up[0][1] / 10 != 2 || Up[1][0] / 10 != 2 || Up[1][2] / 10 != 2 || Up[2][1] / 10 != 2)
	{
		int ok = 1;
		if (Up[0][1] / 10 != 2 && Up[1][0] / 10 != 2 && Up[1][2] / 10 != 2 && Up[2][1] / 10 != 2)  //nu e nicio piesa sus
		{
			rightCounterClock(); upCounterClock(); frontCounterClock(); upClock(); frontClock(); rightClock();  //linie orizontala
			frontClock(); rightClock(); upClock(); rightCounterClock(); upCounterClock(); frontCounterClock();  //cruce
			ok = 0;
		}
		if (ok)
		{
			if (Up[0][1] / 10 == 2)  //daca piesa de sus e 'albastra'
			{
				if (Up[1][0] / 10 == 2) //si cea din dreapta
				{
					upCounterClock();
				}
				if (Up[1][2] / 10 == 2) //si cea din stanga
				{
					frontClock(); upClock(); rightClock(); upCounterClock(); rightCounterClock(); frontCounterClock();
					ok = 0;
				}
				if (Up[2][1] / 10 == 2 && ok) //si cea de jos
				{
					upCounterClock(); frontClock(); rightClock(); upClock(); rightCounterClock(); upCounterClock(); frontCounterClock();
				}
			}
			else
			{
				if (Up[1][2] / 10 == 2) //daca piesa din stanga e 'albastra'
				{
					if (Up[1][0] / 10 == 2) //si cea din dreapta
					{
						frontClock(); rightClock(); upClock(); rightCounterClock(); upCounterClock(); frontCounterClock();
						ok = 0;
					}
					if (Up[2][1] / 10 == 2 && ok) //un simplu else aici //si cea de jos
					{
						upClock(); frontClock(); upClock(); rightClock(); upCounterClock(); rightCounterClock(); frontCounterClock();
					}
				}
				else //cea de jos si cea din dreapta
				{
					upClock(); upClock(); frontClock(); upClock(); rightClock(); upCounterClock(); rightCounterClock(); frontCounterClock();
				}
			}
		}
	}

	//Faza 2: Permutarea crucii
	if (Back[0][1] != 8 || Right[1][2] != 16 || Left[1][0] != 34 || Front[2][1] != 52)
	{
		if (Left[1][0] == 8) { upClock(); }
		if (Right[1][2] == 8) { upCounterClock(); }
		if (Front[2][1] == 8) { upClock(); upClock(); }  //am dus piesa corecta pe Back

		if (Left[1][0] == 34 && Right[1][2] != 16) //daca piesa de la stanga e buna
		{
			backClock(); upClock(); backCounterClock(); upClock(); backClock(); upClock(); upClock(); backCounterClock(); upClock();
		}
		if (Right[1][2] == 16 && Left[1][0] != 34) //daca piesa de la dreapta e buna
		{
			rightClock(); upClock(); rightCounterClock(); upClock(); rightClock(); upClock(); upClock(); rightCounterClock(); upClock();
		}
		if (Front[2][1] == 52 && Left[1][0] != 34) //daca piesa din fata e buna
		{
			rightClock(); upClock(); rightCounterClock(); upClock(); rightClock(); upClock(); upClock(); rightCounterClock();
			upCounterClock();
			rightClock(); upClock(); rightCounterClock(); upClock(); rightClock(); upClock(); upClock(); rightCounterClock(); upClock();
			upClock();
		}

		if (Left[1][0] == 16 && Right[1][2] == 52) //rotire clockwise
		{
			rightClock(); rightClock(); upClock(); rightClock(); upClock(); rightCounterClock(); upCounterClock(); rightCounterClock(); upCounterClock();
			rightCounterClock(); upClock(); rightCounterClock();
		}

		if (Left[1][0] == 52 && Right[1][2] == 34) //rotire counter-clockwise
		{
			rightClock(); upCounterClock(); rightClock(); upClock(); rightClock(); upClock(); rightClock(); upCounterClock(); rightCounterClock();
			upCounterClock(); rightClock(); rightClock();
		}
	}

	//Faza 3: Pozitionarea colturilor
	if (Up[2][0] != 27 && Up[2][0] != 19 && Up[2][0] != 51 || Up[2][2] != 29 && Up[2][2] != 37 && Up[2][2] != 53)
	{
		int ok = 1;
		do {
			if ((Up[2][0] == 27 || Up[2][0] == 19 || Up[2][0] == 51) && ok)
			{
				upClock(); rightClock(); upCounterClock(); leftCounterClock(); upClock(); rightCounterClock(); upCounterClock(); leftClock();
					if (Up[2][2] != 29 && Up[2][2] != 37 && Up[2][2] != 53)
					{
						upClock(); rightClock(); upCounterClock(); leftCounterClock(); upClock(); rightCounterClock(); upCounterClock(); leftClock();
					}
				ok = 0;
			}
			if ((Up[2][2] == 29 || Up[2][2] == 37 || Up[2][2] == 53) && ok)
			{
				yAxisCounterClock();
				upClock(); rightClock(); upCounterClock(); leftCounterClock(); upClock(); rightCounterClock(); upCounterClock(); leftClock();
					if (Up[2][2] != 23 && Up[2][2] != 31 && Up[2][2] != 9)
					{
						upClock(); rightClock(); upCounterClock(); leftCounterClock(); upClock(); rightCounterClock(); upCounterClock(); leftClock();
					}
				yAxisClock();
				ok = 0;
			}
			if ((Up[0][2] == 23 || Up[0][2] == 31 || Up[0][2] == 9) && ok)
			{
				yAxisCounterClock();
				yAxisCounterClock();
				upClock(); rightClock(); upCounterClock(); leftCounterClock(); upClock(); rightCounterClock(); upCounterClock(); leftClock();
					if (Up[2][2] != 21 && Up[2][2] != 13 && Up[2][2] != 7)
					{
						upClock(); rightClock(); upCounterClock(); leftCounterClock(); upClock(); rightCounterClock(); upCounterClock(); leftClock();
					}
				yAxisClock();
				yAxisClock();
				ok = 0;
			}
			if ((Up[0][0] == 21 || Up[0][0] == 13 || Up[0][0] == 7) && ok)
			{
				yAxisClock();
				upClock(); rightClock(); upCounterClock(); leftCounterClock(); upClock(); rightCounterClock(); upCounterClock(); leftClock();
					if (Up[2][2] != 27 && Up[2][2] != 19 && Up[2][2] != 51)
					{
						upClock(); rightClock(); upCounterClock(); leftCounterClock(); upClock(); rightCounterClock(); upCounterClock(); leftClock();
					}
				yAxisCounterClock();
				ok = 0;
			}

			if (ok)
			{
				upClock(); rightClock(); upCounterClock(); leftCounterClock(); upClock(); rightCounterClock(); upCounterClock(); leftClock();
			}
		} while (ok);
	}

	//Faza 4: Rotirea colturilor
	if (Up[0][0] != 21 || Up[0][2] != 23 || Up[2][0] != 27 || Up[2][2] != 29)
	{
		vector1[0] = 27;
		vector1[1] = 29;
		vector1[2] = 23;
		vector1[3] = 21;
		yAxisClock();
		int ok = 0;
		for (int i = 0; i < 4; ++i)
		{
			if (ok == 0) yAxisCounterClock();
			else  upCounterClock();

			if (Front[2][2] == vector1[i])
			{
				rightCounterClock(); downCounterClock(); rightClock(); downClock();
				rightCounterClock(); downCounterClock(); rightClock(); downClock();
			}
			if (Right[2][2] == vector1[i])
			{
				rightCounterClock(); downCounterClock(); rightClock(); downClock();
				rightCounterClock(); downCounterClock(); rightClock(); downClock();
				ok += 1;
			}
		}
		if (Front[1][1] == 55) { upCounterClock(); }
		if (Front[1][1] == 35) { upClock(); upClock(); }
		if (Front[1][1] == 5) { upClock(); }
	}

	//Afisarea:
	repozitionare_cub();
	out << solution << "\n\n\n";
	out << *this;
	out.close();
	solution.clear();
}

ofstream& operator << (ofstream& out, Cub_Rubik& cub)
{
	int i, j;
	for (i = 0; i < 3; ++i)
		out << endl << setw(4) << 0 << setw(4) << 0 << setw(4) << 0 << setw(4) << cub.Back[i][0]
		<< setw(4) << cub.Back[i][1] << setw(4) << cub.Back[i][2] << setw(4) << 0
		<< setw(4) << 0 << setw(4) << 0 << setw(4) << 0 << setw(4) << 0 << setw(4) << 0 << endl;
	for (i = 0; i < 3; ++i)
	{
		out << endl;
		for (j = 0; j < 3; ++j)
			out << setw(4) << cub.Left[i][j];
		for (j = 0; j < 3; ++j)
			out << setw(4) << cub.Down[i][j];
		for (j = 0; j < 3; ++j)
			out << setw(4) << cub.Right[i][j];
		for (j = 0; j < 3; ++j)
			out << setw(4) << cub.Up[i][j];
		out << endl;
	}
	for (i = 0; i < 3; ++i)
		out << endl << setw(4) << 0 << setw(4) << 0 << setw(4) << 0 << setw(4) << cub.Front[i][0]
		<< setw(4) << cub.Front[i][1] << setw(4) << cub.Front[i][2]
		<< setw(4) << 0 << setw(4) << 0 << setw(4) << 0 << setw(4) << 0 << setw(4) << 0 << setw(4) << 0 << endl;
	return out;
}
