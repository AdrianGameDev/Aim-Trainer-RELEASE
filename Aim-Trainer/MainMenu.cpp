#include "MainMenu.h"

int MainMenu::Run(sf::RenderWindow& App) {

	bool Running = true;

	if (!font.loadFromFile("Resources/Fonts/Dosis-Light.ttf")) {

		cout << "ERROR::GameEngine::initFonts::Resources/Fonts/Dosis-Light.ttf!";
	}

	Play.setFont(font);
	Play.setCharacterSize(200);
	Play.setFillColor(sf::Color::White);
	Play.setString("Play");
	sf::FloatRect textRect = Play.getLocalBounds();
	Play.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	Play.setPosition(sf::Vector2f(App.getSize().x / 2.0f, App.getSize().y / 2.0f - 200));

	Exit.setFont(font);
	Exit.setCharacterSize(200);
	Exit.setFillColor(sf::Color::White);
	Exit.setString("Exit");
	sf::FloatRect textRect2 = Exit.getLocalBounds();
	Exit.setOrigin(textRect2.left + textRect2.width / 2.0f,
		textRect2.top + textRect2.height / 2.0f);
	Exit.setPosition(sf::Vector2f(App.getSize().x / 2.0f, App.getSize().y / 2.0f + 200));


	while (Running) {

		while (App.pollEvent(event)) {

			auto mousePosWindow = Mouse::getPosition(App);
			auto mousePosView = App.mapPixelToCoords(mousePosWindow);

			if (event.type == sf::Event::Closed) {
				return (-1);
			}

			if (Play.getGlobalBounds().contains(mousePosView)) {

				Play.setFillColor(Color::Blue);
				Options.setFillColor(Color::White);
				Exit.setFillColor(Color::White);
			}

			else if (Options.getGlobalBounds().contains(mousePosView)) {

				Play.setFillColor(Color::White);
				Options.setFillColor(Color::Blue);
				Exit.setFillColor(Color::White);
			}

			else if (Exit.getGlobalBounds().contains(mousePosView)) {

				Play.setFillColor(Color::White);
				Options.setFillColor(Color::White);
				Exit.setFillColor(Color::Blue);
			}

			else {

				Play.setFillColor(Color::White);
				Options.setFillColor(Color::White);
				Exit.setFillColor(Color::White);
			}


			if (Mouse::isButtonPressed(Mouse::Left)) {

				if (mouseHeld == false) {

					mouseHeld = true;

					if (Play.getGlobalBounds().contains(mousePosView)) {

						return (1);
					}

					else if (Options.getGlobalBounds().contains(mousePosView)) {

						return(3);
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

		App.draw(Play);
		App.draw(Options);
		App.draw(Exit);

		App.display();
	}

	return (-1);
}