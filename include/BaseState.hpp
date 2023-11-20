#ifndef BASESTATE_H
#define BASESTATE_H

#include "SFML/Graphics.hpp"

class BaseStateMachine;

class BaseState
{
public:
	BaseState(BaseStateMachine* stateMachine)
	{
		m_stateMachine = stateMachine;
	}

	virtual void OnEntry() = 0;
	virtual void OnUpdate(sf::RenderWindow& window, sf::Time elapsed) = 0;
	virtual void OnExit() = 0;

protected:
	BaseStateMachine* m_stateMachine;
};

#endif // !BASESTATE_H
