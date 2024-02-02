#pragma once

class State
{
	public:
		State();
		virtual void update(float deltaTime) = 0;
		virtual void draw() = 0;
		virtual void unload() = 0;
};
