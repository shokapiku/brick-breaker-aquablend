#pragma once
#include "State.h"
#include "StateManager.h"
#include "Level.h"
#include "Paddle.h"
#include "Ball.h"
#include <map>
#include <string>

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
		Paddle m_paddle;
		Ball m_ball;
		std::map<std::string, float> m_levelLimits{};
};