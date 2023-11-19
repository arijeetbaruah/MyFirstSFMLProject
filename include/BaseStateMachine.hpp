#ifndef BASESTATEMACHINE_H
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "./BaseState.hpp"

class BaseStateMachine
{
public:
	BaseStateMachine();
	void Update(sf::Time elapsed);
	void SwitchState(std::shared_ptr<BaseState> state);
protected:
	std::shared_ptr<BaseState> m_currentState;
};

#endif // !BASESTATEMACHINE_H
