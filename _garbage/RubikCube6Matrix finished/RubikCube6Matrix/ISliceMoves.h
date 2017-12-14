#pragma once

class ISliceMoves
{
public:
	virtual auto frontClock(int nthSlice = 1)		 -> ISliceMoves & = 0;
	virtual auto frontCounterClock(int nthSlice = 1) -> ISliceMoves & = 0;
	virtual auto backClock(int nthSlice = 1)		 -> ISliceMoves & = 0;
	virtual auto backCounterClock(int nthSlice = 1)	 -> ISliceMoves & = 0;
	virtual auto upClock(int nthSlice = 1)			 -> ISliceMoves & = 0;
	virtual auto upCounterClock(int nthSlice = 1)	 -> ISliceMoves & = 0;
	virtual auto downClock(int nthSlice = 1)		 -> ISliceMoves & = 0;
	virtual auto downCounterClock(int nthSlice = 1)	 -> ISliceMoves & = 0;
	virtual auto leftClock(int nthSlice = 1)		 -> ISliceMoves & = 0;
	virtual auto leftCounterClock(int nthSlice = 1)	 -> ISliceMoves & = 0;
	virtual auto rightClock(int nthSlice = 1)		 -> ISliceMoves & = 0;
	virtual auto rightCounterClock(int nthSlice = 1) -> ISliceMoves & = 0;
};