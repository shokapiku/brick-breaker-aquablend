#pragma once
#include "State.h"
#include <stack>
#include <memory>

class StateManager
{
	public:
		StateManager();
		void setState(std::unique_ptr<State>&& newState);
		void pushState(std::unique_ptr<State> state);
		void popState();
		void update(float deltaTime);
		void draw();
		void unload();

	private:
		std::stack<std::unique_ptr<State>> states{};
};

