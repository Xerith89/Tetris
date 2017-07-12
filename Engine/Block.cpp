#include "Block.h"

void Block::TakeInput(Keyboard::Event & kbd, float dt)
{
	counter += speed * dt;
	downCounter += speed *dt;
	rotCounter += speed *dt;
	if (kbd.IsPress() && kbd.GetCode() == VK_LEFT && counter >= inputCD && tileFull[loc[currentPiece].y][loc[currentPiece].x] == false)
	{
		loc[currentPiece].x -= 1;
		counter = 0.0f;
	}

	if (kbd.IsPress() && kbd.GetCode() == VK_RIGHT && counter >= inputCD && tileFull[loc[currentPiece].y][loc[currentPiece].x] == false)
	{
		loc[currentPiece].x += 1;
		counter = 0.0f;
	}
	if (kbd.IsPress() && kbd.GetCode() == VK_DOWN && counter >= inputCD)
	{
		loc[currentPiece].y += 1;
		counter = 0.0f;
	}
	if (kbd.IsPress() && kbd.GetCode() == VK_UP && rotCounter >= rotCD)
	{
		if (rotated[currentPiece] < 3)
		{
			rotated[currentPiece]++;
		}
		else if (rotated[currentPiece] >= 3)
		{
			rotated[currentPiece] = 0;
		}
	}
}
	
////////////////////////////////////////////////////////////////////////
void Block::SpawnPiece(Board& brd, int randpiece)
{
	canSpawn = true;
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
	case z:
		ZFillTiles();
		break;
	case two:
		TwoFillTiles();
		break;
	case leftl:
		LLFillTiles();
		break;
	case rightl:
		RLFillTiles();
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
					if (rotated[i] == 0 || rotated[i] == 2)
					{
						brd.DrawZH(loc[i]);
					}
					if (rotated[i] == 1 || rotated[i] == 3)
					{
						brd.DrawZV(loc[i]);
					}
					break;
				case two:
					if (rotated[i] == 0 || rotated[i] == 2)
					{
						brd.Draw2H(loc[i]);
					}
					if (rotated[i] == 1 || rotated[i] == 3)
					{
						brd.Draw2V(loc[i]);
					}
					break;
				case leftl:
					if (rotated[i] == 0)
					{
						brd.DrawLLL(loc[i]);
					}
					if (rotated[i] == 1)
					{
						brd.DrawLLRotL(loc[i]);
					}
					if (rotated[i] == 2)
					{
						brd.DrawLLRotUp(loc[i]);
					}
					if (rotated[i] == 3)
					{
						brd.DrawLLRotRight(loc[i]);
					}
					
					break;
				case rightl:
					if (rotated[i] == 0)
					{
						brd.DrawRLR(loc[i]);
					}
					if (rotated[i] == 1)
					{
						brd.DrawRLRotL(loc[i]);
					}
					if (rotated[i] == 2)
					{
						brd.DrawRLRotUp(loc[i]);
					}
					if (rotated[i] == 3)
					{
						brd.DrawRLRotRight(loc[i]);
					}
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
			break;
		case z:
			ZFillTiles();
			break;
		case two:
			TwoFillTiles();
			break;
		case leftl:
			LLFillTiles();
			break;
		case rightl:
			RLFillTiles();
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
	case t:
		TCollision(brd);
		break;
	case z:
		ZCollision(brd);
		break;
	case two:
		TwoCollision(brd);
		break;
	case leftl:
		LLCollision(brd);
		break;
	case rightl:
		RLCollision(brd);
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

	if (rotated[currentPiece] == 0)
	{
		left.x = loc[currentPiece].x - 1;
		left.y = loc[currentPiece].y - 1;
		middle.x = left.x + 1;
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
	else if (rotated[currentPiece] == 1)
	{
		left.x = loc[currentPiece].x;
		left.y = loc[currentPiece].y;
		middle.x = left.x;
		middle.y = left.y-1;
		right.x = middle.x;
		right.y = middle.y-1;
		tee.x = loc[currentPiece].x-1;
		tee.y = loc[currentPiece].y-1;
		if (tileFull[tee.y + 1][tee.x] || tileFull[left.y + 1][left.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
	else if (rotated[currentPiece] == 2)
	{
		left.x = loc[currentPiece].x;
		left.y = loc[currentPiece].y;
		middle.x = left.x + 1;
		middle.y = left.y;
		right.x = middle.x + 1;
		right.y = middle.y;
		tee.x = loc[currentPiece].x+1;
		tee.y = loc[currentPiece].y-1;
		if (tileFull[left.y + 1][left.x] || tileFull[middle.y + 1][middle.x] || tileFull[right.y + 1][right.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
	else if (rotated[currentPiece] == 3)
	{
		left.x = loc[currentPiece].x;
		left.y = loc[currentPiece].y;
		middle.x = left.x;
		middle.y = left.y-1;
		right.x = middle.x;
		right.y = middle.y-1;
		tee.x = loc[currentPiece].x + 1;
		tee.y = loc[currentPiece].y - 1;
		if (tileFull[tee.y + 1][tee.x] || tileFull[left.y + 1][left.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
}

void Block::ZCollision(Board & brd)
{
	Location origin;
	Location bottomright;
	Location topright;
	Location topleft;
	if (rotated[currentPiece] == 0 || rotated[currentPiece] == 2)
	{
		origin.x = loc[currentPiece].x;
		origin.y = loc[currentPiece].y;
		bottomright.x = origin.x + 1;
		bottomright.y = origin.y;
		topright.x = origin.x;
		topright.y = origin.y-1;
		topleft.x = topright.x-1;
		topleft.y = topright.y;

		if (tileFull[origin.y + 1][origin.x] || tileFull[topleft.y + 1][topleft.x] || tileFull[bottomright.y + 1][bottomright.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
	else if (rotated[currentPiece] == 1 || rotated[currentPiece] == 3)
	{
		origin.x = loc[currentPiece].x;
		origin.y = loc[currentPiece].y;
		bottomright.x = origin.x;
		bottomright.y = origin.y-1;
		topright.x = origin.x+1;
		topright.y = origin.y - 1;
		topleft.x = topright.x;
		topleft.y = topright.y-1;

		if (tileFull[origin.y + 1][origin.x] || tileFull[topright.y + 1][topright.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
}

void Block::TwoCollision(Board & brd)
{
	Location origin;
	Location bottomright;
	Location topright;
	Location topleft;
	if (rotated[currentPiece] == 0 || rotated[currentPiece] == 2)
	{
		origin.x = loc[currentPiece].x;
		origin.y = loc[currentPiece].y;
		bottomright.x = origin.x + 1;
		bottomright.y = origin.y;
		topright.x = bottomright.x;
		topright.y = bottomright.y - 1;
		topleft.x = topright.x + 1;
		topleft.y = topright.y;

		if (tileFull[origin.y + 1][origin.x] || tileFull[topleft.y + 1][topleft.x] || tileFull[bottomright.y + 1][bottomright.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
	else if (rotated[currentPiece] == 1 || rotated[currentPiece] == 3)
	{
		origin.x = loc[currentPiece].x;
		origin.y = loc[currentPiece].y;
		bottomright.x = origin.x;
		bottomright.y = origin.y - 1;
		topright.x = origin.x -1;
		topright.y = origin.y - 1;
		topleft.x = topright.x -1;
		topleft.y = topright.y ;

		if (tileFull[origin.y + 1][origin.x] || tileFull[topright.y + 1][topright.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
}

void Block::LLCollision(Board & brd)
{
	Location left;
	Location middle;
	Location origin;
	Location right;

	if (rotated[currentPiece] == 0)
	{
		origin.x = loc[currentPiece].x;
		origin.y = loc[currentPiece].y;
		right.x = origin.x + 1;
		right.y = origin.y;
		middle.x = right.x;
		middle.y = right.y-1;
		left.x = middle.x;
		left.y = middle.y - 1;

		if (tileFull[origin.y + 1][origin.x] || tileFull[right.y + 1][right.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
	else if (rotated[currentPiece] == 1)
	{
		origin.x = loc[currentPiece].x;
		origin.y = loc[currentPiece].y;
		right.x = origin.x + 1;
		right.y = origin.y;
		middle.x = right.x+1;
		middle.y = right.y;
		left.x = origin.x;
		left.y = origin.y - 1;

		if (tileFull[origin.y + 1][origin.x] || tileFull[right.y + 1][right.x] || tileFull[middle.y + 1][middle.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
	else if (rotated[currentPiece] == 2)
	{
		origin.x = loc[currentPiece].x;
		origin.y = loc[currentPiece].y;
		right.x = origin.x;
		right.y = origin.y-1;
		middle.x = right.x;
		middle.y = right.y-1;
		left.x = middle.x+1;
		left.y = middle.y;
		if (tileFull[left.y + 1][left.x] || tileFull[origin.y + 1][origin.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
	else if (rotated[currentPiece] == 3)
	{
		origin.x = loc[currentPiece].x;
		origin.y = loc[currentPiece].y;
		right.x = origin.x;
		right.y = origin.y - 1;
		middle.x = right.x-1;
		middle.y = right.y;
		left.x = middle.x - 1;
		left.y = middle.y;

		if (tileFull[origin.y + 1][origin.x] || tileFull[left.y + 1][left.x] || tileFull[middle.y + 1][middle.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
}

void Block::RLCollision(Board & brd)
{
	Location left;
	Location middle;
	Location origin;
	Location right;

	if (rotated[currentPiece] == 0)
	{
		origin.x = loc[currentPiece].x;
		origin.y = loc[currentPiece].y;
		right.x = origin.x + 1;
		right.y = origin.y;
		middle.x = origin.x;
		middle.y = origin.y - 1;
		left.x = middle.x;
		left.y = middle.y - 1;

		if (tileFull[origin.y + 1][origin.x] || tileFull[right.y + 1][right.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
	else if (rotated[currentPiece] == 1)
	{
		origin.x = loc[currentPiece].x;
		origin.y = loc[currentPiece].y;
		left.x = origin.x;
		left.y = origin.y - 1;
		middle.x = left.x + 1;
		middle.y = left.y;
		right.x = middle.x + 1;
		right.y = middle.y;
	
		if (tileFull[origin.y + 1][origin.x] || tileFull[right.y + 1][right.x] || tileFull[middle.y + 1][middle.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
	else if (rotated[currentPiece] == 2)
	{
		origin.x = loc[currentPiece].x;
		origin.y = loc[currentPiece].y;
		right.x = origin.x;
		right.y = origin.y-1;
		middle.x = right.x;
		middle.y = right.y-1;
		left.x = middle.x-1;
		left.y = middle.y;
		if (tileFull[left.y + 1][left.x] || tileFull[origin.y + 1][origin.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
	else if (rotated[currentPiece] == 3)
	{
		origin.x = loc[currentPiece].x;
		origin.y = loc[currentPiece].y;
		right.x = origin.x+1;
		right.y = origin.y;
		middle.x = right.x+1;
		middle.y = right.y;
		left.x = middle.x;
		left.y = middle.y-1;

		if (tileFull[origin.y + 1][origin.x] || tileFull[right.y + 1][right.x] || tileFull[middle.y + 1][middle.x])
		{
			SpawnPiece(brd, nextPiece);
		}
	}
}

void Block::SpeedUp()
{
	speed = 3.0f+ (lines / 20);
}

bool Block::isGameOver()
{
	if (loc[currentPiece].y - 3 <=1)
	{
		return true;
	}
	else
	{
		return false;
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
	if (rotated[currentPiece] == 0)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x - 1] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x + 1] = true;
	}
	if (rotated[currentPiece] == 1)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 2][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x - 1] = true;
	}
	if (rotated[currentPiece] == 2)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y][loc[currentPiece].x + 1] = true;
		tileFull[loc[currentPiece].y][loc[currentPiece].x + 2] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x + 1] = true;
	}
	if (rotated[currentPiece] == 3)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 2][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x + 1] = true;
	}
}

void Block::ZFillTiles()
{
		if (rotated[currentPiece] == 0 || rotated[currentPiece] == 2)
		{
			tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
			tileFull[loc[currentPiece].y][loc[currentPiece].x+1] = true;
			tileFull[loc[currentPiece].y -1][loc[currentPiece].x] = true;
			tileFull[loc[currentPiece].y - 1][loc[currentPiece].x -1] = true;
		}
		if (rotated[currentPiece] == 1 || rotated[currentPiece] == 3)
		{
			tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
			tileFull[loc[currentPiece].y-1][loc[currentPiece].x] = true;
			tileFull[loc[currentPiece].y - 1][loc[currentPiece].x+1] = true;
			tileFull[loc[currentPiece].y - 2][loc[currentPiece].x + 1] = true;
		}
}

void Block::TwoFillTiles()
{
	if (rotated[currentPiece] == 0 || rotated[currentPiece] == 2)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y][loc[currentPiece].x+1] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x + 1] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x + 2] = true;
	}
	if (rotated[currentPiece] == 1 || rotated[currentPiece] == 3)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x - 1] = true;
		tileFull[loc[currentPiece].y - 2][loc[currentPiece].x - 1] = true;
	}
}

void Block::LLFillTiles()
{
	if (rotated[currentPiece] == 0)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y][loc[currentPiece].x+1] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x +1] = true;
		tileFull[loc[currentPiece].y - 2][loc[currentPiece].x + 1] = true;
	}
	if (rotated[currentPiece] == 1)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y][loc[currentPiece].x + 1] = true;
		tileFull[loc[currentPiece].y][loc[currentPiece].x +2] = true;
	}
	if (rotated[currentPiece] == 2)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 2][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 2][loc[currentPiece].x+ 1] = true;
	}
	if (rotated[currentPiece] == 3)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x - 1] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x - 2] = true;
	}
}

void Block::RLFillTiles()
{
	if (rotated[currentPiece] == 0)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y][loc[currentPiece].x+1] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 2][loc[currentPiece].x] = true;
	}
	if (rotated[currentPiece] == 1)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x + 1] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x + 2] = true;
	}
	if (rotated[currentPiece] == 2)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 1][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 2][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y - 2][loc[currentPiece].x - 1] = true;
	}
	if (rotated[currentPiece] == 3)
	{
		tileFull[loc[currentPiece].y][loc[currentPiece].x] = true;
		tileFull[loc[currentPiece].y ][loc[currentPiece].x+1] = true;
		tileFull[loc[currentPiece].y ][loc[currentPiece].x +2] = true;
		tileFull[loc[currentPiece].y -1][loc[currentPiece].x +2] = true;
	}
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
		if (rotated[currentPiece] == 0)
		{
			return 1;
			break;
		}
		if (rotated[currentPiece] == 1)
		{
			return 1;
			break;
		}
		if (rotated[currentPiece] == 2)
		{
			return 0;
			break;
		}
		if (rotated[currentPiece] == 3)
		{
			return 0;
			break;
		}
		break;
	case z:
		if (rotated[currentPiece] == 1 || rotated[currentPiece] == 3)
		{
			return 0;
			break;
		}
		else if (rotated[currentPiece] == 0 || rotated[currentPiece] == 2)
		{
			return 1;
			break;
		}
		break;
	case two:
		if (rotated[currentPiece] == 1 || rotated[currentPiece] == 3)
		{
			return 1;
			break;
		}
		else if (rotated[currentPiece] == 0 || rotated[currentPiece] == 2)
		{
			return 0;
			break;
		}
		break;
	case leftl:
		if (rotated[currentPiece] == 0)
		{
			return 1;
			break;
		}
		if (rotated[currentPiece] == 1)
		{
			return 0;
			break;
		}
		if (rotated[currentPiece] == 2)
		{
			return 0;
			break;
		}
		if (rotated[currentPiece] == 3)
		{
			return 2;
			break;
		}
		break;
	case rightl:
		if (rotated[currentPiece] == 0)
		{
			return 0;
			break;
		}
		if (rotated[currentPiece] == 1)
		{
			return 0;
			break;
		}
		if (rotated[currentPiece] == 2)
		{
			return 1;
			break;
		}
		if (rotated[currentPiece] == 3)
		{
			return 0;
			break;
		}
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
		if (rotated[currentPiece] == 0)
		{
			return 1;
			break;
		}
		if (rotated[currentPiece] == 1)
		{
			return 0;
			break;
		}
		if (rotated[currentPiece] == 2)
		{
			return 2;
			break;
		}
		if (rotated[currentPiece] == 3)
		{
			return 1;
			break;
		}
		break;
	case z:
		if (rotated[currentPiece] == 1 || rotated[currentPiece] == 3)
		{
			return 1;
			break;
		}
		else if (rotated[currentPiece] == 0 || rotated[currentPiece] == 2)
		{
			return 1;
			break;
		}
		break;
	case two:
		if (rotated[currentPiece] == 1 || rotated[currentPiece] == 3)
		{
			return 1;
			break;
		}
		else if (rotated[currentPiece] == 0 || rotated[currentPiece] == 2)
		{
			return 2;
			break;
		}
		break;
	case leftl:
		if (rotated[currentPiece] == 0)
		{
			return 0;
			break;
		}
		if (rotated[currentPiece] == 1)
		{
			return 2;
			break;
		}
		if (rotated[currentPiece] == 2)
		{
			return 1;
			break;
		}
		if (rotated[currentPiece] == 3)
		{
			return 0;
			break;
		}
		break;
	case rightl:
		if (rotated[currentPiece] == 0)
		{
			return 1;
			break;
		}
		if (rotated[currentPiece] == 1)
		{
			return 2;
			break;
		}
		if (rotated[currentPiece] == 2)
		{
			return 0;
			break;
		}
		if (rotated[currentPiece] == 3)
		{
			return 2;
			break;
		}
		break;
	}
}

int Block::GetPieceHeight()
{
	return 0;
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
	if (tileFull[loc[currentPiece].y][7] && tileFull[loc[currentPiece].y][8] && tileFull[loc[currentPiece].y][9] && tileFull[loc[currentPiece].y][10]
		&& tileFull[loc[currentPiece].y][11] && tileFull[loc[currentPiece].y][12] && tileFull[loc[currentPiece].y][13] && tileFull[loc[currentPiece].y][14]
		&& tileFull[loc[currentPiece].y][15] && tileFull[loc[currentPiece].y][16] && tileFull[loc[currentPiece].y][17] && tileFull[loc[currentPiece].y][18] &&
		tileFull[loc[currentPiece].y][19] && tileFull[loc[currentPiece].y][20] && tileFull[loc[currentPiece].y][21] && tileFull[loc[currentPiece].y][22] &&
		tileFull[loc[currentPiece].y][23] && tileFull[loc[currentPiece].y][24] && tileFull[loc[currentPiece].y][25] && tileFull[loc[currentPiece].y][26] && tileFull[loc[currentPiece].y][27])&&
	{
		//loop through the board array that is above loc.y -move everything down by 1 on y for the true/false array;
		//move everything being drawn down 1
		//loop through top row and insert a row in the top of the board setting everything to false
		//make it so that drawing can only be down if y is lower than the bottom of board
		lines++;
		SpeedUp();
	}
}

Block::Block(Board& brd)
	:
	brd(brd)
{
}


