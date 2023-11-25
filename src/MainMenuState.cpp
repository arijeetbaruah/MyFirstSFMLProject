#include "../include/MainMenuState.hpp"
#include "../include/Button.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Logger.hpp"
#include "../include/GameState.hpp"
#include "../include/EntityManager.hpp"
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

	EntityManager* em = EntityManager::GetInstance();
	playBtn = std::make_shared<Button>("playBtn", "Play", sf::Vector2f(0, 50), sf::Vector2f(100, 50), sf::Color::Blue, sf::Color::Red);
	em->AddEntity(playBtn);
	exitBtn = std::make_shared<Button>("exitBtn", "Exit", sf::Vector2f(0, 50 + 100), sf::Vector2f(100, 50), sf::Color::Blue, sf::Color::Red);
	em->AddEntity(exitBtn);
}

void MainMenuState::OnEntry()
{

}

void MainMenuState::OnUpdate(sf::RenderWindow& window, sf::Time elapsed)
{
	if (playBtn->isPressed())
	{
		GameState* nextState;

		m_stateMachine->SwitchState(new GameState(m_stateMachine));
		return;
	}

	if (exitBtn->isPressed())
	{
		exit(EXIT_SUCCESS);
	}
}

void MainMenuState::Render(sf::RenderWindow& window)
{
	window.draw(titleTxt);
}

void MainMenuState::OnExit()
{

}
