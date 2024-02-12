#pragma once
#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "Level.h"
#include <map>
#include <string>

class HandleCollisions
{
public:
	HandleCollisions(int screenWidth, int screenHeight);
	void checkBoundaryCollision(Ball& ball);
	void checkPaddleCollision(Ball& ball, Paddle& paddle);
	void checkBlocksCollision(Ball& ball, Level& level);
private:
	int m_screenWidth{};
	int m_screenHeight{};
	std::map<std::string, int> m_levelBoundaries;
	Vector2 calculateCollision(Rectangle& ballCollider, Rectangle& targetCollider, Vector2 ballSpeed);
};