#pragma once
#include "State.h"
#include "StateManager.h"

class MenuState : public State
{
	public:
		MenuState(int screenWidth, int screenHeight, StateManager& stateManager);
		void changeState();
		void update(float deltaTime);
		void draw();
		void unload();
	private:
		int m_screenWidth;
		int m_screenHeight;
		StateManager& m_stateManager;
		Texture m_signature;
};