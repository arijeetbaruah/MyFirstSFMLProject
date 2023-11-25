#include "../include/BaseSceneState.hpp"
#include "../include/SceneStateMachine.hpp"
#include "../include/GameState.hpp"

SceneStateMachine::SceneStateMachine() : BaseStateMachine()
{
	//m_currentState = new MainMenuState(window, this);
	m_currentState = new GameState(this);
	m_currentState->OnEntry();
	//m_currentState = mainMenuState;
}

void SceneStateMachine::Render(sf::RenderWindow& window)
{
	if (m_currentState != nullptr)
	{
		BaseSceneState* currentState = reinterpret_cast<BaseSceneState*>(m_currentState);
		currentState->Render(window);
	}
}
