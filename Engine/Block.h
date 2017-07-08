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
	static constexpr int y = 28;
	static constexpr int x = 20;
	float speed = 4.0f;
	Board& brd;
	float inputCD = 5.0f;
	float downCD = 5.0f;
	float counter = 0.0f;
	float downCounter = 0.0f;
	float rotCD = 3.0f;
	float rotcounter = 0.0f;
	enum pieceType {
		cube,
		line,
		t,
		z,
		two,
		leftl,
		rightl
	};
	
public:
	void TakeInput(Keyboard& kbd, float dt);
	void SpawnPiece(Board& brd, int randpiece);
	void UpdatePiece(float dt);
	void DrawPiece(Board& brd);
	void DrawNextPiece(Board& brd);
	void BindPiece();
	void RotatePiece();
	void CubeCollision(Board& brd);
	void CubeFillTiles();
	Location nextBrick = { 33,23 };
	Location spawnloc = { 17,18};
	Location loc[maxPieces];
	bool tileFull[y][x] = { false };
	bool canDraw[maxPieces] = { false };
	int currentPiece = 0;
	int pieceType[maxPieces];
	bool canSpawn = false;
	int nextPiece;
	Block(Board& brd);
};

