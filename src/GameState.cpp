#include "../include/GameState.hpp"
#include "../include/Player.hpp"
#include "../include/EntityManager.hpp"

GameState::GameState(BaseStateMachine* stateMachine) : BaseSceneState(stateMachine)
{
	auto m_player = EntityManager::GetInstance()->CreateEntity("Player", "Player");
	auto m_astriod1 = EntityManager::GetInstance()->CreateEntity("Asteroid", "Asteroid1");
}

void GameState::OnEntry()
{

}

void GameState::OnUpdate(sf::RenderWindow& window, sf::Time elapsed)
{

}

void GameState::OnExit()
{

}
