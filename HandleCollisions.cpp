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

void HandleCollisions::checkPaddleCollision(Ball& ball, Paddle& paddle)
{
	Rectangle ballCol = ball.getCollider();
	Rectangle paddleCol = paddle.getCollider();
	Vector2 ballSpeed = ball.getSpeed();

	bool collision = CheckCollisionRecs(paddleCol, ballCol);

	if (collision)
	{
		Vector2 resultSpeed = calculateCollision(ballCol, paddleCol, ballSpeed);
		ball.setSpeed(resultSpeed);
	}
}

void HandleCollisions::checkBlocksCollision(Ball& ball, Level& level)
{
	std::array<Block, level.LEVEL_SIZE> blockGroup = level.getLevelMap();

	Rectangle ballCol = ball.getCollider();
	Vector2 ballSpeed = ball.getSpeed();
	int indexBlock{};
	bool collision = false;

	for (int i = 0; i < level.LEVEL_SIZE; i++)
	{
		if (blockGroup[i].getEndurance() == 0) continue;

		collision = CheckCollisionRecs(ballCol, blockGroup[i].getCollider());

		if (collision)
		{
			indexBlock = i;
			break;
		}
	}

	if (collision)
	{
		Rectangle blockCol = level.getBlock(indexBlock).getCollider();
		Vector2 resultSpeed = calculateCollision(ballCol, blockCol, ballSpeed);
		ball.setSpeed(resultSpeed);
		level.getBlock(indexBlock).damage();
	}
}

Vector2 HandleCollisions::calculateCollision(Rectangle& ballCollider, Rectangle& targetCollider, Vector2 ballSpeed)
{
	Vector2 ballCenter = { ballCollider.x + ballCollider.width / 2, ballCollider.y + ballCollider.height / 2 };
	Vector2 targetCenter = { targetCollider.x + targetCollider.width / 2, targetCollider.y + targetCollider.height / 2 };
	Vector2 resultSpeed = ballSpeed;

	float xDistance = ballCenter.x - targetCenter.x;
	float yDistance = ballCenter.y - targetCenter.y;

	bool isCollidingVertically = xDistance < ballCenter.x + targetCenter.x;
	bool isCollidingHorizontally = yDistance < ballCenter.y + targetCenter.y;

	if (isCollidingVertically)
	{
		if (ballCollider.x + ballCollider.width > targetCollider.x && ballCollider.x < targetCenter.x)
		{
			resultSpeed.x *= -1;
		}
		else if (ballCollider.x < targetCollider.x + targetCollider.width && ballCollider.x > targetCenter.x)
		{
			resultSpeed.x *= -1;
		}
	}

	if (isCollidingHorizontally)
	{
		if (ballCollider.y + ballCollider.height > targetCollider.y && ballCollider.y < targetCenter.y)
		{
			resultSpeed.y *= -1;
		}
		else if (ballCollider.y < targetCollider.y + targetCollider.height && ballCollider.y > targetCenter.y)
		{
			resultSpeed.y *= -1;
		}
	}

	return resultSpeed;
}


