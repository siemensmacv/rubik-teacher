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

void Cub_Rubik::clock_Front()
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

void Cub_Rubik::counterclock_Front()
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

void Cub_Rubik::clock_Back()
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

void Cub_Rubik::counterclock_Back()
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

void Cub_Rubik::clock_Up()
{
	//counterclock(U, matr_clock(matr_clock(B)), matr_clock(matr_clock(F)), R, L); matr_clock(matr_clock(B)); matr_clock(matr_clock(F)); printf(" U ");
	matr_clock(matr_clock(Back));
	matr_clock(matr_clock(Front));
	counterclock(Up, Back, Front, Right, Left);
	matr_clock(matr_clock(Back));
	matr_clock(matr_clock(Front));
	solution += " U ";
}

void Cub_Rubik::counterclock_Up()
{
	//clock(U, matr_clock(matr_clock(B)), matr_clock(matr_clock(F)), R, L); matr_clock(matr_clock(B)); matr_clock(matr_clock(F)); printf(" U' ");
	matr_clock(matr_clock(Back));
	matr_clock(matr_clock(Front));
	clock(Up, Back, Front, Right, Left);
	matr_clock(matr_clock(Back));
	matr_clock(matr_clock(Front));
	solution += " U' ";
}

void Cub_Rubik::clock_Down()
{
	//counterclock(D, B, F, L, R); printf(" D ");
	counterclock(Down, Back, Front, Left, Right);
	solution += " D ";
}

void Cub_Rubik::counterclock_Down()
{
	//clock(D, B, F, L, R); printf(" D' ");
	clock(Down, Back, Front, Left, Right);
	solution += " D' ";
}

void Cub_Rubik::clock_Left()
{
	//counterclock(L, matr_counterclock(B), matr_clock(F), U, D); matr_clock(B); matr_counterclock(F); printf(" L ");
	matr_counterclock(Back);
	matr_clock(Front);
	counterclock(Left, Back, Front, Up, Down);
	matr_clock(Back);
	matr_counterclock(Front);
	solution += " L ";
}

void Cub_Rubik::counterclock_Left()
{
	//clock(L, matr_counterclock(B), matr_clock(F), U, D); matr_clock(B); matr_counterclock(F); printf(" L' ");
	matr_counterclock(Back);
	matr_clock(Front);
	clock(Left, Back, Front, Up, Down);
	matr_clock(Back);
	matr_counterclock(Front);
	solution += " L' ";
}

void Cub_Rubik::clock_Right()
{
	//counterclock(R, matr_clock(B), matr_counterclock(F), D, U); matr_counterclock(B); matr_clock(F); printf(" R ");
	matr_clock(Back);
	matr_counterclock(Front);
	counterclock(Right, Back, Front, Down, Up);
	matr_counterclock(Back);
	matr_clock(Front);
	solution += " R ";
}

void Cub_Rubik::counterclock_Right()
{
	//clock(R, matr_clock(B), matr_counterclock(F), D, U); matr_counterclock(B); matr_clock(F); printf(" R' ");
	matr_clock(Back);
	matr_counterclock(Front);
	clock(Right, Back, Front, Down, Up);
	matr_counterclock(Back);
	matr_clock(Front);
	solution += " R' ";
}

void Cub_Rubik::cub_X_axis_stanga()
{
	void *aux;
	matr_counterclock(Back); matr_clock(Front);
	aux = (void*)Down;
	Down = Left;
	Left = Up;
	Up = Right;
	Right = (int **)aux;
	solution += " cub_X_axis_stanga ";
}

void Cub_Rubik::cub_X_axis_dreapta()
{
	void *aux;
	matr_clock(Back); matr_counterclock(Front);
	aux = (void*)Down;
	Down = Right;
	Right = Up;
	Up = Left;
	Left = (int **)aux;
	solution += " cub_X_axis_dreapta ";
}

void Cub_Rubik::cub_Y_axis_clock()
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
	solution += " cub_Y_axis_clock ";
}

void Cub_Rubik::cub_Y_axis_counterclock()
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
	solution += " cub_Y_axis_counterclock ";
}

void Cub_Rubik::cub_Z_axis_inainte()
{
	void *aux;
	matr_clock(matr_clock(Front));  matr_clock(matr_clock(Up));
	matr_clock(Left); matr_counterclock(Right);
	aux = (void*)Down;
	Down = Back;
	Back = Up;
	Up = Front;
	Front = (int **)aux;
	solution += " cub_Z_axis_inainte ";
}

void Cub_Rubik::cub_Z_axis_inapoi()
{
	void *aux;
	matr_clock(matr_clock(Back));  matr_clock(matr_clock(Up));
	matr_counterclock(Left); matr_clock(Right);
	aux = (void*)Down;
	Down = Front;
	Front = Up;
	Up = Back;
	Back = (int **)aux;
	solution += " cub_Z_axis_inapoi ";
}

void Cub_Rubik::repozitionare_cub()
{
	if (Up[1][1] != 45)
	{
		if (Front[1][1] == 45) cub_Z_axis_inainte();
		if (Left[1][1] == 45) cub_X_axis_dreapta();
		if (Back[1][1] == 45) cub_Z_axis_inapoi();
		if (Right[1][1] == 45) cub_X_axis_stanga();
		if (Down[1][1] == 45)
		{
			cub_X_axis_dreapta();
			cub_X_axis_dreapta();
		}
	}
	if (Front[1][1] != 55)
	{
		if (Left[1][1] == 55) cub_Y_axis_counterclock();
		if (Right[1][1] == 55) cub_Y_axis_clock();
		if (Back[1][1] == 55)
		{
			cub_Y_axis_clock();
			cub_Y_axis_clock();
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
				while (Up[1][0] / 10 != Up[1][1] / 10 && Right[1][2] / 10 != Up[1][1] / 10) { clock_Up(); }
				counterclock_Left(); clock_Up(); clock_Left(); clock_Up(); clock_Front(); counterclock_Up(); counterclock_Front();
			}
			if (poz_anter == Back[1][1])
			{
				while (Up[2][1] / 10 != Up[1][1] / 10 && Front[2][1] / 10 != Up[1][1] / 10) { clock_Up(); }
				counterclock_Back(); clock_Up(); clock_Back(); clock_Up(); clock_Left(); counterclock_Up(); counterclock_Left();
			}
			if (poz_anter == Right[1][1])
			{
				while (Up[1][2] / 10 != Up[1][1] / 10 && Left[1][0] / 10 != Up[1][1] / 10) { clock_Up(); }
				counterclock_Right(); clock_Up(); clock_Right(); clock_Up(); clock_Back(); counterclock_Up(); counterclock_Back();
			}
		}
	}

	if (piesa_cautata == Left[2][1] || piesa_cautata == Front[1][0])
	{
		cub_Y_axis_counterclock();
		middle_layer(origine, Right[1][1], ++ordin_recurs);
		cub_Y_axis_clock();
	}

	if (piesa_cautata == Back[1][0] || piesa_cautata == Left[0][1])
	{
		cub_Y_axis_counterclock();
		cub_Y_axis_counterclock();
		middle_layer(origine, Back[1][1], ++ordin_recurs);
		cub_Y_axis_clock();
		cub_Y_axis_clock();
	}

	if (piesa_cautata == Right[0][1] || piesa_cautata == Back[1][2])
	{
		cub_Y_axis_clock();
		middle_layer(origine, Left[1][1], ++ordin_recurs);
		cub_Y_axis_counterclock();
	}

	if (piesa_cautata == Up[1][0]) { counterclock_Up(); }
	if (piesa_cautata == Up[1][2]) { clock_Up(); }
	if (piesa_cautata == Up[2][1]) { clock_Up(); clock_Up(); }
	if (piesa_cautata == Up[0][1])
	{
		counterclock_Front(); clock_Up(); clock_Front(); clock_Up(); clock_Right(); counterclock_Up(); counterclock_Right(); 
		return 0;
	}

	if (piesa_cautata == Back[0][1]) { counterclock_Up(); }
	if (piesa_cautata == Right[1][2]) { clock_Up(); clock_Up(); }
	if (piesa_cautata == Front[2][1]) { clock_Up(); }
	if (piesa_cautata == Left[1][0])
	{
		clock_Right(); counterclock_Up(); counterclock_Right(); counterclock_Up(); counterclock_Front(); clock_Up(); clock_Front(); 
		return 0;
	}

	if (piesa_cautata == Right[2][1])
	{
		clock_Right(); counterclock_Up(); counterclock_Right(); counterclock_Up(); counterclock_Front(); clock_Up(); clock_Front();
		counterclock_Up();
		clock_Right(); counterclock_Up(); counterclock_Right(); counterclock_Up(); counterclock_Front(); clock_Up(); clock_Front(); 
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
		case 0: clock_Front(); continue;
		case 1: clock_Back(); continue;
		case 2: cub_X_axis_dreapta(); continue;
		case 3:	clock_Up(); continue;
		case 4: clock_Down(); continue;
		case 5: cub_Y_axis_clock(); continue;
		case 6:	clock_Left(); continue;
		case 7: clock_Right(); continue;
		case 8: cub_Z_axis_inainte(); continue;
		case 9: counterclock_Front(); continue;
		case 10: counterclock_Back(); continue;
		case 11: cub_X_axis_stanga(); continue;
		case 12: counterclock_Up(); continue;
		case 13: counterclock_Down(); continue;
		case 14: cub_Y_axis_counterclock(); continue;
		case 15: counterclock_Left(); continue;
		case 16: counterclock_Right(); continue;
		case 17: cub_Z_axis_inapoi(); continue;
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
	cub_Y_axis_clock();
	for (int i = 0; i < 4; ++i)
	{
		cub_Y_axis_counterclock();
		if (Up[0][1] != vector1[i])
		{
			if (vector1[i] == Down[0][1]) { clock_Back(); clock_Back(); continue; }
			if (vector1[i] == Down[1][0]) { counterclock_Down(); clock_Back(); clock_Back(); continue; }
			if (vector1[i] == Down[1][2]) { clock_Down(); clock_Back(); clock_Back(); continue; }
			if (vector1[i] == Down[2][1]) { clock_Down(); clock_Down(); clock_Back(); clock_Back(); continue; }

			if (vector1[i] == Right[1][0]) { counterclock_Right(); clock_Back(); clock_Right(); continue; }
			if (vector1[i] == Back[2][1]) { counterclock_Down(); counterclock_Right(); clock_Back(); clock_Right(); continue; }
			if (vector1[i] == Front[0][1]) { clock_Down(); counterclock_Right(); clock_Back(); clock_Right(); continue; }
			if (vector1[i] == Left[1][2]) { clock_Left(); counterclock_Back(); counterclock_Left(); continue; }

			if (vector1[i] == Left[0][1]) { counterclock_Back(); continue; }
			if (vector1[i] == Back[1][0]) { clock_Back(); counterclock_Down(); counterclock_Right(); clock_Back(); clock_Right(); continue; }
			if (vector1[i] == Back[1][2]) { counterclock_Back(); counterclock_Down(); counterclock_Right(); clock_Back(); clock_Right(); continue; }
			if (vector1[i] == Right[0][1]) { clock_Back(); continue; }

			if (vector1[i] == Right[2][1]) { counterclock_Right(); counterclock_Right(); clock_Back(); counterclock_Right(); counterclock_Right(); continue; }
			if (vector1[i] == Front[1][2]) { clock_Front(); clock_Down(); counterclock_Front(); counterclock_Right(); clock_Back(); clock_Right(); continue; }
			if (vector1[i] == Front[1][0]) { counterclock_Front(); clock_Down(); clock_Front(); counterclock_Right(); clock_Back(); clock_Right(); continue; }
			if (vector1[i] == Left[2][1]) { clock_Left(); clock_Left(); counterclock_Back(); clock_Left(); clock_Left(); continue; }

			if (vector1[i] == Back[0][1]) { clock_Back(); clock_Back(); counterclock_Down(); counterclock_Right(); clock_Back(); clock_Right(); continue; }
			if (vector1[i] == Up[1][2]) { clock_Up(); continue; }
			if (vector1[i] == Left[1][0]) { counterclock_Left(); counterclock_Back(); continue; }
			if (vector1[i] == Up[2][1]) { clock_Front(); clock_Right(); clock_Right(); clock_Back(); continue; }
			if (vector1[i] == Front[2][1]) { clock_Front(); clock_Front(); clock_Down(); counterclock_Right(); clock_Back(); clock_Right(); continue; }
			if (vector1[i] == Up[1][0]) { clock_Right(); clock_Right(); clock_Down(); clock_Back(); clock_Back(); continue; }
			if (vector1[i] == Right[1][2]) { clock_Right(); clock_Back(); continue; }
		}
	}

	//Faza 2: Colturile
	vector1[0] = Up[1][1] + 2;
	vector1[1] = Up[1][1] + 4;
	vector1[2] = Up[1][1] - 2;
	vector1[3] = Up[1][1] - 4;
	for (int i = 0; i < 4; ++i)
	{
		cub_Y_axis_counterclock();
		if (Up[2][0] != vector1[i])
		{
			if (vector1[i] == Up[2][2] || vector1[i] == Left[2][0] || vector1[i] == Front[2][0])
			{
				clock_Left(); clock_Down(); counterclock_Left();
			}
			if (vector1[i] == Up[0][2] || vector1[i] == Left[0][0] || vector1[i] == Back[0][0])
			{
				counterclock_Left(); clock_Down(); clock_Down(); clock_Left();
			}
			if (vector1[i] == Up[0][0] || vector1[i] == Right[0][2] || vector1[i] == Back[0][2])
			{
				counterclock_Back(); counterclock_Down(); clock_Back();
			}
			if (vector1[i] == Down[2][0] || vector1[i] == Left[2][2] || vector1[i] == Front[0][0])
			{
				clock_Down();
			}
			if (vector1[i] == Down[0][0] || vector1[i] == Left[0][2] || vector1[i] == Back[2][0])
			{
				clock_Down(); clock_Down();
			}
			if (vector1[i] == Down[0][2] || vector1[i] == Back[2][2] || vector1[i] == Right[0][0])
			{
				counterclock_Down();
			}
			if (vector1[i] == Right[2][2])
			{
				counterclock_Right(); counterclock_Down(); clock_Right(); clock_Down();
			}
			if (vector1[i] == Front[2][2])
			{
				clock_Front(); clock_Down(); counterclock_Front(); counterclock_Down();
			}
			if (vector1[i] == Down[2][2])
			{
				counterclock_Right(); clock_Down(); clock_Down(); clock_Right(); clock_Down();
			}
			if (vector1[i] == Right[2][0])
			{
				counterclock_Right(); counterclock_Down(); clock_Right(); continue;
			}
			if (vector1[i] == Front[0][2])
			{
				clock_Front(); clock_Down(); counterclock_Front(); continue;
			}
		}
	}
	cub_Y_axis_counterclock();

	//Layer 2							//tine minte Y
	cub_X_axis_stanga();
	cub_X_axis_stanga();
	vector1[0] = Front[1][1] - 1;
	vector1[1] = Left[1][1] + 3;
	vector1[2] = Back[1][1] + 1;
	vector1[3] = Right[1][1] - 3;
	cub_Y_axis_clock();
	for (int i = 0; i < 4; ++i)
	{
		cub_Y_axis_counterclock();
		int ok = 0;
		if (Front[1][2] != vector1[i])
			middle_layer(Front[1][1], -1, ok);
	}
	cub_Y_axis_counterclock();

	//Layer 3
	//Faza 1: Crucea 
	if (Up[0][1] / 10 != 2 || Up[1][0] / 10 != 2 || Up[1][2] / 10 != 2 || Up[2][1] / 10 != 2)
	{
		int ok = 1;
		if (Up[0][1] / 10 != 2 && Up[1][0] / 10 != 2 && Up[1][2] / 10 != 2 && Up[2][1] / 10 != 2)  //nu e nicio piesa sus
		{
			counterclock_Right(); counterclock_Up(); counterclock_Front(); clock_Up(); clock_Front(); clock_Right();  //linie orizontala
			clock_Front(); clock_Right(); clock_Up(); counterclock_Right(); counterclock_Up(); counterclock_Front();  //cruce
			ok = 0;
		}
		if (ok)
		{
			if (Up[0][1] / 10 == 2)  //daca piesa de sus e 'albastra'
			{
				if (Up[1][0] / 10 == 2) //si cea din dreapta
				{
					counterclock_Up();
				}
				if (Up[1][2] / 10 == 2) //si cea din stanga
				{
					clock_Front(); clock_Up(); clock_Right(); counterclock_Up(); counterclock_Right(); counterclock_Front();
					ok = 0;
				}
				if (Up[2][1] / 10 == 2 && ok) //si cea de jos
				{
					counterclock_Up(); clock_Front(); clock_Right(); clock_Up(); counterclock_Right(); counterclock_Up(); counterclock_Front();
				}
			}
			else
			{
				if (Up[1][2] / 10 == 2) //daca piesa din stanga e 'albastra'
				{
					if (Up[1][0] / 10 == 2) //si cea din dreapta
					{
						clock_Front(); clock_Right(); clock_Up(); counterclock_Right(); counterclock_Up(); counterclock_Front();
						ok = 0;
					}
					if (Up[2][1] / 10 == 2 && ok) //un simplu else aici //si cea de jos
					{
						clock_Up(); clock_Front(); clock_Up(); clock_Right(); counterclock_Up(); counterclock_Right(); counterclock_Front();
					}
				}
				else //cea de jos si cea din dreapta
				{
					clock_Up(); clock_Up(); clock_Front(); clock_Up(); clock_Right(); counterclock_Up(); counterclock_Right(); counterclock_Front();
				}
			}
		}
	}

	//Faza 2: Permutarea crucii
	if (Back[0][1] != 8 || Right[1][2] != 16 || Left[1][0] != 34 || Front[2][1] != 52)
	{
		if (Left[1][0] == 8) { clock_Up(); }
		if (Right[1][2] == 8) { counterclock_Up(); }
		if (Front[2][1] == 8) { clock_Up(); clock_Up(); }  //am dus piesa corecta pe Back

		if (Left[1][0] == 34 && Right[1][2] != 16) //daca piesa de la stanga e buna
		{
			clock_Back(); clock_Up(); counterclock_Back(); clock_Up(); clock_Back(); clock_Up(); clock_Up(); counterclock_Back(); clock_Up();
		}
		if (Right[1][2] == 16 && Left[1][0] != 34) //daca piesa de la dreapta e buna
		{
			clock_Right(); clock_Up(); counterclock_Right(); clock_Up(); clock_Right(); clock_Up(); clock_Up(); counterclock_Right(); clock_Up();
		}
		if (Front[2][1] == 52 && Left[1][0] != 34) //daca piesa din fata e buna
		{
			clock_Right(); clock_Up(); counterclock_Right(); clock_Up(); clock_Right(); clock_Up(); clock_Up(); counterclock_Right();
			counterclock_Up();
			clock_Right(); clock_Up(); counterclock_Right(); clock_Up(); clock_Right(); clock_Up(); clock_Up(); counterclock_Right(); clock_Up();
			clock_Up();
		}

		if (Left[1][0] == 16 && Right[1][2] == 52) //rotire clockwise
		{
			clock_Right(); clock_Right(); clock_Up(); clock_Right(); clock_Up(); counterclock_Right(); counterclock_Up(); counterclock_Right(); counterclock_Up();
			counterclock_Right(); clock_Up(); counterclock_Right();
		}

		if (Left[1][0] == 52 && Right[1][2] == 34) //rotire counter-clockwise
		{
			clock_Right(); counterclock_Up(); clock_Right(); clock_Up(); clock_Right(); clock_Up(); clock_Right(); counterclock_Up(); counterclock_Right();
			counterclock_Up(); clock_Right(); clock_Right();
		}
	}

	//Faza 3: Pozitionarea colturilor
	if (Up[2][0] != 27 && Up[2][0] != 19 && Up[2][0] != 51 || Up[2][2] != 29 && Up[2][2] != 37 && Up[2][2] != 53)
	{
		int ok = 1;
		do {
			if ((Up[2][0] == 27 || Up[2][0] == 19 || Up[2][0] == 51) && ok)
			{
				clock_Up(); clock_Right(); counterclock_Up(); counterclock_Left(); clock_Up(); counterclock_Right(); counterclock_Up(); clock_Left();
					if (Up[2][2] != 29 && Up[2][2] != 37 && Up[2][2] != 53)
					{
						clock_Up(); clock_Right(); counterclock_Up(); counterclock_Left(); clock_Up(); counterclock_Right(); counterclock_Up(); clock_Left();
					}
				ok = 0;
			}
			if ((Up[2][2] == 29 || Up[2][2] == 37 || Up[2][2] == 53) && ok)
			{
				cub_Y_axis_counterclock();
				clock_Up(); clock_Right(); counterclock_Up(); counterclock_Left(); clock_Up(); counterclock_Right(); counterclock_Up(); clock_Left();
					if (Up[2][2] != 23 && Up[2][2] != 31 && Up[2][2] != 9)
					{
						clock_Up(); clock_Right(); counterclock_Up(); counterclock_Left(); clock_Up(); counterclock_Right(); counterclock_Up(); clock_Left();
					}
				cub_Y_axis_clock();
				ok = 0;
			}
			if ((Up[0][2] == 23 || Up[0][2] == 31 || Up[0][2] == 9) && ok)
			{
				cub_Y_axis_counterclock();
				cub_Y_axis_counterclock();
				clock_Up(); clock_Right(); counterclock_Up(); counterclock_Left(); clock_Up(); counterclock_Right(); counterclock_Up(); clock_Left();
					if (Up[2][2] != 21 && Up[2][2] != 13 && Up[2][2] != 7)
					{
						clock_Up(); clock_Right(); counterclock_Up(); counterclock_Left(); clock_Up(); counterclock_Right(); counterclock_Up(); clock_Left();
					}
				cub_Y_axis_clock();
				cub_Y_axis_clock();
				ok = 0;
			}
			if ((Up[0][0] == 21 || Up[0][0] == 13 || Up[0][0] == 7) && ok)
			{
				cub_Y_axis_clock();
				clock_Up(); clock_Right(); counterclock_Up(); counterclock_Left(); clock_Up(); counterclock_Right(); counterclock_Up(); clock_Left();
					if (Up[2][2] != 27 && Up[2][2] != 19 && Up[2][2] != 51)
					{
						clock_Up(); clock_Right(); counterclock_Up(); counterclock_Left(); clock_Up(); counterclock_Right(); counterclock_Up(); clock_Left();
					}
				cub_Y_axis_counterclock();
				ok = 0;
			}

			if (ok)
			{
				clock_Up(); clock_Right(); counterclock_Up(); counterclock_Left(); clock_Up(); counterclock_Right(); counterclock_Up(); clock_Left();
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
		cub_Y_axis_clock();
		int ok = 0;
		for (int i = 0; i < 4; ++i)
		{
			if (ok == 0) cub_Y_axis_counterclock();
			else  counterclock_Up();

			if (Front[2][2] == vector1[i])
			{
				counterclock_Right(); counterclock_Down(); clock_Right(); clock_Down();
				counterclock_Right(); counterclock_Down(); clock_Right(); clock_Down();
			}
			if (Right[2][2] == vector1[i])
			{
				counterclock_Right(); counterclock_Down(); clock_Right(); clock_Down();
				counterclock_Right(); counterclock_Down(); clock_Right(); clock_Down();
				ok += 1;
			}
		}
		if (Front[1][1] == 55) { counterclock_Up(); }
		if (Front[1][1] == 35) { clock_Up(); clock_Up(); }
		if (Front[1][1] == 5) { clock_Up(); }
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
