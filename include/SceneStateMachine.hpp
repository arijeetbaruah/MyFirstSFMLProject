#ifndef BASESTATEMACHINE_H
#include "./BaseStateMachine.hpp"
#include "./BaseGameEntity.hpp"
#include <SFML/Graphics.hpp>

class SceneStateMachine : public BaseStateMachine
{
public:
	SceneStateMachine();

	void Render(sf::RenderWindow* window);
};

#endif // !BASESTATEMACHINE_H
