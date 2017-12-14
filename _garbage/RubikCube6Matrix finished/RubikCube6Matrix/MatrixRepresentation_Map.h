#pragma once
#include "IMatrixRepresentation.h"
#include "Matrix.h"
#include "rubikface.h"
#include <map>

template<class T>
class MatrixRepresentation_Map :
	public IMatrixRepresentation<T>
{
	std::map< RubikFace, Matrix<T> > m_facesMap;

public:
	MatrixRepresentation_Map() {}
	MatrixRepresentation_Map(const Matrix<T> & upFace,
							 const Matrix<T> & rightFace,
							 const Matrix<T> & frontFace,
							 const Matrix<T> & downFace,
							 const Matrix<T> & leftFace,
							 const Matrix<T> & backFace)
	{
		insert(RubikFace::Up,    upFace);
		insert(RubikFace::Right, rightFace);
		insert(RubikFace::Front, frontFace);
		insert(RubikFace::Down,  downFace);
		insert(RubikFace::Left,  leftFace);
		insert(RubikFace::Back,  backFace);
	}
	~MatrixRepresentation_Map()	{}

	auto insert(const RubikFace & face, const Matrix<T> & matrix) ->MatrixRepresentation_Map<T> &
	{
		m_facesMap.emplace(face, matrix);
		return *this;
	}
	
	// Inherited via IMatrixRepresentation
	auto UpFace()->IMatrix<T>& override
	{
		return m_facesMap[RubikFace::Up];
	}
	auto DownFace()->IMatrix<T>& override
	{
		return m_facesMap[RubikFace::Down];
	}
	auto LeftFace()->IMatrix<T>& override
	{
		return m_facesMap[RubikFace::Left];
	}
	auto RightFace()->IMatrix<T>& override
	{
		return m_facesMap[RubikFace::Right];
	}
	auto FrontFace()->IMatrix<T>& override
	{
		return m_facesMap[RubikFace::Front];
	}
	auto BackFace()->IMatrix<T>& override
	{
		return m_facesMap[RubikFace::Back];
	}

};

