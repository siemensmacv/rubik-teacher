#pragma once

class ICubeMoves
{
public:
	virtual auto frontClock(bool isSliceTurn = true, unsigned sliceNb = 1)        -> ICubeMoves & = 0;
	virtual auto frontCounterClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & = 0;
	virtual auto backClock(bool isSliceTurn = true, unsigned sliceNb = 1)         -> ICubeMoves & = 0;
	virtual auto backCounterClock(bool isSliceTurn = true, unsigned sliceNb = 1)  -> ICubeMoves & = 0;
	virtual auto upClock(bool isSliceTurn = true, unsigned sliceNb = 1)           -> ICubeMoves & = 0;
	virtual auto upCounterClock(bool isSliceTurn = true, unsigned sliceNb = 1)    -> ICubeMoves & = 0;
	virtual auto downClock(bool isSliceTurn = true, unsigned sliceNb = 1)         -> ICubeMoves & = 0;
	virtual auto downCounterClock(bool isSliceTurn = true, unsigned sliceNb = 1)  -> ICubeMoves & = 0;
	virtual auto leftClock(bool isSliceTurn = true, unsigned sliceNb = 1)         -> ICubeMoves & = 0;
	virtual auto leftCounterClock(bool isSliceTurn = true, unsigned sliceNb = 1)  -> ICubeMoves & = 0;
	virtual auto rightClock(bool isSliceTurn = true, unsigned sliceNb = 1)        -> ICubeMoves & = 0;
	virtual auto rightCounterClock(bool isSliceTurn = true, unsigned sliceNb = 1) -> ICubeMoves & = 0;

	// optional functii pentru rotiri complete
	// tehnic sunt apeluri simple cu parametrii false si sliceNb == size
};