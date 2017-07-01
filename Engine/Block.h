#pragma once
#include "Location.h"
#include "Board.h"
#include "SpriteCodex.h"
#include "Graphics.h"
#include "Keyboard.h"
class Block
{
private:
	static constexpr int maxPieces = 100;
	float speed = 4.0f;
	bool canSpawn = true;
	float inputCD = 5.0f;
	float downCD = 5.0f;
	float counter = 0.0f;
	float downCounter = 0.0f;
public:
	void TakeInput(Keyboard& kbd, float dt);
	void SpawnPiece(Board& brd);
	void UpdatePiece(float dt);
	void BindPiece();
	Location nextBrick = { 33,23 };
	Location spawnloc = { 17,0};
	Location loc[maxPieces];
	bool canDraw[maxPieces] = { false };
	int currentPiece = 0;
	Block();
};

