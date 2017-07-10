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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         Draw Z Blocks Orange

void Board::DrawZH(Location & loc) const
{
	DrawCell(loc, Colors::Yellow);
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//														Draw 2 Blocks
void Board::Draw2H(Location & loc) const
{
	DrawCell(loc, Colors::Green);
	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Draw Left Side L Blocks
void Board::DrawLLL(Location & loc) const
{
	DrawCell(loc, Colors::Red);
	
}
/////////////////////////////////////////////////////////////////////////
//									Draw Right Side L Blocks
void Board::DrawRLR(Location & loc) const
{
	DrawCell(loc, Colors::Blue);
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

