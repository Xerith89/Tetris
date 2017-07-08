#include "Block.h"



void Block::TakeInput(Keyboard & kbd, float dt)
{
	counter += speed * dt;
	downCounter += speed *dt;
	rotcounter += speed*dt;
	if (kbd.KeyIsPressed(VK_LEFT) && counter >= inputCD && tileFull[loc[currentPiece].y][loc[currentPiece].x - 1] == false ||
		kbd.KeyIsPressed(VK_LEFT) && counter >= inputCD && tileFull[loc[currentPiece].y+1][loc[currentPiece].x - 1] == false)
	{
		loc[currentPiece].x -= 1;
		counter = 0.0f;	
	}
		
	if (kbd.KeyIsPressed(VK_RIGHT) && counter >= inputCD && tileFull[loc[currentPiece].y][loc[currentPiece].x + 1] == false || 
		kbd.KeyIsPressed(VK_RIGHT) && counter >= inputCD && tileFull[loc[currentPiece].y+1][loc[currentPiece].x + 1] == false)
	{
		loc[currentPiece].x += 1;
		counter = 0.0f;
	}
	if (kbd.KeyIsPressed(VK_DOWN) && counter >= inputCD )
	{
		loc[currentPiece].y += 1;
		counter = 0.0f;
	}
	if (kbd.KeyIsPressed(VK_RETURN) && rotcounter >= rotCD)
	{
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
	switch (pieceType[currentPiece])
	{
	case cube:
		CubeFillTiles();
		break;
	case line:
		LineFillTiles();
		break;
	}
	
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

void Block::DrawPiece(Board & brd)
{
	for (int i = 0; i < maxPieces; i++)
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

void Block::BindPiece(float dt)
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
		switch (pieceType[currentPiece])
		{
		case cube:
			CubeFillTiles();
			break;
		case line:
			LineFillTiles();
			break;
		}
		SpawnPiece(brd, nextPiece);
	}

	if (downCounter >= downCD)
	{
		loc[currentPiece].y += 1;
		downCounter = 0.0f;
	}
	switch (pieceType[currentPiece])
	{
	case cube:
		CubeCollision(brd);
		break;
	case line:
		LineCollision(brd);
		break;
	}
		

}

void Block::CubeCollision(Board& brd)
{
	Location bottomright;
	Location bottomleft;
	bottomleft.x = loc[currentPiece].x;
	bottomleft.y = loc[currentPiece].y;
	bottomright.x = loc[currentPiece].x + 1;
	bottomright.y = loc[currentPiece].y;
	
	if (tileFull[bottomright.y+1][bottomright.x] || tileFull[bottomleft.y+1][bottomleft.x])
	{
		SpawnPiece(brd, nextPiece);
	}
}

void Block::LineCollision(Board & brd)
{
	Location left;
	Location middleleft;
	Location middleright;
	Location right;
	middleleft.x = loc[currentPiece].x + 1;
	middleleft.y = loc[currentPiece].y;
	middleright.x = middleleft.x + 1;
	middleright.y = middleleft.y;
	right.x = middleright.x + 1;
	right.y = middleright.y;
	left.x = loc[currentPiece].x;
	left.y = loc[currentPiece].y;

	if (tileFull[left.y + 1][left.x] || tileFull[middleleft.y + 1][middleleft.x] || tileFull[middleright.y + 1][middleright.x] || tileFull[right.y + 1][right.x])
	{
		SpawnPiece(brd, nextPiece);
	}
}

void Block::CubeFillTiles()
{
	tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
	tileFull[loc[currentPiece].y][loc[currentPiece].x + 1] = true;
	tileFull[loc[currentPiece].y-1][loc[currentPiece].x] = true;
	tileFull[loc[currentPiece].y-1][loc[currentPiece].x + 1] = true;
}

void Block::LineFillTiles()
{
	tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
	tileFull[loc[currentPiece].y][loc[currentPiece].x + 1] = true;
	tileFull[loc[currentPiece].y][loc[currentPiece].x + 2] = true;
	tileFull[loc[currentPiece].y][loc[currentPiece].x + 3] = true;
}

Block::Block(Board& brd)
	:
	brd(brd)
{
}


