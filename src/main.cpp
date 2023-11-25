#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/Logger.hpp"
#include "../include/EntityManager.hpp"
#include "../include/SceneStateMachine.hpp"

const float playerSpeed = 3;

int main()
{
	Logger::GetInstance()->setLogLevel(LogLevel::DEBUG);

	auto window = sf::RenderWindow{ { 1920u, 1080u }, "Arijeet's SFML Project" };
	window.setFramerateLimit(144);

	EntityManager* em = EntityManager::GetInstance();

	SceneStateMachine* sceneStateMachine = new SceneStateMachine();

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float currentTimeInSec = elapsed.asSeconds();
		float fps = 1.0f / (currentTimeInSec);

		//Logger::GetInstance()->log(LogLevel::INFO, "FPS: " + std::to_string(fps));

		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				Logger::GetInstance()->log(LogLevel::INFO, "Handling event closed");
				exit(EXIT_SUCCESS);
			}
		}

		sceneStateMachine->Update(window, elapsed);
		em->Update(window, elapsed);

		window.clear();

		sceneStateMachine->Render(window);
		em->Render(window);

		window.display();
	}

	delete sceneStateMachine;
	sceneStateMachine = nullptr;
}