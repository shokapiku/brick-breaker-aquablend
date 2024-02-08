#include "raylib.h"
#include "GameState.h"
#include "MenuState.h"
#include "Level.h"

using namespace std;

GameState::GameState(int screenWidth, int screenHeight, StateManager& stateManager)
	: m_screenWidth(screenWidth), m_screenHeight(screenHeight), m_stateManager(stateManager), 
	  m_level(screenWidth, screenHeight), m_paddle(screenWidth, screenHeight), m_ball(screenWidth, screenHeight)
{
	float minX = screenWidth / 2 - 512 / 2;
	float maxX = minX + 512;
	float minY = screenHeight / 2 - 360;
	float maxY = minY + 660;

	m_levelLimits.insert(std::make_pair("xMin", minX));
	m_levelLimits.insert(std::make_pair("xMax", maxX));
	m_levelLimits.insert(std::make_pair("yMin", minY));
	m_levelLimits.insert(std::make_pair("yMax", maxY));

	m_ball.setLimits(minX, maxX, minY, maxY);
}

void GameState::changeState()
{
	//Testing go back to Menu
	m_stateManager.setState(make_unique<MenuState>(m_screenWidth, m_screenHeight, m_stateManager));
}

void GameState::update(float deltaTime)
{
	if (IsKeyDown(KEY_BACKSPACE))
	{
		changeState();
	}

	m_paddle.update(deltaTime);
	m_ball.update(deltaTime);
	m_ball.followPaddle(m_paddle);
}

void GameState::draw()
{
	m_level.draw();
	m_paddle.draw();
	m_ball.draw();

}

void GameState::unload()
{
	m_level.unload();
	m_paddle.unload();
	m_ball.unload();
}