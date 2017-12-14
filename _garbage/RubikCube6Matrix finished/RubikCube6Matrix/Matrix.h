#pragma once
#include "IMatrix.h"
#include <vector>

template<class T>
class Matrix : public IMatrix<T>
{
	std::vector< std::vector<T> > m_matrix;
	unsigned m_nbRows, m_nbColumns;

public:
	Matrix(unsigned nbRows, unsigned nbColumns)
		: m_nbRows{nbRows}, m_nbColumns{nbColumns}, m_matrix(nbRows, std::vector<T>(nbColumns))
	{
	}
	Matrix(unsigned size = 0) : Matrix(size, size)
	{
	}
	~Matrix()
	{
	}

	// Inherited via IMatrix
	auto getNbRows() const -> unsigned override
	{
		return m_nbRows;
	}

	auto getNbColumns() const -> unsigned override
	{
		return m_nbColumns;
	}

	auto elementAt(unsigned row, unsigned column) -> T& override
	{
		return m_matrix[row][column];
	}

	auto rotate90Clock() -> IMatrix & override
	{
		auto aux = m_matrix;
		for (unsigned i = 0; i < m_nbRows; ++i)
			for (unsigned j = 0; j < m_nbColumns; ++j)
				m_matrix[j][m_nbColumns - 1 - i] = aux[i][j];
		
		return *this;
	}

	auto rotate90Counterclock() -> IMatrix & override
	{
		auto aux = m_matrix;
		for (unsigned i = 0; i < m_nbRows; ++i)
			for (unsigned j = 0; j < m_nbColumns; ++j)
				m_matrix[m_nbRows - 1 - j][i] = aux[i][j];

		return *this;
	}

};

