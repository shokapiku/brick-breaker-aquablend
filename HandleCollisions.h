#pragma once
#include "raylib.h"
#include "Ball.h"
#include <map>
#include <string>

class HandleCollisions
{
public:
	HandleCollisions(int screenWidth, int screenHeight);
	void checkBoundaryCollision(Ball& ball);
private:
	int m_screenWidth{};
	int m_screenHeight{};
	std::map<std::string, int> m_levelBoundaries;
};