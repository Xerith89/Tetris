#include "Block.h"



void Block::TakeInput(Keyboard & kbd, float dt)
{
	counter += speed * dt;
	downCounter += speed *dt;
	rotcounter += speed*dt;
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
	if (kbd.KeyIsPressed(VK_RETURN) && rotcounter >= rotCD)
	{
		RotatePiece();
		rotcounter = 0.0f;
	}
	//////////////////////////////////////////////////////////////////
	//						test code
	if (kbd.KeyIsPressed(VK_F1))
	{
		nextPiece = cube;
	}
	if (kbd.KeyIsPressed(VK_F2))
	{
		nextPiece = line;
	}
	if (kbd.KeyIsPressed(VK_F3))
	{
		nextPiece = t;
	}
	if (kbd.KeyIsPressed(VK_F4))
	{
		nextPiece = z;
	}
	if (kbd.KeyIsPressed(VK_F5))
	{
		nextPiece = two;
	}
	if (kbd.KeyIsPressed(VK_F6))
	{
		nextPiece = leftl;
	}
	if (kbd.KeyIsPressed(VK_F7))
	{
		nextPiece = rightl;
	}
}
////////////////////////////////////////////////////////////////////////
void Block::SpawnPiece(Board& brd, int randpiece)
{
	canSpawn = false;
	currentPiece++;
	loc[currentPiece].x = spawnloc.x;
	loc[currentPiece].y = spawnloc.y;
	switch (nextPiece)
	{
	case cube:
		pieceType[currentPiece] = cube;
		nextPiece = randpiece;
		break;
	case line:
		pieceType[currentPiece] = line;
		nextPiece = randpiece;
		break;
	case t:
		pieceType[currentPiece] = t;
		nextPiece = randpiece;
		break;
	case z:
		pieceType[currentPiece] = z;
		nextPiece = randpiece;
		break;
	case two:
		pieceType[currentPiece] = two;
		nextPiece = randpiece;
		break;
	case leftl:
		pieceType[currentPiece] = leftl;
		nextPiece = randpiece;
		break;
	case rightl:
		pieceType[currentPiece] = rightl;
		nextPiece = randpiece;
		break;
	}
	canDraw[currentPiece] = true;
}

void Block::UpdatePiece(float dt)
{
	if (downCounter >= downCD)
	{
		loc[currentPiece].y += 1;
		downCounter = 0.0f;

	
	}
}

void Block::DrawPiece(Board & brd)
{
	for (int i = 0; i < 100; i++)
	{
		if (i >= 0)
			{
				switch (pieceType[i])
				{
				case cube:
					brd.DrawCube(loc[i]);
					break;
				case line:
					brd.DrawLineH(loc[i]);
					break;
				case t:
					brd.DrawTD(loc[i]);
					break;
				case z:
					brd.DrawZH(loc[i]);
					break;
				case two:
					brd.Draw2H(loc[i]);
					break;
				case leftl:
					brd.DrawLLL(loc[i]);
					break;
				case rightl:
					brd.DrawRLR(loc[i]);
					break;
				}
			}
		}
	}

void Block::DrawNextPiece(Board & brd)
{
	switch (nextPiece)
	{
	case cube:
		brd.DrawCube(nextBrick);
		break;
	case line:
		brd.DrawLineH(nextBrick);
		break;
	case t:
		brd.DrawTD(nextBrick);
		break;
	case z:
		brd.DrawZH(nextBrick);
		break;
	case two:
		brd.Draw2H(nextBrick);
		break;
	case leftl:
		brd.DrawLLL(nextBrick);
		break;
	case rightl:
		brd.DrawRLR(nextBrick);
		break;
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
		SpawnPiece(brd, nextPiece);
	}
	
		CubeCollision(brd);

}

void Block::RotatePiece()
{
}

void Block::CubeCollision(Board& brd)
{
	for (int i = 0; i < maxPieces; i++)
	{
		if (loc[currentPiece].y + 1 == loc[i].y && loc[currentPiece].x == loc[i].x)
		{
			SpawnPiece(brd, nextPiece);
		}
	}
}

Block::Block(Board& brd)
	:
	brd(brd)
{
}


