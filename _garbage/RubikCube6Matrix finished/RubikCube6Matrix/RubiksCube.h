#pragma once
#include "IMatrixRepresentation.h"
#include "ICubeMoves.h"
#include <utility>

// Type T shall be move-constructible and move-assignable because std::swap is used.
// Custom overloads of swap declared in the same namespace as the type for which they
// are provided get selected over this generic version. 
template <class T>
class RubiksCube : public ICubeMoves
{
	IMatrixRepresentation<T> * m_data;
	unsigned m_size;

	void swap4RowsOnSidesClock(IMatrix<T> & up, IMatrix<T> & right, IMatrix<T> & down, IMatrix<T> & left, unsigned nthSlice)
	{
		for (unsigned i = 0; i < m_size; ++i)
		{
			// swapping up and right => up in correct position
			std::swap(up.elementAt(m_size - nthSlice, i), right.elementAt(i, nthSlice - 1));

			// swapping up (values from right) with down => right in correct position
			std::swap(up.elementAt(m_size - nthSlice, i), down.elementAt(nthSlice - 1, m_size - 1 - i));

			//swapping up (values from down) with left => down and left in correct positions
			std::swap(up.elementAt(m_size - nthSlice, i), left.elementAt(m_size - 1 - i, m_size - nthSlice));
		}
	}

	void swap4RowsOnSidesCounterClock(IMatrix<T> & up, IMatrix<T> & left, IMatrix<T> & down, IMatrix<T> & right, unsigned nthSlice)
	{
		for (unsigned i = 0; i < m_size; ++i)
		{
			// swapping up and left => up in correct position
			std::swap(up.elementAt(m_size - nthSlice, i), left.elementAt(m_size - 1 - i, m_size - nthSlice));

			// swapping up (values from left) with down => left in correct position
			std::swap(up.elementAt(m_size - nthSlice, i), down.elementAt(nthSlice - 1, m_size - 1 - i));

			//swapping up (values from down) with right => down and right in correct positions
			std::swap(up.elementAt(m_size - nthSlice, i), right.elementAt(i, nthSlice - 1));
		}
	}

	void faceClock(IMatrix<T> & front, IMatrix<T> & up, IMatrix<T> & right, 
		IMatrix<T> & down, IMatrix<T> & left, IMatrix<T> & back, bool isSliceTurn, unsigned sliceNb)
	{
		if (sliceNb < 1 || sliceNb > m_size)
			return;
		if (!isSliceTurn || sliceNb == 1)
			front.rotate90Clock();
		for (unsigned i = isSliceTurn ? sliceNb : 1; i <= sliceNb; ++i)
			swap4RowsOnSidesClock(up, right, down, left, i);
		if (sliceNb == m_size)
			back.rotate90Counterclock();
	}

	void faceCounterClock(IMatrix<T> & front, IMatrix<T> & up, IMatrix<T> & left,
		IMatrix<T> & down, IMatrix<T> & right, IMatrix<T> & back, bool isSliceTurn, unsigned sliceNb)
	{
		if (sliceNb < 1 || sliceNb > m_size)
			return;
		if (!isSliceTurn || sliceNb == 1)
			front.rotate90Counterclock();
		for (unsigned i = isSliceTurn ? sliceNb : 1; i <= sliceNb; ++i)
			swap4RowsOnSidesCounterClock(up, left, down, right, i);
		if (sliceNb == m_size)
			back.rotate90Clock();
	}

public:
	RubiksCube(IMatrixRepresentation<T> * cubeData)
		:m_data{ cubeData }, m_size{ cubeData->UpFace().getNbRows() }
	{}
	~RubiksCube() {}

	// Inherited via ICubeMoves
	auto frontClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & override
	{
		faceClock(m_data->FrontFace(), m_data->UpFace(), m_data->RightFace(),
			m_data->DownFace(), m_data->LeftFace(), m_data->BackFace(), isSliceTurn, sliceNb);
		return *this;
	}

	auto frontCounterClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & override
	{
		faceCounterClock(m_data->FrontFace(), m_data->UpFace(), m_data->LeftFace(),
			m_data->DownFace(), m_data->RightFace(), m_data->BackFace(), isSliceTurn, sliceNb);
		return *this;
	}

	auto backClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & override
	{
		m_data->UpFace().rotate90Clock().rotate90Clock();
		m_data->DownFace().rotate90Clock().rotate90Clock();

		faceClock(m_data->BackFace(), m_data->UpFace(), m_data->LeftFace(),
			m_data->DownFace(), m_data->RightFace(), m_data->FrontFace(), isSliceTurn, sliceNb);

		m_data->UpFace().rotate90Clock().rotate90Clock();
		m_data->DownFace().rotate90Clock().rotate90Clock();
		return *this;
	}

	auto backCounterClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & override
	{
		m_data->UpFace().rotate90Clock().rotate90Clock();
		m_data->DownFace().rotate90Clock().rotate90Clock();

		faceCounterClock(m_data->BackFace(), m_data->UpFace(), m_data->RightFace(),
			m_data->DownFace(), m_data->LeftFace(), m_data->FrontFace(), isSliceTurn, sliceNb);

		m_data->UpFace().rotate90Clock().rotate90Clock();
		m_data->DownFace().rotate90Clock().rotate90Clock();
		return *this;
	}

	auto upClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & override
	{
		m_data->LeftFace().rotate90Clock();
		m_data->RightFace().rotate90Counterclock();
		m_data->BackFace().rotate90Clock().rotate90Clock();
		m_data->DownFace().rotate90Clock().rotate90Clock();

		faceClock(m_data->UpFace(), m_data->BackFace(), m_data->RightFace(),
			m_data->FrontFace(), m_data->LeftFace(), m_data->DownFace(), isSliceTurn, sliceNb);

		m_data->LeftFace().rotate90Counterclock();
		m_data->RightFace().rotate90Clock();
		m_data->BackFace().rotate90Clock().rotate90Clock();
		m_data->DownFace().rotate90Clock().rotate90Clock();
		return *this;
	}

	auto upCounterClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & override
	{
		m_data->LeftFace().rotate90Clock();
		m_data->RightFace().rotate90Counterclock();
		m_data->BackFace().rotate90Clock().rotate90Clock();
		m_data->DownFace().rotate90Clock().rotate90Clock();

		faceCounterClock(m_data->UpFace(), m_data->BackFace(), m_data->LeftFace(),
			m_data->FrontFace(), m_data->RightFace(), m_data->DownFace(), isSliceTurn, sliceNb);

		m_data->LeftFace().rotate90Counterclock();
		m_data->RightFace().rotate90Clock();
		m_data->BackFace().rotate90Clock().rotate90Clock();
		m_data->DownFace().rotate90Clock().rotate90Clock();
		return *this;
	}

	auto downClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & override
	{
		m_data->LeftFace().rotate90Counterclock();
		m_data->RightFace().rotate90Clock();
		m_data->BackFace().rotate90Clock().rotate90Clock();
		m_data->UpFace().rotate90Clock().rotate90Clock();

		faceClock(m_data->DownFace(), m_data->FrontFace(), m_data->RightFace(),
			m_data->BackFace(), m_data->LeftFace(), m_data->UpFace(), isSliceTurn, sliceNb);

		m_data->LeftFace().rotate90Clock();
		m_data->RightFace().rotate90Counterclock();
		m_data->BackFace().rotate90Clock().rotate90Clock();
		m_data->UpFace().rotate90Clock().rotate90Clock();
		return *this;
	}

	auto downCounterClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & override
	{
		m_data->LeftFace().rotate90Counterclock();
		m_data->RightFace().rotate90Clock();
		m_data->BackFace().rotate90Clock().rotate90Clock();
		m_data->UpFace().rotate90Clock().rotate90Clock();

		faceCounterClock(m_data->DownFace(), m_data->FrontFace(), m_data->LeftFace(),
			m_data->BackFace(), m_data->RightFace(), m_data->UpFace(), isSliceTurn, sliceNb);

		m_data->LeftFace().rotate90Clock();
		m_data->RightFace().rotate90Counterclock();
		m_data->BackFace().rotate90Clock().rotate90Clock();
		m_data->UpFace().rotate90Clock().rotate90Clock();
		return *this;
	}

	auto leftClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & override
	{
		m_data->UpFace().rotate90Counterclock();
		m_data->DownFace().rotate90Clock();

		faceClock(m_data->LeftFace(), m_data->UpFace(), m_data->FrontFace(),
			m_data->DownFace(), m_data->BackFace(), m_data->RightFace(), isSliceTurn, sliceNb);

		m_data->UpFace().rotate90Clock();
		m_data->DownFace().rotate90Counterclock();
		return *this;
	}

	auto leftCounterClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & override
	{
		m_data->UpFace().rotate90Counterclock();
		m_data->DownFace().rotate90Clock();

		faceCounterClock(m_data->LeftFace(), m_data->UpFace(), m_data->BackFace(),
			m_data->DownFace(), m_data->FrontFace(), m_data->RightFace(), isSliceTurn, sliceNb);

		m_data->UpFace().rotate90Clock();
		m_data->DownFace().rotate90Counterclock();
		return *this;
	}

	auto rightClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & override
	{
		m_data->UpFace().rotate90Clock();
		m_data->DownFace().rotate90Counterclock();

		faceClock(m_data->RightFace(), m_data->UpFace(), m_data->BackFace(),
			m_data->DownFace(), m_data->FrontFace(), m_data->LeftFace(), isSliceTurn, sliceNb);

		m_data->UpFace().rotate90Counterclock();
		m_data->DownFace().rotate90Clock();
		return *this;
	}

	auto rightCounterClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & override
	{
		m_data->UpFace().rotate90Clock();
		m_data->DownFace().rotate90Counterclock();

		faceCounterClock(m_data->RightFace(), m_data->UpFace(), m_data->FrontFace(),
			m_data->DownFace(), m_data->BackFace(), m_data->LeftFace(), isSliceTurn, sliceNb);

		m_data->UpFace().rotate90Counterclock();
		m_data->DownFace().rotate90Clock();
		return *this;
	}

};