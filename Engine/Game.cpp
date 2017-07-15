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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(rd()),
	blck(brd),
	blocksel(0, 6),
	gameoversound(L"Sounds\\fart.wav"),
	linecomplete(L"Sounds\\arkbrick.wav"),
	blocksound(L"Sounds\\kb.wav")
{
	blck.loc[0] = { blck.spawnloc };
	blck.nextPiece = blocksel(rng);
	blck.pieceType[blck.currentPiece] = blocksel(rng);
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

	switch (gamestate)
	{
	case splashscreen:
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			gamestate = playing;
		}
		break;
	case playing:
		blck.TakeInput(wnd.kbd.ReadKey(), dt);
		blck.BindPiece();
		if (blck.playlinesound)
		{
			linecomplete.Play();
			blck.playlinesound = false;
		}
		if (blck.playblocksound)
		{
			blocksound.Play();
			blck.playblocksound = false;
		}
		if (blck.canSpawn)
		{
			blck.nextPiece = blocksel(rng);
			blck.canSpawn = false;
		}
		if (blck.isGameOver())
		{
			gameoversound.Play();
			gamestate = gameover;
		}
		break;
	}
	
	
}

void Game::ComposeFrame()
{	
	switch (gamestate)
	{
	case splashscreen:
		SpriteCodex::DrawSplash(160, 250, gfx);
		break;
	case playing:
		brd.DrawWall();
		blck.DrawPiece(brd);
		blck.DrawOver(gfx);
		blck.DrawNextPiece(brd);
		DrawScore(gfx);
		brd.DrawOver();
		break;
	case gameover:
		SpriteCodex::DrawGameOver(300, 250, gfx);
		break;
	}
	
}


void Game::DrawSingles(int x, int y, Graphics& gfx) 
{
	int singles = blck.lines % 10;
	if (tens >= 10)
	{
		tens = 0;
	}
	switch (singles)
	{
	case 0:
		SpriteCodex::DrawZero(x, y, gfx);
		if (blck.linecomplete)
		{
			tens += 1;
		}
		if (tens >= 10)
		{
			tens = 0;
		}
		break;
	case 1:
		SpriteCodex::DrawOne(x, y, gfx);
		break;
	case 2:
		SpriteCodex::DrawTwo(x, y, gfx);
		break;
	case 3:
		SpriteCodex::DrawThree(x, y, gfx);
		break;
	case 4:
		SpriteCodex::DrawFour(x, y, gfx);
		break;
	case 5:
		SpriteCodex::DrawFive(x, y, gfx);
		break;
	case 6:
		SpriteCodex::DrawSix(x, y, gfx);
		break;
	case 7:
		SpriteCodex::DrawSeven(x, y, gfx);
		break;
	case 8:
		SpriteCodex::DrawEight(x, y, gfx);
		break;
	case 9:
		SpriteCodex::DrawNine(x, y, gfx);
		break;
	};
}

void Game::DrawTens(int x, int y, Graphics & gfx) const
{
	switch (tens)
	{
	case 0:
		SpriteCodex::DrawZero(x, y, gfx);
		break;
	case 1:
		SpriteCodex::DrawOne(x, y, gfx);
		break;
	case 2:
		SpriteCodex::DrawTwo(x, y, gfx);
		break;
	case 3:
		SpriteCodex::DrawThree(x, y, gfx);
		break;
	case 4:
		SpriteCodex::DrawFour(x, y, gfx);
		break;
	case 5:
		SpriteCodex::DrawFive(x, y, gfx);
		break;
	case 6:
		SpriteCodex::DrawSix(x, y, gfx);
		break;
	case 7:
		SpriteCodex::DrawSeven(x, y, gfx);
		break;
	case 8:
		SpriteCodex::DrawEight(x, y, gfx);
		break;
	case 9:
		SpriteCodex::DrawNine(x, y, gfx);
		break;
	};
}

void Game::DrawHunds(int x, int y, Graphics & gfx) const
{
	int hunds = blck.lines / 100;
	switch (hunds)
	{
	case 0:
		SpriteCodex::DrawZero(x, y, gfx);
		break;
	case 1:
		SpriteCodex::DrawOne(x, y, gfx);
		break;
	case 2:
		SpriteCodex::DrawTwo(x, y, gfx);
		break;
	case 3:
		SpriteCodex::DrawThree(x, y, gfx);
		break;
	case 4:
		SpriteCodex::DrawFour(x, y, gfx);
		break;
	case 5:
		SpriteCodex::DrawFive(x, y, gfx);
		break;
	case 6:
		SpriteCodex::DrawSix(x, y, gfx);
		break;
	case 7:
		SpriteCodex::DrawSeven(x, y, gfx);
		break;
	case 8:
		SpriteCodex::DrawEight(x, y, gfx);
		break;
	case 9:
		SpriteCodex::DrawNine(x, y, gfx);
		break;
	};
}

void Game::DrawScore(Graphics& gfx)
{
	DrawSingles(670, 300, gfx);
	DrawTens(650, 300, gfx);
	DrawHunds(630, 300, gfx);
}

