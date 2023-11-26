#ifndef GAMESTATE_H
#include "./BaseSceneState.hpp"

class BaseGameEntity;
class Asteroid;

class GameState : public BaseSceneState
{
public:
	GameState(BaseStateMachine* stateMachine);

	void OnEntry() override;
	void OnUpdate(sf::RenderWindow& window, sf::Time elapsed) override;
	void OnExit() override;

private:
	//BaseGameEntity* m_player;
	std::shared_ptr<Asteroid> m_astriod1;
};

#endif
