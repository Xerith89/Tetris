#pragma once
#include "Graphics.h"
#include "Location.h"
class Board
{
private:

	static constexpr int cellWidth = 10;
	static constexpr int cellHeight = 10;
	static constexpr int cellDimension = cellWidth+cellHeight;
	Graphics& gfx;
public:
	void DrawCell(Location& loc, Color c); 
	void DrawWall(Color c);
	Board(Graphics &gfx);
};

