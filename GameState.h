#pragma once
#include "State.h"
#include "StateManager.h"
#include "Level.h"

class GameState : public State
{
	public:
		GameState(int screenWidth, int screenHeight, StateManager& stateManager);
		void changeState();
		void update(float deltaTime);
		void draw();
		void unload();
	private:
		int m_screenWidth;
		int m_screenHeight;
		StateManager& m_stateManager;
		Level m_level;
};