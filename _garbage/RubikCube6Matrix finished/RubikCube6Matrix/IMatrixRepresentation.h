#pragma once
#include "IMatrix.h"

template<class T>
class IMatrixRepresentation
{
public:
	virtual auto UpFace()    -> IMatrix<T> & = 0;
	virtual auto DownFace()  -> IMatrix<T> & = 0;
	virtual auto LeftFace()  -> IMatrix<T> & = 0;
	virtual auto RightFace() -> IMatrix<T> & = 0;
	virtual auto FrontFace() -> IMatrix<T> & = 0;
	virtual auto BackFace()  -> IMatrix<T> & = 0;
};