#include "Paddle.h"


Paddle::Paddle(int screenWidth, int screenHeight)
{
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;
	m_paddleTexture = LoadTexture("assets/images/paddle-test.png");
	m_brushTextureIdle = LoadTexture("assets/images/paint-brush-test.png");
	m_brushTexturePressed = LoadTexture("assets/images/paint-brush-2-test.png");

	m_position.x = m_screenWidth / 2 - m_paddleTexture.width / 2;
	m_position.y = m_screenHeight - 150;

	m_speed = 100;
	m_paddleCollider = { m_position.x, m_position.y, static_cast<float>(m_paddleTexture.width), static_cast<float>(m_paddleTexture.height) };

	m_brushPosition.x = m_screenWidth / 2 - m_brushTextureIdle.width / 2;
	m_brushPosition.y = m_screenHeight - 120;
}

void Paddle::update(float deltaTime)
{
	paddleMovement(deltaTime);
	brushMovement(deltaTime);
}

void Paddle::draw()
{
	DrawTexture(m_paddleTexture, m_position.x, m_position.y, WHITE);
	DrawTexture((m_canFollowMouse) ? m_brushTexturePressed : m_brushTextureIdle, m_brushPosition.x, m_brushPosition.y, WHITE);
	DrawRectangleLinesEx(m_paddleCollider, 5, RED);
}

void Paddle::unload()
{
	UnloadTexture(m_paddleTexture);
	UnloadTexture(m_brushTextureIdle);
	UnloadTexture(m_brushTexturePressed);
}

Vector2 Paddle::getPosition()
{
	return m_position;
}

int Paddle::getPaddleSize()
{
	return m_paddleTexture.width;
}

Rectangle Paddle::getCollider()
{
	return m_paddleCollider;
}

void Paddle::paddleMovement(float deltaTime)
{
	if (IsKeyDown(KEY_A))
	{
		m_position.x -= m_speed * deltaTime;
	}

	if (IsKeyDown(KEY_D))
	{
		m_position.x += m_speed * deltaTime;
	}

	//Testing Mouse Drag
	if (IsMouseButtonDown(0))
	{
		m_isMouseColliding = CheckCollisionPointRec(GetMousePosition(), m_paddleCollider);

		if (m_isMouseColliding)
		{
			m_canFollowMouse = true;
		}
	}
	else if (IsMouseButtonUp(0)) m_canFollowMouse = false;

	if (m_canFollowMouse)
	{
		m_position.x = GetMouseX() - m_paddleTexture.width / 2;
	}

	m_paddleCollider = { m_position.x, m_position.y, m_paddleCollider.width, m_paddleCollider.height };

}

void Paddle::brushMovement(float deltaTime)
{
	m_brushPosition.x = GetMouseX() - m_brushTextureIdle.width / 2;

	m_brushPosition.y = (m_canFollowMouse) ? m_screenHeight - 180 : m_screenHeight - 120;
}

