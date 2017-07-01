#pragma once

#include "Graphics.h"
#include "Location.h"

class SpriteCodex
{
public:
	static void DrawGameOver( int x,int y,Graphics& gfx );
	static void DrawBlockYellow(int x, int y, Graphics& gfx);
	static void DrawBlockWhite(int x, int y, Graphics& gfx);
	static void DrawBlockRed(int x, int y, Graphics& gfx);
	static void DrawBlockOrange(int x, int y, Graphics& gfx);
	static void DrawBlockGreen(int x, int y, Graphics& gfx);
	static void DrawBlockBrown(int x, int y, Graphics& gfx);
	static void DrawBlockBlue(int x, int y, Graphics& gfx);
	static void DrawBlockBlack(int x, int y, Graphics& gfx);
	static void DrawBlockAqua(int x, int y, Graphics& gfx);
	static void DrawBlockWall(int x, int y, Graphics& gfx);
};