#pragma once
#include "Graphics.h"
#include "Location.h"
class Board
{
private:
	static constexpr int cellDimension= 20;
	static constexpr int callWidth = 20;
	static constexpr int cellHeight = 20;
	static constexpr int cellpadding = 2;
	static constexpr int x_offset = 30;
	static constexpr int y_offset = 30;
	Graphics& gfx;
public:
	void DrawCell(Location& loc, Color c); 
	void DrawCellTwo(Location& loc, Color c);
	void DrawWall(Color c);
	Board(Graphics &gfx);
};

