#include "GameRestart.h"

int GameRestart::Run(sf::RenderWindow& App) {

	bool Running = true;

	if (!font.loadFromFile("Resources/Fonts/Dosis-Light.ttf")) {

		cout << "ERROR::GameEngine::initFonts::Resources/Fonts/Dosis-Light.ttf!";
	}

	Retry.setFont(font);
	Retry.setCharacterSize(150);
	Retry.setFillColor(sf::Color::White);
	Retry.setString("Restart");
	sf::FloatRect textRect = Retry.getLocalBounds();
	Retry.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	Retry.setPosition(sf::Vector2f(App.getSize().x / 2.0f, App.getSize().y / 2.0f - 200.f));

	ReturnToMenu.setFont(font);
	ReturnToMenu.setCharacterSize(150);
	ReturnToMenu.setFillColor(sf::Color::White);
	ReturnToMenu.setString("Menu");
	sf::FloatRect textRect1 = ReturnToMenu.getLocalBounds();
	ReturnToMenu.setOrigin(textRect1.left + textRect1.width / 2.0f,
		textRect1.top + textRect1.height / 2.0f);
	ReturnToMenu.setPosition(sf::Vector2f(App.getSize().x / 2.0f, App.getSize().y / 2.0f));

	Exit.setFont(font);
	Exit.setCharacterSize(150);
	Exit.setFillColor(sf::Color::White);
	Exit.setString("Exit");
	sf::FloatRect textRect2 = Exit.getLocalBounds();
	Exit.setOrigin(textRect2.left + textRect2.width / 2.0f,
		textRect2.top + textRect2.height / 2.0f);
	Exit.setPosition(sf::Vector2f(App.getSize().x / 2.0f, App.getSize().y / 2.0f + 200.f));



	while (Running) {

		while (App.pollEvent(event)) {

			auto mousePosWindow = Mouse::getPosition(App);
			auto mousePosView = App.mapPixelToCoords(mousePosWindow);

			if (event.type == sf::Event::Closed) {

				return (-1);
			}

			if (Retry.getGlobalBounds().contains(mousePosView)) {

				Retry.setFillColor(Color::Blue);
				ReturnToMenu.setFillColor(Color::White);
				Exit.setFillColor(Color::White);
			}
			else if (ReturnToMenu.getGlobalBounds().contains(mousePosView)) {

				Retry.setFillColor(Color::White);
				ReturnToMenu.setFillColor(Color::Blue);
				Exit.setFillColor(Color::White);
			}
			else if (Exit.getGlobalBounds().contains(mousePosView)) {

				Retry.setFillColor(Color::White);
				ReturnToMenu.setFillColor(Color::White);
				Exit.setFillColor(Color::Blue);
			}
			else {

				Retry.setFillColor(Color::White);
				ReturnToMenu.setFillColor(Color::White);
				Exit.setFillColor(Color::White);
			}

			if (Mouse::isButtonPressed(Mouse::Left)) {

				if (mouseHeld == false) {

					mouseHeld = true;

					if (Retry.getGlobalBounds().contains(mousePosView)) {

						return(1);
					}

					else if (ReturnToMenu.getGlobalBounds().contains(mousePosView)) {

						return(0);
					}

					else if (Exit.getGlobalBounds().contains(mousePosView)) {

						Running = false;
					}
				}
			}
			else
				mouseHeld = false;
		}

		App.clear();

		App.draw(Retry);
		App.draw(ReturnToMenu);
		App.draw(Exit);

		App.display();
	}

	return (-1);
}