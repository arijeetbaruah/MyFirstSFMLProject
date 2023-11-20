#include "../include/BaseSceneState.hpp"
#include "../include/SceneStateMachine.hpp"
#include "../include/MainMenuState.hpp"

SceneStateMachine::SceneStateMachine() : BaseStateMachine()
{
	m_currentState = new MainMenuState(this);
	m_currentState->OnEntry();
	//m_currentState = mainMenuState;
}

void SceneStateMachine::Render(sf::RenderWindow* window)
{
	if (m_currentState != nullptr)
	{
		BaseSceneState* currentState = dynamic_cast<BaseSceneState*>(m_currentState);
		currentState->Render(window);
	}
}
