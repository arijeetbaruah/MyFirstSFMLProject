#include "../include/MainMenuState.hpp"
#include "../include/ResourceManager.hpp"

MainMenuState::MainMenuState(std::shared_ptr<BaseStateMachine> stateMachine) : BaseSceneState(stateMachine)
{
	ResourceManager* resourceManager = ResourceManager::GetInstance();

	sf::Font font = resourceManager->LoadFont("Roboto-Black.ttf");

	titleTxt.setFont(font);
	titleTxt.setStyle(sf::Text::Bold | sf::Text::Underlined);
	titleTxt.setString("Hello world");
	titleTxt.setCharacterSize(24);
	titleTxt.setFillColor(sf::Color::Red);
}

void MainMenuState::OnEntry()
{

}

void MainMenuState::OnUpdate(sf::Time elapsed)
{

}

void MainMenuState::Render(sf::RenderWindow* window)
{
	window->draw(titleTxt);
}

void MainMenuState::OnExit()
{

}
