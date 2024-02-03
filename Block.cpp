#include "Block.h"

Block::Block()
{
}

Block::Block(float x, float y, Texture texture, int endurance, Color fontColor)
{
	m_position.x = x;
	m_position.y = y;
	m_texture = texture;
	m_endurance = endurance;
	m_fontColor = fontColor;

	m_canDraw = true;
}

void Block::update(float deltaTime)
{

}

void Block::damage()
{
	m_endurance -= 1;

	if (m_endurance <= 0) m_canDraw = false;
}

void Block::draw()
{
	if (!m_canDraw) return;
	
	DrawTexture(m_texture, m_position.x, m_position.y, WHITE);
	DrawText(TextFormat("%d", m_endurance), m_position.x + m_texture.width / 3, m_position.y + m_texture.height / 4, 20, m_fontColor);

}

void Block::unload()
{
	UnloadTexture(m_texture);
}