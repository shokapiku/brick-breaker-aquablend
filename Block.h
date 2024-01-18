#pragma once
#include "raylib.h"

class Block
{
public:
	Block();
	Block(float x, float y, Texture texture);
	void update(float deltaTime);
	void damage();
	void draw();
	void unload();

private:
	Texture texture{};
	Vector2 position{};
	int endurance{};
	bool canDraw{ false };
};