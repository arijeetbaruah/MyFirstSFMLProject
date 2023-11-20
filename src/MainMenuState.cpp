#include "../include/MainMenuState.hpp"
#include "../include/Button.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Logger.hpp"
#include "../include/GameState.hpp"
#include "../include/BaseStateMachine.hpp"

MainMenuState::MainMenuState(BaseStateMachine* stateMachine) : BaseSceneState(stateMachine)
{
	ResourceManager* resourceManager = ResourceManager::GetInstance();

	if (resourceManager->LoadFont("Roboto-Black.ttf", font))
	{
		titleTxt.setFont(font);
		titleTxt.setStyle(sf::Text::Bold | sf::Text::Underlined);
		titleTxt.setString("Hello world");
		titleTxt.setCharacterSize(24);
		titleTxt.setFillColor(sf::Color::Red);
	}

	playBtn = new Button("Play", glm::vec2(1920u / 2, 1080u / 2 - 50), glm::vec2(100, 50), sf::Color::Blue, sf::Color::Red);
	exitBtn = new Button("Exit", glm::vec2(1920u / 2, 1080u / 2 - 50 + 100), glm::vec2(100, 50), sf::Color::Blue, sf::Color::Red);
}

void MainMenuState::OnEntry()
{

}

void MainMenuState::OnUpdate(sf::RenderWindow& window, sf::Time elapsed)
{
	playBtn->Update(window);
	exitBtn->Update(window);

	if (playBtn->isPressed())
	{
		GameState* nextState;

		m_stateMachine->SwitchState(new GameState(m_stateMachine));
	}

	if (exitBtn->isPressed())
	{
		exit(EXIT_SUCCESS);
	}
}

void MainMenuState::Render(sf::RenderWindow* window)
{
	window->draw(titleTxt);
	playBtn->Render(window);
	exitBtn->Render(window);
}

void MainMenuState::OnExit()
{

}
