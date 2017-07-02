#include "Board.h"

void Board::DrawCell(Location & loc)const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension, cellDimension);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//										Cube Drawing Code White
void Board::DrawCube(Location & loc)const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension*2, cellDimension*2);
	SpriteCodex::DrawBlockWhite(loc.x*cellDimension, loc.y*cellDimension, gfx);
	SpriteCodex::DrawBlockWhite(loc.x*cellDimension+cellDimension, loc.y*cellDimension, gfx);
	SpriteCodex::DrawBlockWhite(loc.x*cellDimension, loc.y*cellDimension+cellDimension, gfx);
	SpriteCodex::DrawBlockWhite(loc.x*cellDimension + cellDimension, loc.y*cellDimension+cellDimension, gfx);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//									Line Block Drawing Code Blue
void Board::DrawLineH(Location & loc)const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension * 3, cellDimension);
	for (int i = 0; i < 4; i++)
	{
		SpriteCodex::DrawBlockBlue(loc.x*cellDimension + (cellDimension*i), loc.y*cellDimension, gfx);
	}
}

void Board::DrawLineV(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension , cellDimension*3);
	for (int i = 0; i < 4; i++)
	{
		SpriteCodex::DrawBlockBlue(loc.x*cellDimension , loc.y*cellDimension+(cellDimension*i), gfx);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//												Draw T Code Red
void Board::DrawTD(Location & loc) const
{
	
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension * 3, cellDimension);
	for (int i = 0; i < 3; i++)
	{
		SpriteCodex::DrawBlockRed(loc.x*cellDimension + (cellDimension*i), loc.y*cellDimension, gfx);
	}
	gfx.DrawRectDim(loc.x*cellDimension+cellDimension, loc.y*cellDimension, cellDimension, cellDimension+cellDimension);
	SpriteCodex::DrawBlockRed(loc.x*cellDimension+cellDimension , loc.y*cellDimension, gfx);
	SpriteCodex::DrawBlockRed(loc.x*cellDimension + cellDimension, loc.y*cellDimension+cellDimension, gfx);
}

void Board::DrawTL(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension, cellDimension*3);
	for (int i = 0; i < 3; i++)
	{
	SpriteCodex::DrawBlockRed(loc.x*cellDimension , loc.y*cellDimension+ (cellDimension*i), gfx);
	}
	gfx.DrawRectDim(loc.x*cellDimension - cellDimension, loc.y*cellDimension+cellDimension, cellDimension, cellDimension);
	SpriteCodex::DrawBlockRed(loc.x*cellDimension - cellDimension, loc.y*cellDimension+cellDimension, gfx);
}

void Board::DrawTU(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension * 3, cellDimension);
	for (int i = 0; i < 3; i++)
	{
		SpriteCodex::DrawBlockRed(loc.x*cellDimension + (cellDimension*i), loc.y*cellDimension, gfx);
	}
	gfx.DrawRectDim(loc.x*cellDimension+cellDimension, loc.y*cellDimension-cellDimension, cellDimension, cellDimension + cellDimension);
	SpriteCodex::DrawBlockRed(loc.x*cellDimension + cellDimension, loc.y*cellDimension, gfx);
	SpriteCodex::DrawBlockRed(loc.x*cellDimension + cellDimension, loc.y*cellDimension - cellDimension, gfx);
}

void Board::DrawTR(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension, cellDimension * 3);
	for (int i = 0; i < 3; i++)
	{
		SpriteCodex::DrawBlockRed(loc.x*cellDimension, loc.y*cellDimension + (cellDimension*i), gfx);
	}
	gfx.DrawRectDim(loc.x*cellDimension + cellDimension, loc.y*cellDimension + cellDimension, cellDimension, cellDimension);
	SpriteCodex::DrawBlockRed(loc.x*cellDimension + cellDimension, loc.y*cellDimension + cellDimension, gfx);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         Draw Z Blocks Orange

void Board::DrawZH(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension*2, cellDimension);
	SpriteCodex::DrawBlockOrange(loc.x*cellDimension, loc.y*cellDimension, gfx);
	SpriteCodex::DrawBlockOrange(loc.x*cellDimension+cellDimension, loc.y*cellDimension, gfx);
	gfx.DrawRectDim(loc.x*cellDimension+cellDimension, loc.y*cellDimension+cellDimension, cellDimension * 2, cellDimension);
	SpriteCodex::DrawBlockOrange(loc.x*cellDimension+cellDimension, loc.y*cellDimension+cellDimension, gfx);
	SpriteCodex::DrawBlockOrange(loc.x*cellDimension + cellDimension*2, loc.y*cellDimension+cellDimension, gfx);
}

void Board::DrawZV(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension, cellDimension*2);
	SpriteCodex::DrawBlockOrange(loc.x*cellDimension, loc.y*cellDimension, gfx);
	SpriteCodex::DrawBlockOrange(loc.x*cellDimension, loc.y*cellDimension+cellDimension, gfx);
	gfx.DrawRectDim(loc.x*cellDimension + cellDimension, loc.y*cellDimension + cellDimension, cellDimension, cellDimension*2);
	SpriteCodex::DrawBlockOrange(loc.x*cellDimension + cellDimension, loc.y*cellDimension + cellDimension, gfx);
	SpriteCodex::DrawBlockOrange(loc.x*cellDimension + cellDimension, loc.y*cellDimension + cellDimension*2, gfx);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//														Draw 2 Blocks
void Board::Draw2H(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension*2, cellDimension);
	SpriteCodex::DrawBlockGreen(loc.x*cellDimension, loc.y*cellDimension, gfx);
	SpriteCodex::DrawBlockGreen(loc.x*cellDimension+cellDimension, loc.y*cellDimension, gfx);
	gfx.DrawRectDim(loc.x*cellDimension - cellDimension, loc.y*cellDimension + cellDimension, cellDimension * 2, cellDimension);
	SpriteCodex::DrawBlockGreen(loc.x*cellDimension-cellDimension, loc.y*cellDimension+cellDimension, gfx);
	SpriteCodex::DrawBlockGreen(loc.x*cellDimension, loc.y*cellDimension+cellDimension, gfx);
}

void Board::Draw2V(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension, cellDimension*2);
	SpriteCodex::DrawBlockGreen(loc.x*cellDimension, loc.y*cellDimension, gfx);
	SpriteCodex::DrawBlockGreen(loc.x*cellDimension, loc.y*cellDimension+cellDimension, gfx);
	gfx.DrawRectDim(loc.x*cellDimension-cellDimension, loc.y*cellDimension+cellDimension, cellDimension, cellDimension * 2);
	SpriteCodex::DrawBlockGreen(loc.x*cellDimension-cellDimension, loc.y*cellDimension+cellDimension, gfx);
	SpriteCodex::DrawBlockGreen(loc.x*cellDimension-cellDimension, loc.y*cellDimension + cellDimension*2, gfx);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Draw Left Side L Blocks
void Board::DrawLLL(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension, cellDimension * 3);
	for (int i = 0; i < 3; i++)
	{
		SpriteCodex::DrawBlockAqua(loc.x*cellDimension, loc.y*cellDimension + (cellDimension*i), gfx);
	}
	gfx.DrawRectDim(loc.x*cellDimension-cellDimension, loc.y*cellDimension+cellDimension*2, cellDimension, cellDimension);
	SpriteCodex::DrawBlockAqua(loc.x*cellDimension-cellDimension, loc.y*cellDimension + (cellDimension*2), gfx);
}

void Board::DrawLLU(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension * 3, cellDimension);
	for (int i = 0; i < 3; i++)
	{
		SpriteCodex::DrawBlockAqua(loc.x*cellDimension + (cellDimension*i), loc.y*cellDimension, gfx);
	}
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension - cellDimension, cellDimension, cellDimension);
	SpriteCodex::DrawBlockAqua(loc.x*cellDimension, loc.y*cellDimension-cellDimension, gfx);
}

void Board::DrawLLD(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension * 3, cellDimension);
	for (int i = 0; i < 3; i++)
	{
		SpriteCodex::DrawBlockAqua(loc.x*cellDimension + (cellDimension*i), loc.y*cellDimension, gfx);
	}
	gfx.DrawRectDim(loc.x*cellDimension+cellDimension*2, loc.y*cellDimension + cellDimension, cellDimension, cellDimension);
	SpriteCodex::DrawBlockAqua(loc.x*cellDimension + (cellDimension*2), loc.y*cellDimension+cellDimension, gfx);
}

void Board::DrawLLR(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension, cellDimension * 3);
	for (int i = 0; i < 3; i++)
	{
		SpriteCodex::DrawBlockAqua(loc.x*cellDimension, loc.y*cellDimension + (cellDimension*i), gfx);
	}
	gfx.DrawRectDim(loc.x*cellDimension + cellDimension , loc.y*cellDimension , cellDimension, cellDimension);
	SpriteCodex::DrawBlockAqua(loc.x*cellDimension + cellDimension, loc.y*cellDimension, gfx);
}

void Board::DrawRLR(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension, cellDimension * 3);
	for (int i = 0; i < 3; i++)
	{
		SpriteCodex::DrawBlockBrown(loc.x*cellDimension, loc.y*cellDimension + (cellDimension*i), gfx);
	}
	gfx.DrawRectDim(loc.x*cellDimension + cellDimension, loc.y*cellDimension + cellDimension * 2, cellDimension, cellDimension);
	SpriteCodex::DrawBlockBrown(loc.x*cellDimension + cellDimension, loc.y*cellDimension + (cellDimension * 2), gfx);
}

void Board::DrawRLD(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension * 3, cellDimension);
	for (int i = 0; i < 3; i++)
	{
		SpriteCodex::DrawBlockBrown(loc.x*cellDimension + (cellDimension*i), loc.y*cellDimension, gfx);
	}
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension + cellDimension, cellDimension, cellDimension);
	SpriteCodex::DrawBlockBrown(loc.x*cellDimension, loc.y*cellDimension + cellDimension, gfx);
}

void Board::DrawRLL(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension, cellDimension * 3);
	for (int i = 0; i < 3; i++)
	{
		SpriteCodex::DrawBlockBrown(loc.x*cellDimension, loc.y*cellDimension + (cellDimension*i), gfx);
	}
	gfx.DrawRectDim(loc.x*cellDimension - cellDimension, loc.y*cellDimension, cellDimension, cellDimension);
	SpriteCodex::DrawBlockBrown(loc.x*cellDimension - cellDimension, loc.y*cellDimension, gfx);
}

void Board::DrawRLU(Location & loc) const
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension * 3, cellDimension);
	for (int i = 0; i < 3; i++)
	{
		SpriteCodex::DrawBlockBrown(loc.x*cellDimension + (cellDimension*i), loc.y*cellDimension, gfx);
	}
	gfx.DrawRectDim(loc.x*cellDimension+cellDimension*2, loc.y*cellDimension - cellDimension, cellDimension, cellDimension);
	SpriteCodex::DrawBlockBrown(loc.x*cellDimension+cellDimension*2, loc.y*cellDimension - cellDimension, gfx);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//												Draw the Board Layout
void Board::DrawWall()
{
	gfx.DrawRectDim(cellDimension*6, 0, cellDimension, cellDimension * 30); //Draw Left Wall
	for (int i = 0; i < cellDimension+10; i++)
	{
		SpriteCodex::DrawBlockWall(cellDimension*6, 0+(cellDimension*i), gfx);
	}
	gfx.DrawRectDim(cellDimension * 28, 0, cellDimension, cellDimension * 30); //Draw Right Wall
	for (int i = 0; i < cellDimension + 10; i++)
	{
		SpriteCodex::DrawBlockWall(cellDimension * 28, 0 + (cellDimension*i), gfx);
	}
	gfx.DrawRectDim(cellDimension *6, cellDimension*29, cellDimension*23, cellDimension); //Draw Bottom Wall
	for (int i = 6; i < 29; i++)
	{
		SpriteCodex::DrawBlockWall(cellDimension * i, cellDimension*29, gfx);
	}
	gfx.DrawRectDim(cellDimension * 6, cellDimension * 28, cellDimension * 29, cellDimension); //Draw Bottom Wall
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

