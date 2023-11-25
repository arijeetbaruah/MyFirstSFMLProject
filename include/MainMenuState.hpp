#ifndef MAINMENUSTATE_H
#include "./BaseSceneState.hpp"

class Button;

class MainMenuState : public BaseSceneState
{
public:
	MainMenuState(BaseStateMachine* stateMachine);

	void OnEntry() override;
	void OnUpdate(sf::RenderWindow& window, sf::Time elapsed) override;
	void OnExit() override;
	void Render(sf::RenderWindow& window) override;

private:
	sf::Font font;
	sf::Text titleTxt;

	std::shared_ptr<Button> playBtn;
	std::shared_ptr<Button> exitBtn;
};

#endif
