#include "raylib.h"
#include "GameState.h"
#include "MenuState.h"
#include "Level.h"

using namespace std;

GameState::GameState(int screenWidth, int screenHeight, StateManager& stateManager)
	: m_screenWidth(screenWidth), m_screenHeight(screenHeight), m_stateManager(stateManager), m_level(screenWidth, screenHeight)
{
	
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
}

void GameState::draw()
{
	m_level.draw();
}

void GameState::unload()
{
	m_level.unload();
}