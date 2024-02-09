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

void Ball::followPaddle(Paddle paddle)
{
	if (m_canMove) return;

	m_position.x = paddle.getPosition().x + paddle.getPaddleSize() / 2 - m_ballSize.x / 2;
}

Vector2 Ball::getPosition()
{
	return m_position;
}

void Ball::setPosition(Vector2 position)
{
	m_position = position;
}

Vector2 Ball::getSpeed()
{
	return m_speed;
}

void Ball::setSpeed(Vector2 speed)
{
	m_speed = speed;
}

Rectangle Ball::getCollider()
{
	return m_ballCollider;
}
