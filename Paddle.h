#pragma once
#include <raylib.h>

class Paddle
{
	public:
		Paddle(int screenWidth, int screenHeight);
		void update(float deltaTime);
		void paddleMovement(float deltaTime);
		void brushMovement(float deltaTime);
		void draw();
		void unload();
		Vector2 getPosition();
		int getPaddleSize();
		Rectangle getCollider();
	private:
		int m_screenWidth{};
		int m_screenHeight{};
		Texture m_paddleTexture{};
		Vector2 m_position{};
		float m_speed{};
		Rectangle m_paddleCollider{};
		Rectangle m_mouseCollider{};
		bool m_isMouseColliding{ false };
		bool m_canFollowMouse{ false };
		Vector2 m_brushPosition{};
		Texture m_brushTextureIdle{};
		Texture m_brushTexturePressed{};
};