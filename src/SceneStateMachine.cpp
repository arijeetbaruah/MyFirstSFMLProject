#include "../include/BaseSceneState.hpp"
#include "../include/SceneStateMachine.hpp"
#include "../include/MainMenuState.hpp"

SceneStateMachine::SceneStateMachine() : BaseStateMachine()
{
	std::shared_ptr<BaseStateMachine> stateMachine = std::dynamic_pointer_cast<BaseStateMachine>(std::shared_ptr<SceneStateMachine>(this));
	std::shared_ptr<MainMenuState> mainMenuState = std::shared_ptr<MainMenuState>(new MainMenuState(stateMachine));
	
	std::shared_ptr<BaseSceneState> currentState = std::dynamic_pointer_cast<BaseSceneState>(mainMenuState);
	
	mainMenuState->OnEntry();
}

void SceneStateMachine::Render(sf::RenderWindow* window)
{
	if (m_currentState != nullptr)
	{
		std::shared_ptr<BaseSceneState> currentState = std::dynamic_pointer_cast<BaseSceneState>(m_currentState);
		currentState->Render(window);
	}
}
