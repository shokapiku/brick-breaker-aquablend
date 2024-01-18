#include "Level.h"

Level::Level(int screenWidth, int screenHeight)
{
	textureBlank = LoadTexture("assets/images/block-test.png");
	textureGreen = LoadTexture("assets/images/block-test-green.png");

	tileWidth = 30;
	tileHeight = 30;

	setLevelType1(screenWidth, screenHeight);
}

void Level::draw()
{
	for (int i = 0; i < levelSize; i++)
	{
		levelMap[i].draw();
	}
}

void Level::unload()
{
	for (int i = 0; i < levelSize; i++)
	{
		levelMap[i].unload();
	}
}

void Level::setLevelType1(int screenWidth, int screenHeight)
{
	int example[levelSize] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
		0, 0, 1, 2, 2, 1, 0, 0, 0, 1, 2, 2, 1, 0, 0,
		0, 0, 1, 2, 2, 1, 1, 1, 1, 1, 2, 2, 1, 0, 0,
		0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0,
		0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0,
		0, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 0,
		0, 1, 2, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 0,
		1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1,
		1, 2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 2, 2, 2, 1,
		1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	int x = 0;
	int y = 0;
	int count = 0;
	int countRow = 0;

	int width = screenWidth - 15 * tileWidth;

	for (int i = 0; i < levelSize; i++)
	{
		x = width / 2 + count * tileWidth;
		y = 50 + tileHeight * countRow;

		if (example[i] != 0)
		{
			Texture texture = (example[i] == 1) ? textureGreen : textureBlank;
			Block block(x, y, texture);

			levelMap[i] = block;
		}

		countRow = (count + 1 == 15) ? countRow + 1 : countRow;
		count = (count + 1 == 15) ? 0 : count + 1;
	}
}