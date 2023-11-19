#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/Logger.hpp"
#include "../include/SceneStateMachine.hpp"

const float playerSpeed = 3;

int main()
{
	Logger::GetInstance()->setLogLevel(LogLevel::DEBUG);

	auto window = sf::RenderWindow{ { 1920u, 1080u }, "Arijeet's SFML Project" };
	window.setFramerateLimit(144);

	/*ResourceManager* resourceManager = ResourceManager::GetInstance();

	sf::Font font = resourceManager->LoadFont("Roboto-Black.ttf");

	sf::Text text;
	text.setFont(font);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setString("Hello world");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);*/

	std::shared_ptr<SceneStateMachine> sceneStateMachine = std::shared_ptr<SceneStateMachine>(new SceneStateMachine());

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

		sceneStateMachine->Update(elapsed);

		window.clear();

		//window.draw(text);
		sceneStateMachine->Render(&window);

		window.display();
	}
}