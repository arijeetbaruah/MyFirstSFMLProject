#ifndef GAMESTATE_H
#include "./BaseSceneState.hpp"

class BaseGameEntity;

class GameState : public BaseSceneState
{
public:
	GameState(std::shared_ptr<BaseStateMachine> stateMachine);

	void OnEntry() override;
	void OnUpdate(sf::Time elapsed) override;
	void OnExit() override;
	void Render(sf::RenderWindow* window) override;

private:
	BaseGameEntity* m_player;
};

#endif
