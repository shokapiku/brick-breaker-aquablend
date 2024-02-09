#include "HandleCollisions.h"

HandleCollisions::HandleCollisions(int screenWidth, int screenHeight) 
{
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	float minX = m_screenWidth / 2 - 512 / 2;
	float maxX = minX + 512;
	float minY = m_screenHeight / 2 - 360;
	float maxY = minY + 660;

	m_levelBoundaries.insert(std::make_pair("xMin", minX));
	m_levelBoundaries.insert(std::make_pair("xMax", maxX));
	m_levelBoundaries.insert(std::make_pair("yMin", minY));
	m_levelBoundaries.insert(std::make_pair("yMax", maxY));
}

void HandleCollisions::checkBoundaryCollision(Ball& ball)
{
	Vector2 ballPos = ball.getPosition();
	Vector2 ballSpeed = ball.getSpeed();
	Rectangle ballCol = ball.getCollider();

	if (ballPos.x + ballCol.width > m_levelBoundaries["xMax"] || ballPos.x < m_levelBoundaries["xMin"])
	{
		ballSpeed.x *= -1;
		ball.setSpeed(ballSpeed);
	}

	if (ballPos.y < m_levelBoundaries["yMin"] || ballPos.y + ballCol.height > m_levelBoundaries["yMax"])
	{
		ballSpeed.y *= -1;
		ball.setSpeed(ballSpeed);
	}
}