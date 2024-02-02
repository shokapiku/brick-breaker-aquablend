#include "StateManager.h"

//using directive
using namespace std;

StateManager::StateManager()
{

}

void StateManager::setState(unique_ptr<State>&& newState)
{
	popState();
	pushState(move(newState));
}

void StateManager::pushState(unique_ptr<State> state)
{
	states.push(move(state));
}

void StateManager::popState()
{
	if (!states.empty())
	{
		unload();
		states.pop();
	}
}

void StateManager::update(float deltaTime)
{
	if (!states.empty())
	{
		states.top()->update(deltaTime);
	}
}

void StateManager::draw()
{
	if (!states.empty())
	{
		states.top()->draw();
	}
}

void StateManager::unload()
{
	if (!states.empty())
	{
		states.top()->unload();
	}
}