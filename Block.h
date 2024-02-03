#pragma once
#include "raylib.h"

class Block
{
public:
	Block();
	Block(float x, float y, Texture texture, int endurance, Color fontColor);
	void update(float deltaTime);
	void damage();
	void draw();
	void unload();

private:
	Texture m_texture{};
	Vector2 m_position{};
	int m_endurance{};
	Color m_fontColor;
	bool m_canDraw{ false };
};