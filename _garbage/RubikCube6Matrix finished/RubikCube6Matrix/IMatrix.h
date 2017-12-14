#pragma once
template <class T>
class IMatrix
{
public:
	virtual auto getNbRows() const    -> unsigned = 0;
	virtual auto getNbColumns() const -> unsigned = 0;
	virtual auto rotate90Clock()        -> IMatrix & = 0;
	virtual auto rotate90Counterclock() -> IMatrix & = 0;
	virtual auto elementAt(unsigned row, unsigned column) -> T& = 0;
};