#pragma once
#include "raylib.h"

class HandleCollisions
{
public:
	HandleCollisions(int screenWidth, int screenHeight);
private:
	int m_screenWidth{};
	int m_screenHeight{};
};