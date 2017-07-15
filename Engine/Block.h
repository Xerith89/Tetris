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
	static constexpr float inputCD = 2.5f;
	static constexpr float downCD = 2.5f;
	static constexpr float rotCD = 2.5f;
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
	bool canDraw[maxPieces] = { false };
	bool tileFull[y][x] = { false };
public:
	bool isGameOver();
	void DrawOver(Graphics& gfx);
	void TakeInput(Keyboard::Event& kbd, float dt);
	void SpawnPiece(Board& brd, int randpiece);
	void DrawPiece(const Board& brd);
	void DrawNextPiece(const Board& brd);
	void BindPiece();
	Location nextBrick = { 33,25 };
	Location spawnloc = { 13,3};
	Location loc[maxPieces];
	int currentPiece = 0;
	int pieceType[maxPieces];
	bool canSpawn = false;
	int nextPiece;
	Block(Board& brd);
	int lines = 0;
	bool linecomplete = false;
	bool playlinesound = false;
	bool playblocksound = false;
};

