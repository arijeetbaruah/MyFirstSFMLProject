#ifndef BASESCENESTATE_H
#define BASESCENESTATE_H

#include "./BaseState.hpp"

class BaseSceneState : public BaseState
{
public:
	BaseSceneState(BaseStateMachine* stateMachine) : BaseState(stateMachine) {}
	virtual void Render(sf::RenderWindow* window) = 0;
};

#endif // !BASESCENESTATE_H
