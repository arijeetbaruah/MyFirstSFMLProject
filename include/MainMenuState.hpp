#ifndef MAINMENUSTATE_H
#include "./BaseSceneState.hpp"

class MainMenuState : BaseSceneState
{
public:
	MainMenuState(std::shared_ptr<BaseStateMachine> stateMachine);

	void OnEntry() override;
	void OnUpdate(sf::Time elapsed) override;
	void OnExit() override;
	void Render(sf::RenderWindow* window) override;

private:
	sf::Text titleTxt;
};

#endif
