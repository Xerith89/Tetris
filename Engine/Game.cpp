/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	xDist(2, 37),
	yDist(2, 27),
	brd(gfx)
{
	snake.bloct[0] = { snake.loc.x - 1, snake.loc.y };
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	if (wnd.kbd.KeyIsPressed(VK_RETURN) && !isGameStarted )
	{
		isGameStarted = true;
		isGameOver = false;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RETURN) && isGameOver)
	{
		isGameOver = false;
		isGameStarted = true;
	}

	if (!isGameOver && isGameStarted)
	{
		snake.CheckKeyboard(wnd.kbd);
		snake.UpdateSnake(dt);
		SpawnFruit();
		if (snake.insideTile() || snake.HitWall())
		{
			isGameStarted = false;
			isGameOver = true;
		}
	}
}

void Game::ComposeFrame()
{
	if (isGameOver)
	{
		sprite.DrawGameOver(250, 300, gfx);
	}
	
	if (!isGameStarted && !isGameOver)
	{
		sprite.DrawTitle(250, 250, gfx);
	}
	else if (isGameStarted && !isGameOver)
	{
		snake.DrawHead(brd, snake.loc);
		fruit.DrawFruit(brd, floc);
		for (int i = 1; i < snake.nSegments; i++)
		{
			snake.DrawBody(brd, snake.bloct[i]);
		}
		brd.DrawWall(Colors::Blue);
	}
}

void Game::SpawnFruit()
{
	if (snake.loc.x == floc.x && snake.loc.y == floc.y)
	{
		snake.GrowSnake();
		snake.bloct[snake.nSegments].x = snake.bloct[snake.nSegments - 1].x;
		snake.bloct[snake.nSegments].y = snake.bloct[snake.nSegments - 1].y;
		floc = { xDist(rng),yDist(rng) };
		snake.SpeedUp();
	}
}



