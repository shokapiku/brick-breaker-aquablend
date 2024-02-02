#include "raylib.h"
#include "MenuState.h"
#include "GameState.h"

using namespace std;

MenuState::MenuState(int screenWidth, int screenHeight, StateManager& stateManager) 
	: m_screenWidth(screenWidth), m_screenHeight(screenHeight), m_stateManager(stateManager)
{
	m_signature = LoadTexture("assets/images/signature.png");
}

void MenuState::changeState()
{
	m_stateManager.setState(make_unique<GameState>(m_screenWidth, m_screenHeight, m_stateManager));
}

void MenuState::update(float deltaTime)
{
	if (IsKeyDown(KEY_SPACE))
	{
		changeState();
	}
}

void MenuState::draw()
{
	DrawText("Press Space", m_screenWidth / 2, m_screenHeight / 2, 50, GRAY);
	DrawText("to start", m_screenWidth / 2, m_screenHeight / 2 + 50, 50, GRAY);
	DrawTexture(m_signature, m_screenWidth - m_signature.width - 50 , m_screenHeight - m_signature.height - 10, WHITE);
}

void MenuState::unload()
{
	UnloadTexture(m_signature);
}