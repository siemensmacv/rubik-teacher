#pragma once

class IDeepMoves
{
public:
	virtual auto frontClock_Deep(int nbOfSlices = 1)        ->IDeepMoves & = 0;
	virtual auto frontCounterClock_Deep(int nbOfSlices = 1) ->IDeepMoves & = 0;
	virtual auto backClock_Deep(int nbOfSlices = 1)         ->IDeepMoves & = 0;
	virtual auto backCounterClock_Deep(int nbOfSlices = 1)  ->IDeepMoves & = 0;
	virtual auto upClock_Deep(int nbOfSlices = 1)           ->IDeepMoves & = 0;
	virtual auto upCounterClock_Deep(int nbOfSlices = 1)    ->IDeepMoves & = 0;
	virtual auto downClock_Deep(int nbOfSlices = 1)         ->IDeepMoves & = 0;
	virtual auto downCounterClock_Deep(int nbOfSlices = 1)  ->IDeepMoves & = 0;
	virtual auto leftClock_Deep(int nbOfSlices = 1)         ->IDeepMoves & = 0;
	virtual auto leftCounterClock_Deep(int nbOfSlices = 1)  ->IDeepMoves & = 0;
	virtual auto rightClock_Deep(int nbOfSlices = 1)        ->IDeepMoves & = 0;
	virtual auto rightCounterClock_Deep(int nbOfSlices = 1) ->IDeepMoves & = 0;
};