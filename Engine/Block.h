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
	static constexpr int y = 27;
	static constexpr int x = 24;
	static constexpr int boardLeft = 7;
	static constexpr int boardRight = 23;
	static constexpr int boardBottom = 26;
	float speed = 3.0f;
	Board& brd;
	float inputCD = 2.5f;
	float downCD = 2.5f;
	float rotCD = 2.5f;
	float counter = 0.0f;
	float downCounter = 0.0f;
	float rotCounter = 0.0f;
	int rotated[maxPieces] = { 0 };
	enum pieceType {
		cube,
		line,
		t,
		z,
		two,
		leftl,
		rightl
	};
	int GetMostLeft();
	int GetMostRight();
	int GetPieceHeight();
	void SetMostLeft(int left);
	void SetMostRight(int right);
	void CheckLine();
	void CubeCollision(Board& brd);
	void LineCollision(Board& brd);
	void CubeFillTiles();
	void LineFillTiles();
	void TFillLines();
	void ZFillTiles();
	void TwoFillTiles();
	void LLFillTiles();
	void RLFillTiles();
	void TCollision(Board& brd);
	void ZCollision(Board& brd);
	void TwoCollision(Board& brd);
	void LLCollision(Board& brd);
	void RLCollision(Board& brd);
	bool fullRow = false;
	void SpeedUp();
	void drawCurrentPiece(Board& brd);
public:
	bool isGameOver();
	void DrawOver(Graphics& gfx);
	void TakeInput(Keyboard::Event& kbd, float dt);
	void SpawnPiece(Board& brd, int randpiece);
	void DrawPiece(Board& brd);
	void DrawNextPiece(Board& brd);
	void BindPiece(float dt);
	Location nextBrick = { 33,25 };
	Location spawnloc = { 13,5};
	Location loc[maxPieces];
	bool tileFull[y][x] = { false };
	bool canDraw[maxPieces] = { false };
	int currentPiece = 0;
	int pieceType[maxPieces];
	bool canSpawn = false;
	int nextPiece;
	Block(Board& brd);
	int lines = 0;
	bool linecomplete = false;
};

