#include "Board.h"

void Board::DrawCell(Location & loc,Color c)const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension, cellDimension, c);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//										Cube Drawing Code White
void Board::DrawCube(Location & loc)const
{
	DrawCell(loc, Colors::White);
	SpriteCodex::DrawBlockWhite(loc.x*cellDimension, loc.y*cellDimension, gfx);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//									Line Block Drawing Code Blue
void Board::DrawLineH(Location & loc)const
{
	Location middleleft;
	Location middleright;
	Location right;
	middleleft.x = loc.x + 1;
	middleleft.y = loc.y;
	middleright.x = middleleft.x + 1;
	middleright.y = middleleft.y;
	right.x = middleright.x + 1;
	right.y = middleright.y;
	DrawCell(loc, Colors::Cyan);
	DrawCell(middleleft, Colors::Cyan);
	DrawCell(middleright, Colors::Cyan);
	DrawCell(right, Colors::Cyan);
	SpriteCodex::DrawBlockAqua(loc.x*cellDimension, loc.y*cellDimension, gfx);
	SpriteCodex::DrawBlockAqua(middleleft.x*cellDimension, middleleft.y*cellDimension, gfx);
	SpriteCodex::DrawBlockAqua(middleright.x*cellDimension, middleright.y*cellDimension, gfx);
	SpriteCodex::DrawBlockAqua(right.x*cellDimension, right.y*cellDimension, gfx);
}

void Board::DrawLineV(Location & loc) const
{
	Location middleleft;
	Location middleright;
	Location right;
	middleleft.x = loc.x;
	middleleft.y = loc.y-1;
	middleright.x = middleleft.x;
	middleright.y = middleleft.y-1;
	right.x = middleright.x;
	right.y = middleright.y-1;
	DrawCell(loc, Colors::Cyan);
	DrawCell(middleleft, Colors::Cyan);
	DrawCell(middleright, Colors::Cyan);
	DrawCell(right, Colors::Cyan);
	SpriteCodex::DrawBlockAqua(loc.x*cellDimension, loc.y*cellDimension, gfx);
	SpriteCodex::DrawBlockAqua(middleleft.x*cellDimension, middleleft.y*cellDimension, gfx);
	SpriteCodex::DrawBlockAqua(middleright.x*cellDimension, middleright.y*cellDimension, gfx);
	SpriteCodex::DrawBlockAqua(right.x*cellDimension, right.y*cellDimension, gfx);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//												Draw T Code Red
void Board::DrawTD(Location & loc) const
{
	Location left;
	Location middle;
	Location right;
	left.x = loc.x-1;
	left.y = loc.y-1;
	middle.x = loc.x;
	middle.y = loc.y - 1;
	right.x = loc.x+1;
	right.y = loc.y - 1;
	DrawCell(loc, Colors::Gray); 	
	DrawCell(left, Colors::Gray);
	DrawCell(middle, Colors::Gray);
	DrawCell(right, Colors::Gray);
}

void Board::DrawTRotLeft(Location & loc) const
{
	Location tee;
	Location middle;
	Location top;
	middle.x = loc.x;
	middle.y = loc.y-1;
	top.x = middle.x;
	top.y = middle.y - 1;
	tee.x = middle.x - 1;
	tee.y = middle.y;
	DrawCell(loc, Colors::Gray);
	DrawCell(middle, Colors::Gray);
	DrawCell(top, Colors::Gray);
	DrawCell(tee, Colors::Gray);
}

void Board::DrawTRotUp(Location & loc) const
{
	Location tee;
	Location middle;
	Location right;
	
	middle.x = loc.x+1;
	middle.y = loc.y;
	right.x = middle.x + 1;
	right.y = middle.y;
	tee.x = middle.x;
	tee.y = middle.y - 1;
	DrawCell(loc, Colors::Gray);
	DrawCell(tee, Colors::Gray);
	DrawCell(middle, Colors::Gray);
	DrawCell(right, Colors::Gray);
}

void Board::DrawTRotRight(Location & loc) const
{
	Location tee;
	Location middle;
	Location top;
	middle = { loc.x,loc.y - 1 };
	top.x = middle.x;
	top.y = middle.y - 1;
	tee.x = middle.x + 1;
	tee.y = middle.y;
	DrawCell(loc, Colors::Gray);
	DrawCell(middle, Colors::Gray);
	DrawCell(top, Colors::Gray);
	DrawCell(tee, Colors::Gray);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         Draw Z Blocks Orange

void Board::DrawZH(Location & loc) const
{
	Location bottomright;
	Location topleft;
	Location topright;
	bottomright = { loc.x + 1,loc.y };
	topright = { loc.x,loc.y-1 };
	topleft = { topright.x - 1,topright.y };
	DrawCell(loc, Colors::Green);
	DrawCell(bottomright, Colors::Green);
	DrawCell(topleft, Colors::Green);
	DrawCell(topright, Colors::Green);
	
}

void Board::DrawZV(Location & loc) const
{
	Location bottommiddle;
	Location topmiddle;
	Location top;
	bottommiddle = { loc.x,loc.y - 1 };
	topmiddle = { bottommiddle.x + 1,bottommiddle.y };
	top = { topmiddle.x,topmiddle.y-1 };
	DrawCell(loc, Colors::Green);
	DrawCell(bottommiddle, Colors::Green);
	DrawCell(topmiddle, Colors::Green);
	DrawCell(top, Colors::Green);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//														Draw 2 Blocks
void Board::Draw2H(Location & loc) const
{
	Location bottomright;
	Location topleft;
	Location topright;
	bottomright = { loc.x + 1,loc.y };
	topleft = { bottomright.x,bottomright.y - 1 };
	topright = { topleft.x + 1,topleft.y };
	DrawCell(loc, Colors::Yellow);
	DrawCell(bottomright, Colors::Yellow);
	DrawCell(topleft, Colors::Yellow);
	DrawCell(topright, Colors::Yellow);
	
}
void Board::Draw2V(Location & loc) const
{
	Location bottommiddle;
	Location topmiddle;
	Location top;
	bottommiddle = { loc.x,loc.y-1 };
	topmiddle = { bottommiddle.x-1,bottommiddle.y };
	top = { topmiddle.x,topmiddle.y-1 };
	DrawCell(loc, Colors::Yellow);
	DrawCell(bottommiddle, Colors::Yellow);
	DrawCell(topmiddle, Colors::Yellow);
	DrawCell(top, Colors::Yellow);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Draw Left Side L Blocks
void Board::DrawLLL(Location & loc) const
{
	Location bottomleft;
	Location bottommiddle;
	Location topmiddle;
	Location top;
	bottomleft = { loc.x-1,loc.y };
	bottommiddle = { loc.x,loc.y-1 };
	top = { bottommiddle.x,bottommiddle.y - 1 };
	DrawCell(loc, Colors::Red);
	DrawCell(bottomleft, Colors::Red);
	DrawCell(bottommiddle, Colors::Red);
	DrawCell(top, Colors::Red);
}
/////////////////////////////////////////////////////////////////////////
//									Draw Right Side L Blocks
void Board::DrawRLR(Location & loc) const
{
	Location bottomright;
	Location bottommiddle;
	Location topmiddle;
	Location top;
	bottomright = { loc.x + 1,loc.y };
	bottommiddle = { loc.x,loc.y - 1 };
	top = { bottommiddle.x,bottommiddle.y - 1 };
	DrawCell(loc, Colors::Blue);
	DrawCell(bottomright, Colors::Blue);
	DrawCell(bottommiddle, Colors::Blue);
	DrawCell(top, Colors::Blue);
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//												Draw the Board Layout
void Board::DrawWall()
{
	gfx.DrawRectDim(cellDimension*6, 0, cellDimension, cellDimension * 30,Colors::Black); //Draw Left Wall
	for (int i = 0; i < cellDimension+10; i++)
	{
		SpriteCodex::DrawBlockWall(cellDimension*6, 0+(cellDimension*i), gfx);
	}
	gfx.DrawRectDim(cellDimension * 28, 0, cellDimension, cellDimension * 30, Colors::Black); //Draw Right Wall
	for (int i = 0; i < cellDimension + 10; i++)
	{
		SpriteCodex::DrawBlockWall(cellDimension * 28, 0 + (cellDimension*i), gfx);
	}
	gfx.DrawRectDim(cellDimension *6, cellDimension*29, cellDimension*23, cellDimension, Colors::Black); //Draw Bottom Wall
	for (int i = 6; i < 29; i++)
	{
		SpriteCodex::DrawBlockWall(cellDimension * i, cellDimension*29, gfx);
	}
	gfx.DrawRectDim(cellDimension * 6, cellDimension * 28, cellDimension * 29, cellDimension, Colors::Black); //Draw Bottom Wall
	for (int i = 6; i < 29; i++)
	{
		SpriteCodex::DrawBlockWall(cellDimension * i, cellDimension * 28, gfx);
	}
	for (int i = 29; i < 40; i++)
	{
		SpriteCodex::DrawBlockWall(cellDimension * i, cellDimension * 17, gfx);
		SpriteCodex::DrawBlockWall(cellDimension * i, cellDimension * 18, gfx);
	}
	for (int i = 29; i < 40; i++)
	{
		SpriteCodex::DrawBlockWall(cellDimension * i, cellDimension * 10, gfx);
		SpriteCodex::DrawBlockWall(cellDimension * i, cellDimension * 11, gfx);
	}
	for (int i = 29; i < 40; i++)
	{
		SpriteCodex::DrawBlockWall(cellDimension * i, cellDimension-cellDimension, gfx);
	}
	for (int i = 29; i < 40; i++)
	{
		SpriteCodex::DrawBlockWall(cellDimension * i, cellDimension *29, gfx);
	}
	for (int i = 0; i < cellDimension + 10; i++)
	{
		SpriteCodex::DrawBlockWall(cellDimension * 39, cellDimension * i, gfx);
	}
	SpriteCodex::DrawLinesText(cellDimension * 29, cellDimension * 12, gfx);
	SpriteCodex::DrawNextText(cellDimension * 29, cellDimension * 19, gfx);
}


Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
	
}

