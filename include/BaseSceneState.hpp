#ifndef BASESCENESTATE_H
#define BASESCENESTATE_H

#include "./BaseState.hpp"

class BaseSceneState : BaseState
{
public:
	BaseSceneState(std::shared_ptr<BaseStateMachine> stateMachine) : BaseState(stateMachine) {}
	virtual void Render(sf::RenderWindow* window) = 0;
};

#endif // !BASESCENESTATE_H
