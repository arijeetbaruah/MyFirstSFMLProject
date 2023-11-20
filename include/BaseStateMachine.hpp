#ifndef BASESTATEMACHINE_H
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "./BaseState.hpp"

class BaseStateMachine
{
public:
	BaseStateMachine();
	~BaseStateMachine();
	void Update(sf::RenderWindow& window, sf::Time elapsed);
	void SwitchState(BaseState* state);
protected:
	BaseState* m_currentState;
};

#endif // !BASESTATEMACHINE_H
