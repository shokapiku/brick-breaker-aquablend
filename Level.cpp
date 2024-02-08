#include "Level.h"
#include <random>

//using directive
using namespace std;

//Forward declaration
array<int, 225> createType1();
array<int, 225> createType2();
array<int, 225> createType3();

Level::Level(int screenWidth, int screenHeight)
{
	m_tileWidth = 30;
	m_tileHeight = 30;

	setLevel(screenWidth, screenHeight);

	m_levelBackground = LoadTexture("assets/images/level-background.png");
	
}

void Level::draw()
{
	DrawTexture(m_levelBackground, 0, 0, WHITE);
	
	for (int i = 0; i < m_levelSize; i++)
	{
		m_levelMap[i].draw();
	}

	DrawRectangleLinesEx({1240/2 - 512/2, 800/2 - 360, 512, 660}, 5, RED);
}

void Level::unload()
{
	UnloadTexture(m_levelBackground);

	for (int i = 0; i < m_levelSize; i++)
	{
		m_levelMap[i].unload();
	}
}

void Level::setLevel(int screenWidth, int screenHeight)
{
	random_device random;
	uniform_int_distribution<int> dist(0, 2);

	int type = dist(random);

	array<int, m_levelSize> example;

	switch (type)
	{
		case 0:
			example = createType1();
			break;
		case 1:
			example = createType2();
			break;
		case 2:
			example = createType3();
			break;
		default:
			example = createType1();
			break;
	}


	int x = 0;
	int y = 0;
	int count = 0;
	int countRow = 0;

	int width = screenWidth - 15 * m_tileWidth;

	for (int i = 0; i < m_levelSize; i++)
	{
		x = width / 2 + count * m_tileWidth;
		y = 50 + m_tileHeight * countRow;

		if (example[i] != 0)
		{
			Texture texture = m_blockTexture[example[i] - 1];
			Color fontColor = (example[i] == 2) ? WHITE : BLACK;
			Block block(x, y, texture, example[i], fontColor);

			m_levelMap[i] = block;
		}

		countRow = (count + 1 == 15) ? countRow + 1 : countRow;
		count = (count + 1 == 15) ? 0 : count + 1;
	}
}

//1-white, 2-black, 3-red, 4-green, 5-blue
//6-pink, 7-orange, 8-brown

array<int, 225> createType1()
{
	return { 
		{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0,
			0, 0, 2, 1, 8, 2, 0, 0, 0, 2, 1, 8, 2, 0, 0,
			0, 0, 2, 1, 8, 2, 2, 2, 2, 2, 1, 8, 2, 0, 0,
			0, 2, 1, 8, 8, 7, 7, 7, 1, 1, 8, 7, 7, 2, 0,
			0, 2, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2, 0,
			0, 2, 7, 7, 7, 2, 7, 7, 7, 2, 7, 7, 7, 2, 0,
			0, 2, 7, 2, 2, 2, 7, 7, 7, 2, 2, 2, 7, 2, 0,
			2, 1, 7, 7, 7, 7, 2, 7, 2, 7, 7, 7, 7, 8, 2,
			2, 1, 7, 7, 7, 2, 7, 2, 7, 2, 7, 7, 8, 8, 2,
			2, 1, 1, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 2,
			2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		} 
	};
}

array<int, 225> createType2()
{
	return {
		{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
			1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
			1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
			1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
			1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
			1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
			1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
			1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
			1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		}
	};
}

array<int, 225> createType3()
{
	return {
		{
			0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
			0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
			0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0,
			0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
			0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
			1, 0, 0, 0, 1, 2, 0, 0, 0, 1, 2, 0, 0, 0, 1,
			1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1,
			1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 1, 2, 2, 2, 1, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 1,
			0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
			0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
			0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0
		}
	};
}