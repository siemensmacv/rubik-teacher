// pentru afisare
#include <iostream>
#include <iomanip>
#include <Windows.h>

// pentru testare
#include <functional>

// cubul efectiv
#include "Matrix.h"
#include "MatrixRepresentation_Map.h"
#include "RubiksCube.h"

template <class T>
auto maxNumberWidth(const IMatrix<T> & matrix) -> int
{
	int max = matrix.getNbColumns() * matrix.getNbRows();
	int  width = 0, cat = 1;
	while (max / cat != 0)
	{
		cat *= 10;
		++width;
	}
	return width;
}

template <class T>
auto printRow(IMatrix<T> & matrix, int row) -> void
{
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int colors[] = { 14, 12, 10, 13, 9, 15 };
	int width = maxNumberWidth(matrix) + 2;
	int prefix = 1;
	for (int i = 0; i < (width - 2); ++i)
		prefix *= 10;
	for (unsigned i = 0; i < matrix.getNbRows(); ++i)
	{
		int k = colors[matrix.elementAt(row, i) / prefix];
		SetConsoleTextAttribute(hConsole, k);
		std::cout << std::setw(width) << matrix.elementAt(row, i) % prefix;
	}
	SetConsoleTextAttribute(hConsole, 15);
}

template <class T>
auto print(MatrixRepresentation_Map<T> & m) -> void
{
	int numberWidth = maxNumberWidth(m.UpFace()) + 2;
	int size = m.UpFace().getNbRows();
	int matrixWidth = numberWidth * size;

	for (int i = 0; i < size; ++i)
	{
		std::cout << std::setw(matrixWidth) << " " << "  ";
		printRow(m.UpFace(), i);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		printRow(m.LeftFace(), i);
		std::cout << "  ";
		printRow(m.FrontFace(), i);
		std::cout << "  ";
		printRow(m.RightFace(), i);
		std::cout << "  ";
		printRow(m.BackFace(), i);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << std::setw(matrixWidth) << " " << "  ";
		printRow(m.DownFace(), i);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <class T>
auto test(ICubeMoves& obj,
	ICubeMoves& (ICubeMoves::*sens)(bool, unsigned),
	ICubeMoves& (ICubeMoves::*antisens)(bool, unsigned),
	MatrixRepresentation_Map<T> & rep,
	int size) -> void
{
	for (int b = 1; b > -1; --b)
		for (int i = 1; i <= size; ++i)
		{
			print(rep);
			std::invoke(sens, obj, static_cast<bool>(b), i);
			std::cout << std::endl << std::endl;
			print(rep);
			std::invoke(antisens, obj, static_cast<bool>(b), i);
			std::cout << std::endl << std::endl;
			std::cout << std::endl << std::endl;
		}
}

auto main() -> int
{
	int size = 1;
	auto getMatrix = [size](int face)
	{
		Matrix<int> m(size);

		int prefix = 1, width = maxNumberWidth(m);
		for (int i = 0; i < width; ++i)
			prefix *= 10;
		prefix *= face;

		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				m.elementAt(i, j) = prefix + size * i + j;

		return m;
	};

	MatrixRepresentation_Map<int> rep(getMatrix(0), getMatrix(3),
		getMatrix(2), getMatrix(5), getMatrix(1), getMatrix(4));

	RubiksCube<int> rubik(&rep);

	test(rubik, &ICubeMoves::frontClock, &ICubeMoves::frontCounterClock, rep, size);

	return 0;
}