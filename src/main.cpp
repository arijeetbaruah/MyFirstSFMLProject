#include <SFML/Graphics.hpp>
#include <iostream>

#include "Logger.hpp"
#include "./ResourceManager/ResourceManager.hpp"
#include "./ResourceManager/TextureManager.hpp"

const float playerSpeed = 3;

int main()
{
	Logger::GetInstance()->setLogLevel(LogLevel::DEBUG);

	auto window = sf::RenderWindow{ { 1920u, 1080u }, "Arijeet's SFML Project" };
	window.setFramerateLimit(144);
	ResourceManager* resourceManager = ResourceManager::GetInstance();
	resourceManager->Initialize();

	sf::Texture playerTex = resourceManager->textureManager->GetTexture("player.png");
	//playerTex.loadFromFile("../assets/player.png");
	playerTex.setSmooth(true);
	sf::Sprite player(playerTex);
	player.setScale(0.3f, 0.3f);

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				Logger::GetInstance()->log(LogLevel::INFO, "Handling event closed");
				exit(EXIT_SUCCESS);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				// left key is pressed: move our character
				sf::Vector2f movementDirection(-1.f, 0.f);
				player.move(movementDirection * playerSpeed);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				// left key is pressed: move our character
				sf::Vector2f movementDirection(1.f, 0.f);
				player.move(movementDirection * playerSpeed);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				// left key is pressed: move our character
				sf::Vector2f movementDirection(0.f, -1.f);
				player.move(movementDirection * playerSpeed);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				// left key is pressed: move our character
				sf::Vector2f movementDirection(0.f, 1.f);
				player.move(movementDirection * playerSpeed);
			}
		}

		window.clear();

		window.draw(player);

		window.display();
	}
}