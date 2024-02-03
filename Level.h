#pragma once
#include "raylib.h"
#include "Block.h"
#include <array>


class Level
{
public:
	Level(int screenWidth, int screenHeight);
	void draw();
	void unload();
	void setLevel(int screenWidth, int screenHeight);

private:
	static const int m_levelWidth = 15;
	static const int m_levelHeight = 15;
	static const int m_levelSize = m_levelWidth * m_levelHeight;
	Block m_levelMap[m_levelSize];
	std::array<Texture, 8> m_blockTexture = 
	{
		LoadTexture("assets/images/block-test.png"),
		LoadTexture("assets/images/block-test-black.png"),
		LoadTexture("assets/images/block-test-red.png"),
		LoadTexture("assets/images/block-test-green.png"),
		LoadTexture("assets/images/block-test-darkblue.png"),
		LoadTexture("assets/images/block-test-pink.png"),
		LoadTexture("assets/images/block-test-orange.png"),
		LoadTexture("assets/images/block-test-brown.png")
	};
	float m_tileWidth;
	float m_tileHeight;
	Texture m_levelBackground = LoadTexture("assets/images/level-background.png");
};
