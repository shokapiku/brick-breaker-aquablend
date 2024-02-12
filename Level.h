#pragma once
#include "raylib.h"
#include "Block.h"
#include <array>


class Level
{
public:
	Level(int screenWidth, int screenHeight);
	static const int LEVEL_SIZE = 225;
	void draw();
	void unload();
	std::array<Block, LEVEL_SIZE>& getLevelMap();
	Block& getBlock(int index);
private:
	std::array<Block, LEVEL_SIZE> m_levelMap{};
	std::array<Texture, 8> m_blockTexture 
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
	Texture m_levelBackground{};
	void setLevel(int screenWidth, int screenHeight);
};
