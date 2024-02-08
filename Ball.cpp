#include "Ball.h"

Ball::Ball(int screenWidth, int screenHeight)
{
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	m_ballSize = { 15, 15 };

	m_position.x = m_screenWidth / 2 - m_ballSize.x / 2;
	m_position.y = m_screenHeight - 170;

	m_speed = { 100, -100 };

	m_ballCollider = { m_position.x, m_position.y, m_ballSize.x, m_ballSize.y };

	m_ballTexture = LoadTexture("assets/images/ball-test.png");
}

void Ball::update(float deltaTime)
{
	if (!m_canMove && IsKeyPressed(KEY_SPACE))
	{
		m_canMove = true;
	}

	if (!m_canMove) return;

	m_position.x += m_speed.x * deltaTime;
	m_position.y += m_speed.y * deltaTime;

	if (m_position.x + m_ballSize.x > m_levelLimits["xMax"] || m_position.x < m_levelLimits["xMin"])
	{
		m_speed.x *= -1;
		m_speed.y *= 1;
	}

	if (m_position.y < m_levelLimits["yMin"] || m_position.y + m_ballSize.y > m_levelLimits["yMax"])
	{
		m_speed.x *= 1;
		m_speed.y *= -1;
	}

}

void Ball::draw()
{
	DrawTexture(m_ballTexture, m_position.x, m_position.y, WHITE);
	DrawCircleLinesV({m_position.x + m_ballSize.x / 2, m_position.y + m_ballSize.y / 2}, 7.5, GREEN);

	if(!m_canMove) DrawText("Press Space", 10, 100, 30, GREEN);
	
}

void Ball::unload()
{
	UnloadTexture(m_ballTexture);
}

void Ball::setLimits(float minX, float maxX, float minY, float maxY)
{
	m_levelLimits.insert(std::make_pair( "xMin", minX ));
	m_levelLimits.insert(std::make_pair( "xMax", maxX));
	m_levelLimits.insert(std::make_pair( "yMin", minY));
	m_levelLimits.insert(std::make_pair( "yMax", maxY));
}

void Ball::followPaddle(Paddle paddle)
{
	if (m_canMove) return;

	m_position.x = paddle.getPosition().x + paddle.getPaddleSize() / 2 - m_ballSize.x / 2;
}
