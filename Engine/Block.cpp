#include "Block.h"



void Block::TakeInput(Keyboard & kbd, float dt)
{
	counter += speed * dt;
	downCounter += speed *dt;
	if (kbd.KeyIsPressed(VK_LEFT) && counter >= inputCD)
	{
		loc[currentPiece].x -= 1;
		counter = 0.0f;
	}
	if (kbd.KeyIsPressed(VK_RIGHT) && counter >= inputCD)
	{
		loc[currentPiece].x += 1;
		counter = 0.0f;
	}
	if (kbd.KeyIsPressed(VK_DOWN) && counter >= inputCD)
	{
		loc[currentPiece].y += 1;
		counter = 0.0f;
	}
	if (kbd.KeyIsPressed(VK_RETURN))
	{
		currentPiece++;
		loc[currentPiece].x = spawnloc.x;
		loc[currentPiece].y = spawnloc.y;
		canDraw[currentPiece] = true;
	}
}

void Block::SpawnPiece(Board& brd)
{
}

void Block::UpdatePiece(float dt)
{
	if (downCounter >= downCD)
	{
		loc[currentPiece].y += 1;
		downCounter = 0.0f;
		if (loc[currentPiece].y >= 27)
		{
			currentPiece++;
		}
	}
}

void Block::BindPiece()
{
	if (loc[currentPiece].x <= 7)
	{
		loc[currentPiece].x = 7;
	}
	if (loc[currentPiece].x >= 26)
	{
		loc[currentPiece].x = 26;
	}
	if (loc[currentPiece].y >= 27)
	{
		loc[currentPiece].y = 27;
	}
}

Block::Block()
{
}


