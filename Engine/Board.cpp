#include "Board.h"

void Board::DrawCell(Location & loc, Color c)
{
	gfx.DrawRectDim(loc.x*cellDimension, loc.y*cellDimension, cellDimension, cellDimension, c);
}

void Board::DrawCellTwo(Location & loc, Color c)
{
	gfx.DrawRectDim(loc.x*cellDimension+cellpadding, loc.y*cellDimension+cellpadding, cellDimension-cellpadding*2, cellDimension-cellpadding*2, c);
}

void Board::DrawWall(Color c)
{
	int x = x_offset;
	int y = y_offset;
	gfx.DrawRectDim(x, y, x_offset+705, y_offset-25, c);//top
	gfx.DrawRectDim(x, y, x_offset-25, y_offset*18, c);//left
	gfx.DrawRectDim(x, y+535, x_offset+705, y_offset-25, c);//bottom
	gfx.DrawRectDim(x+734, y, x_offset-24, y_offset*18, c);//right
}


Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
	
}

