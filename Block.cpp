#include "Block.h"

Block::Block()
{
}

Block::Block(float x, float y, Texture texture)
{
	this->position.x = x;
	this->position.y = y;
	this->texture = texture;

	canDraw = true;
}

void Block::update(float deltaTime)
{

}

void Block::damage()
{
	endurance -= 1;

	if (endurance <= 0) canDraw = false;
}

void Block::draw()
{
	if (canDraw) DrawTexture(texture, position.x, position.y, WHITE);
}

void Block::unload()
{
	UnloadTexture(texture);
}