#pragma once
#include "Location.h"
#include "Board.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Fruit.h"
class Snake
{
private:
	static constexpr Color snake_head = Colors::Yellow;
	static constexpr Color snake_body = Colors::Green;
	static constexpr int maxSegments = 400;
	bool dirRight = false;
	bool dirLeft = false;
	bool dirUp = false;
	bool dirDown = false;
	float resetTime = 0.40f;
	float counter = 0.0f;
	float speedUpTimer = 0.07f;
	float MaxSpeed = 0.30f;
	bool insidetile = false;
public:
	Snake();
	void DrawHead(Board& brd, Location& loc)const;
	void DrawBody(Board& brd, Location& bloc)const;
	void CheckKeyboard(Keyboard& kbd);
	void UpdateSnake(float dt);
	bool HitWall();
	int nSegments = 1;
	void GrowSnake();
	bool insideTile();
	Location bloct[maxSegments];
	Location loc = { 5,10 };
	void SpeedUp();
};

