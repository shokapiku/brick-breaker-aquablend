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
	Vector2 getPosition();
	Rectangle getCollider();
	int getEndurance();

private:
	Texture m_texture{};
	Vector2 m_position{};
	int m_endurance{};
	Rectangle m_collider{};
	Color m_fontColor;
	bool m_canDraw{ false };
};