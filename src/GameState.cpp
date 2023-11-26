#include "../include/GameState.hpp"
#include "../include/Player.hpp"
#include "../include/Asteroid.hpp"
#include "../include/EntityManager.hpp"

GameState::GameState(BaseStateMachine* stateMachine) : BaseSceneState(stateMachine)
{
	auto m_player = EntityManager::GetInstance()->CreateEntity("Player", "Player");
	m_astriod1 = std::reinterpret_pointer_cast<Asteroid>(EntityManager::GetInstance()->CreateEntity("Asteroid", "Asteroid1"));
}

void GameState::OnEntry()
{

}

void GameState::OnUpdate(sf::RenderWindow& window, sf::Time elapsed)
{
	if (m_astriod1 != nullptr)
	{
		auto transform = m_astriod1->GetTransform();
		transform->Move(glm::vec2(3, 4) * 100.f * elapsed.asSeconds());
	}
}

void GameState::OnExit()
{

}
