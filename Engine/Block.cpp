#include "Block.h"



void Block::TakeInput(Keyboard::Event & kbd, float dt)
{
	counter += speed * dt;
	downCounter += speed *dt;
	rotCounter += speed *dt;
	if ( kbd.IsPress() && kbd.GetCode() == VK_LEFT && counter >= inputCD && tileFull[loc[currentPiece].y][GetMostLeft()-1] == false)
	{
		loc[currentPiece].x -= 1;
		counter = 0.0f;	
	}
		
	if (kbd.IsPress() && kbd.GetCode() == VK_RIGHT && counter >= inputCD && tileFull[loc[currentPiece].y][GetMostRight() + 1] == false)
	{
		loc[currentPiece].x += 1;
		counter = 0.0f;
	}
	if (kbd.IsPress() && kbd.GetCode() == VK_DOWN && counter >= inputCD )
	{
		loc[currentPiece].y += 1;
		counter = 0.0f;
	}
	if (kbd.IsPress() && kbd.GetCode() == VK_UP && rotCounter >= rotCD)
	{
		if (rotated[currentPiece] <3)
		{
			rotated[currentPiece]++;
		}
		else if (rotated[currentPiece] >= 3)
		{
			rotated[currentPiece] = 0;
		}
	}
	
	//////////////////////////////////////////////////////////////////
	//						test code
	if (kbd.IsPress() && kbd.GetCode() == VK_F1)
	{
		nextPiece = cube;
	}
	if (kbd.IsPress() && kbd.GetCode() == VK_F2)
	{
		nextPiece = line;
	}
	if (kbd.IsPress() && kbd.GetCode() == VK_F3)
	{
		nextPiece = t;
	}
	if (kbd.IsPress() && kbd.GetCode() == VK_F4)
	{
		nextPiece = z;
	}
	if (kbd.IsPress() && kbd.GetCode() == VK_F5)
	{
		nextPiece = two;
	}
	if (kbd.IsPress() && kbd.GetCode() == VK_F6)
	{
		nextPiece = leftl;
	}
	if (kbd.IsPress() && kbd.GetCode() == VK_F7)
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
	case t:
		TFillLines();
		break;
	}
	CheckLine();
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
					if (rotated[i] == 0 || rotated[i] == 2)
					{
						brd.DrawLineH(loc[i]);
					}
					if (rotated[i] == 1 || rotated[i] == 3)
					{
						brd.DrawLineV(loc[i]);
					}
					break;
				case t:
					if (rotated[i] == 0)
					{
						brd.DrawTD(loc[i]);
					}
					if (rotated[i] == 1)
					{
						brd.DrawTRotLeft(loc[i]);
					}
					if (rotated[i] == 2)
					{
						brd.DrawTRotUp(loc[i]);
					}
					if (rotated[i] == 3)
					{
						brd.DrawTRotRight(loc[i]);
					}
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
	if (loc[currentPiece].x - GetMostLeft() <= boardLeft)
	{
		loc[currentPiece].x = boardLeft + GetMostLeft();
	}
	if (loc[currentPiece].x + GetMostRight() >= boardRight)
	{
		loc[currentPiece].x = boardRight-GetMostRight();
	}
	if (loc[currentPiece].y >= boardBottom)
	{
		switch (pieceType[currentPiece])
		{
		case cube:
			CubeFillTiles();
			break;
		case line:
			LineFillTiles();
			break;
		case t:
			TFillLines();
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
	case t:
		TCollision(brd);
		break;
	}
		

}

/////////////////////////////////////////////////////////////
//				Collision Code
void Block::CubeCollision(Board& brd)
{
	
	Location bottom;
	bottom.x = loc[currentPiece].x;
	bottom.y = loc[currentPiece].y;
	
	if ( tileFull[bottom.y+1][bottom.x])
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
	if (rotated[currentPiece] == 0 || rotated[currentPiece] == 2)
	{
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
	else if (rotated[currentPiece] == 1 || rotated[currentPiece] == 3 )
	{
		middleleft.x = loc[currentPiece].x;
		middleleft.y = loc[currentPiece].y-1;
		middleright.x = middleleft.x;
		middleright.y = middleleft.y-1;
		right.x = middleright.x;
		right.y = middleright.y-1;
		left.x = loc[currentPiece].x;
		left.y = loc[currentPiece].y;

		if (tileFull[left.y + 1][left.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
}

void Block::TCollision(Board & brd)
{
	Location left;
	Location middle;
	Location tee;
	Location right;
	left.x = loc[currentPiece].x -1;
	left.y = loc[currentPiece].y-1;
	middle.x = left.x+1;
	middle.y = left.y;
	right.x = middle.x + 1;
	right.y = middle.y;
	tee.x = loc[currentPiece].x;
	tee.y = loc[currentPiece].y;

	if (tileFull[tee.y + 1][tee.x] || tileFull[left.y + 1][left.x] || tileFull[right.y + 1][right.x])
	{
		SpawnPiece(brd, nextPiece);
	}
}

/////////////////////////////////////////////////
//			Set Tile Array
void Block::CubeFillTiles()
{
	tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
}

void Block::LineFillTiles()
{
	if (rotated[currentPiece] == 0 || rotated[currentPiece] == 2)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y][loc[currentPiece].x + 1] = true;
		tileFull[loc[currentPiece].y][loc[currentPiece].x + 2] = true;
		tileFull[loc[currentPiece].y][loc[currentPiece].x + 3] = true;
	}
	else if (rotated[currentPiece] == 1 || rotated[currentPiece] == 3)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y-1][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y-2][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y-3][loc[currentPiece].x] = true;
	}
}

void Block::TFillLines()
{
	tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
	tileFull[loc[currentPiece].y - 1][loc[currentPiece].x-1] = true;
	tileFull[loc[currentPiece].y - 1][loc[currentPiece].x] = true;
	tileFull[loc[currentPiece].y - 1][loc[currentPiece].x+1] = true;
}



int Block::GetMostLeft()
{
	switch (pieceType[currentPiece])
	{
	case cube:
		return 0;
		break;
	case line:
		if (rotated[currentPiece] == 1 || rotated[currentPiece] == 3)
		{
			return 0;
			break;
		}
		else if (rotated[currentPiece] == 0 || rotated[currentPiece] == 3)
		{
			return 0;
			break;
		}
	case t:
		return 1;
		break;
	}
}

int Block::GetMostRight()
{
	switch (pieceType[currentPiece])
	{
	case cube:
		return 0;
		break;
	case line:
		if (rotated[currentPiece] == 1 || rotated[currentPiece] == 3)
		{
			return 0;
			break;
		}
		else if (rotated[currentPiece] == 0 || rotated[currentPiece] == 2)
		{
			return 3;
			break;
		}
	case t:
		return 1;
		break;
	}
}

void Block::SetMostLeft(int left)
{
	loc[currentPiece].x = left;
}

void Block::SetMostRight(int right)
{
	loc[currentPiece].x = right;
}

void Block::CheckLine()
{
	
}

Block::Block(Board& brd)
	:
	brd(brd)
{
}


