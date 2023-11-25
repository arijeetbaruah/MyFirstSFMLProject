#ifndef GAMESTATE_H
#include "./BaseSceneState.hpp"

class BaseGameEntity;

class GameState : public BaseSceneState
{
public:
	GameState(BaseStateMachine* stateMachine);

	void OnEntry() override;
	void OnUpdate(sf::RenderWindow& window, sf::Time elapsed) override;
	void OnExit() override;

private:
	//BaseGameEntity* m_player;
};

#endif
