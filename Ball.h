#pragma once
#include <raylib.h>
#include <map>
#include <string>
#include "Paddle.h"

class Ball
{
public:
	Ball(int screenWidth, int screenHeight);
	void update(float deltaTime);
	void draw();
	void unload();
	void setLimits(float minX, float maxX, float minY, float maxY);
	void followPaddle(Paddle paddle);
	Vector2 getPosition();
	void setPosition(Vector2 position);
	Vector2 getSpeed();
	void setSpeed(Vector2 speed);
	Rectangle getCollider();

private:
	int m_screenWidth{};
	int m_screenHeight{};
	Vector2 m_position{};
	Vector2 m_speed{};
	Texture m_ballTexture{};
	Vector2 m_ballSize{};
	Rectangle m_ballCollider{};
	std::map<std::string, float> m_levelLimits{};
	bool m_canMove{ false };
};