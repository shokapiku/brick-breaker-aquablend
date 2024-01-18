#pragma once
#include "raylib.h"
#include "Block.h"

class Level
{
public:
	Level(int screenWidth, int screenHeight);
	void draw();
	void unload();
	void setLevelType1(int screenWidth, int screenHeight);

private:
	static const int levelWidth = 15;
	static const int levelHeight = 15;
	static const int levelSize = levelWidth * levelHeight;
	Block levelMap[levelSize];
	Texture textureBlank;
	Texture textureGreen;
	float tileWidth;
	float tileHeight;
};
