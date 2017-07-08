#pragma once
#include "Graphics.h"
#include "Location.h"
#include "SpriteCodex.h"
class Board
{
private:

	static constexpr int cellWidth = 10;
	static constexpr int cellHeight = 10;
	static constexpr int cellDimension = cellWidth+cellHeight;
	Graphics& gfx;
public:
	void DrawCell(Location& loc, Color c)const; 
	void DrawCube(Location& loc)const;
	void DrawLineH(Location& loc)const;
	void DrawTD(Location& loc)const;
	void DrawZH(Location& loc)const;
	void Draw2H(Location& loc)const;
	void DrawLLL(Location& loc)const;
	void DrawRLR(Location& loc)const;
	void DrawWall();
	Board(Graphics &gfx);
};

