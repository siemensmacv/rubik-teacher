#pragma once
#include <fstream>
#include <iomanip>
#include <random>
#include <ctime>
#include <string>
using namespace std;
typedef int** fata_cub;

class Cub_Rubik
{
	fata_cub Front, Back, Up, Down, Left, Right;
	string solution;
public:
	Cub_Rubik();
	~Cub_Rubik();
private:
	inline void swap(int& a, int& b);
	inline fata_cub& matr_clock(fata_cub& m);
	inline fata_cub& matr_counterclock(fata_cub& m);
	inline void clock(fata_cub& centru, fata_cub& sus, fata_cub& jos, fata_cub& stanga, fata_cub& dreapta);
	inline void counterclock(fata_cub& centru, fata_cub& sus, fata_cub& jos, fata_cub& stanga, fata_cub& dreapta);
public:
	void clock_Front();
	void counterclock_Front();
	void clock_Back();
	void counterclock_Back();
	void clock_Up();
	void counterclock_Up();
	void clock_Down();
	void counterclock_Down();
	void clock_Left();
	void counterclock_Left();
	void clock_Right();
	void counterclock_Right();
	void cub_X_axis_stanga();
	void cub_X_axis_dreapta();
	void cub_Y_axis_clock();
	void cub_Y_axis_counterclock();
	void cub_Z_axis_inainte();
	void cub_Z_axis_inapoi();
	void repozitionare_cub();
	int middle_layer(int origine, int poz_anter, int ordin_recurs);
	void Scramble();
	void Solve();
	friend ofstream& operator << (ofstream& out, Cub_Rubik& cub);
};
