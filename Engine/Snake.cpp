#include "Snake.h"

Snake::Snake()
{
}

void Snake::DrawHead(Board& brd, Location& loc)const
{
	brd.DrawCell(loc, Snake::snake_head);
}

void Snake::DrawBody(Board& brd, Location& bloc)const
{
	brd.DrawCellTwo(bloc, Snake::snake_body);
}

void Snake::CheckKeyboard(Keyboard & kbd)
{
	if (kbd.KeyIsPressed(VK_UP))
	{
		dirUp = true;
		dirDown = false;
		dirLeft = false;
		dirRight = false;
	}
	else if (kbd.KeyIsPressed(VK_DOWN))
	{
		dirDown = true;
		dirUp = false;
		dirLeft = false;
		dirRight = false;
	}
	else if (kbd.KeyIsPressed(VK_LEFT))
	{
		dirLeft = true;
		dirDown = false;
		dirUp = false;
		dirRight = false;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{

		dirRight = true;
		dirDown = false;
		dirLeft = false;
		dirUp = false;
	}
}

void Snake::UpdateSnake(float dt)
{	
	counter += dt;
	if (dirUp && counter >= resetTime)
	{
		bloct[0].x = loc.x;
		bloct[0].y = loc.y;
		for (int i = nSegments; i > 0; --i)
		{
			bloct[i].x = bloct[i - 1].x;
			bloct[i].y = bloct[i - 1].y;
		}
		loc.y -= 1;
		counter = 0.0f;
	}
	else if (dirDown && counter >= resetTime)
	{
		bloct[0].x = loc.x;
		bloct[0].y = loc.y;
		for (int i = nSegments; i > 0; --i)
		{
			bloct[i].x = bloct[i - 1].x;
			bloct[i].y = bloct[i - 1].y;
		}
		loc.y += 1;
		counter = 0.0f;
	}
	else if (dirLeft && counter >= resetTime)
	{
		bloct[0].x = loc.x;
		bloct[0].y = loc.y;
		for (int i = nSegments; i > 0; --i)
		{
			bloct[i].x = bloct[i - 1].x;
			bloct[i].y = bloct[i - 1].y;
		}

		loc.x -= 1;
		counter = 0.0f;
	}
	else if (dirRight && counter >= resetTime)
	{
		bloct[0].x = loc.x;
		bloct[0].y = loc.y;
		for (int i = nSegments; i > 0; --i)
		{
			bloct[i].x = bloct[i - 1].x;
			bloct[i].y = bloct[i - 1].y;
		}

		loc.x += 1;
		counter = 0.0f;
	}
}

bool Snake::HitWall()
{
	if (loc.x <= 1 || loc.x >= 38 || loc.y <= 1 || loc.y >= 28)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Snake::GrowSnake()
{
	if (nSegments < maxSegments)
	{
		nSegments++;
	}
}

bool Snake::insideTile()
{
	for (int i = 0; i <= nSegments; i++)
	{
		if (loc.x == bloct[i].x && loc.y == bloct[i].y)
		{
			insidetile = true;
		}
	}
	return insidetile;
}

void Snake::SpeedUp()
{
	if (resetTime > MaxSpeed)
	{
		resetTime = resetTime - speedUpTimer;
	}
	else if (resetTime <= MaxSpeed)
	{
		resetTime = MaxSpeed;
	}
}

