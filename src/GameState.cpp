#include "../include/GameState.hpp"
#include "../include/Player.hpp"

GameState::GameState(std::shared_ptr<BaseStateMachine> stateMachine) : BaseSceneState(stateMachine)
{
	m_player = new Player();
}

void GameState::OnEntry()
{

}

void GameState::OnUpdate(sf::Time elapsed)
{
	m_player->Update(elapsed);
}

void GameState::OnExit()
{

}

void GameState::Render(sf::RenderWindow* window)
{
	m_player->Render(window);
}